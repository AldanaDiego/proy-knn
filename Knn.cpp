#include <bits/stdc++.h>
#include <fstream>
#include <math.h>
#include "Knn.h"

using namespace std;

//Implementacion de KNN
//queryInstance: vector con la informacion de consulta (sin categoria)
//trainingSet: vector de strings con las instancias de entrenamiento, deben venir
//				en formato CSV, y con el valor de clase al final
//k: numero de vecinos a revisar
string Knn::run(vector<double> queryInstance, vector<string> trainingSet, int k)
{
	int dimension = queryInstance.size();
	ifstream file;
	priority_queue<pair<double,string >> q;
	string in;

	for(auto it = trainingSet.begin(); it < trainingSet.end(); it++)
	{
		//Parsear CSV
		stringstream st(*it);
		vector<string> input;
		string aux;
		while(getline(st, aux, ','))
			input.push_back(aux);

		//Calcular distancia euclidiana
		double distance = 0;
		for(int i=0; i<dimension; i++)
		{
			distance += pow(queryInstance[i]-stod(input[i]),2.0);
		}
		distance =sqrt(distance)*-1; //-1 para que ordene de menor a mayor
		
		//Asumimos que la ultima columna en el CSV es la categoria...
		q.push(make_pair(distance,input[input.size()-1]));
	}
	file.close();

	//Escoger las k categorias vecinas
	map<string,int> m;
	for(int i=0; i<k; i++)
	{
		string category = q.top().second;
		if(m.count(category) == 0)
			m[category] = 1;
		else
			m[category]++;
		q.pop();
	}

	//Retornar la categoria con mas "votos"
	int maxVotes = 0;
	string category;
	for(map<string,int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		if(it->second > maxVotes)
		{
			category = it->first;
			maxVotes = it->second;
		}
	}
	return category;
}