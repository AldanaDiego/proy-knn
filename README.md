Machine Learning - KNN
------------------------
	Este proyecto consiste en una implementación del algoritmo KNN en C++.

Knn.h Knn.cpp
---------------
	Corresponden a los archivos donde se encuentra la implementación del algoritmo. Estas proveen 
	la funcionalidad de Knn para ser usada como función.
		->En un archivo .cpp se incluye como: #include <"Knn.h">
		->Se declara un objeto de la clase Knn, ej: Knn solver;
		->Luego se puede llamar el algoritmo como: solver.run(query,dataset,k);
		->Donde:
			*query: Es un vector<double> que contiene los datos de la instancia de consulta
			*dataset: Es un vector<string>, donde cada string es una instancia de entrenemiento, en 
			formato CSV. Para el correcto funcionamiento del algoritmo, la clase o categoría debe ser 
			el último valor en el CSV, ej: 5,3.6,1.4,0.2,setosa
			*k: Es el parámetro k del algoritmo, que indica la cantidad de vecinos a visitar
  
Main.cpp
---------
	Método principal que hace uso del algoritmo KNN. Realiza 10-fold cross-validation e imprime 
	la certeza promedio obtenida para cada k entre 1 y 10. Para ello hace uso de los archivos 
	Subset.csv provistos.
	->Compilación: g++ Knn.cpp Main.cpp -o Main
	->Ejecución: .\Main <subsets>
	->Donde
		*subsets: Es el número de subsets disponibles. En este caso son 10.
  
CreateDatasets.cpp
--------------------
	Método adicional usado para separar el dataset Iris original en particiones aleatorias. 
	Puede usarse para reemplazar los archivos Subset.csv existentes y probar el algoritmo 
	nuevamente.
	->Compilación: g++ CreateDatasets.cpp -o Data
	->Ejecución: .\Data file.csv <rows> <subsets>
	->Donde:
		*file.csv: Es el archivo .csv con los datos originales. En este caso es IRIS.csv
		*rows: Es el número de instancias que tiene el set .csv. Para el caso de Iris es 150
		*subsets: Es el número de particiones o subsets a crear. En este caso se usaron 10.
