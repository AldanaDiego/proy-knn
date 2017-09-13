#include <bits/stdc++.h>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 4)
        cout << "Modo de uso: CreateDatasets <file.csv> <num_rows> <num_subsets>";
    
    ifstream file;
    int size = atoi(argv[2]);
    int subsets = atoi(argv[3]);

    //Shuffle! Para tirar aleatoriamente cada fila a un archivo distinto
    int shuffle[size];
    for(int i=0; i<size; i++)
    {
        shuffle[i] = i%subsets;
        
    }
    srand(time(NULL));
    for(int i=0; i<size; i++)
    {
        int j = rand()%size;
        int aux = shuffle[i];
        shuffle[i] = shuffle[j];
        shuffle[j] = aux;
    }

    int i = 0;
    file.open(argv[1]);
    string in;
    ostringstream output[subsets];
    while(file >> in)
    {
        output[shuffle[i]] << in << endl;
        i++;
    }
    file.close();

    ofstream outfile;
    ostringstream oss;
    for(i=0; i<subsets; i++)
    {
        oss << "Subset" << i << ".csv";
        outfile.open(oss.str());
        outfile << output[i].str();
        outfile.close();
        oss.str("");
        oss.clear();
    }
    return 0;
}