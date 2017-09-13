#include <bits/stdc++.h>
#include <sstream>
#include <fstream>
#include "Knn.h"
#define maxK 10

using namespace std;

int main(int argc, char* argv[])
{
    Knn solver;
    if(argc != 2)
    {
        cout << "Modo de uso: " << argv[0] << " <num_subsets>";
    }
    int numSubsets = atoi(argv[1]);
    vector<string> subsets[numSubsets];
    ifstream file;
    ostringstream oss;
    
    //Leer los subsets de datos
    for(int i=0; i<numSubsets; i++)
    {
        oss << "Subset" << i << ".csv";
        file.open(oss.str());
        string in;
        while(file >> in)
        {
            subsets[i].push_back(in);
        }
        file.close();
        oss.str("");
        oss.clear();
    }

    //Matriz de resultados!
    double results[numSubsets][maxK];
    for(int i=0; i<numSubsets; i++)
        for(int j=0; j<maxK; j++)
            results[i][j] = 0;

    //Para cada iteracion, i sera el subset de prueba y el resto sera de entrenamiento
    for(int i=0; i<numSubsets; i++)
    {
        vector<string> trainingSet;
        for(int j=0; j<numSubsets; j++)
        {
            if(i==j)
                continue;
            trainingSet.insert(trainingSet.end(),subsets[j].begin(),subsets[j].end()); //Concatenar subsets para crear el set de entrenamiento
        }
        for(auto it = subsets[i].begin(); it < subsets[i].end(); it++)
        {
            //Parsear CSV del set de prueba, extraer datos y clase
            stringstream st(*it);
            vector<double> queryData;
            string species;
			string aux;
			while(getline(st, aux, ','))
            {
                if(isdigit(aux[0]))
                {
                    queryData.push_back(stod(aux));
                }
                else
                {
                    species = aux;
                }
            }

            //Probar para todos los k!!!
            for(int k=1; k<=maxK; k++)
            {
                string answer = solver.run(queryData,trainingSet,k);
                if(answer == species)
                    results[i][k-1]++; //Un acierto probando con el subset i, para un cierto k
            }
        }
    }

    //Promediar resultados
    for(int k=0; k<maxK; k++)
    {
        double prom = 0;
        for(int i=0; i<numSubsets; i++)
        {
            results[i][k]/=subsets[i].size(); //Porcentaje de acierto
            prom += results[i][k];
        }
        prom/=numSubsets;
        cout << (k+1) << " " << prom << endl;
    }
    return 0;   
}