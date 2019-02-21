// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

// función que resuelve el problema
void resolver(tMatriz const& matriz, int k, int sumAct,
	int & sumMin, int numFunc, std::vector<bool> & marcar, 
	std::vector<int> const& acumulados) {

	//Con el for recorroemos las columnas:
	for (int i = 0; i < numFunc; ++i) {
		sumAct += matriz[k][i]; //sumo una tarea de un funcionario nuevo;
	
		if (!marcar[i]) { //¿es valida?
			if (k == numFunc - 1) { //¿hemos recorrido todas las filas?
				if (sumAct < sumMin)  //¿es solucion?
					sumMin = sumAct; //actualizo la suma minima;
			}

			//seguimos con la siguiente etapa (fila):
			else {
				
				//Estimacion con vector de acumulados:
				if (sumMin > (sumAct + (acumulados[numFunc - 1] - acumulados[k]))) { 
					marcar[i] = true; //marco la columna usada;
					resolver(matriz, k + 1, sumAct, sumMin, numFunc, marcar, acumulados);
					marcar[i] = false; //desmarco la columna usada;
				}
				
			}
		}
		
		sumAct -= matriz[k][i]; //resto lo sumado (cuando no es valido, o no es solucion);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numFunc, k = 0, sumAct = 0, sumMin = 0;
	std::cin >> numFunc;

	if (numFunc == 0) return false;
	tMatriz matriz(numFunc, std::vector<int>(numFunc));
	std::vector<int> acumulados(numFunc); //Vector de acumulados;
	int min = 0, anterior = 0;

	for (int i = 0; i < numFunc; i++) {
		std::cin >> matriz[i][0];
		min = matriz[i][0];
		for (int j = 1; j < numFunc; j++) {
			std::cin >> matriz[i][j];
			if (min > matriz[i][j]) min = matriz[i][j];
		}
		acumulados[i] = min + anterior;
		anterior = acumulados[i];
		sumMin += matriz[i][i];
	}

	//Creamos un vector para marcar la columna usada:
	std::vector<bool> marcar(numFunc);

	resolver(matriz, k, sumAct, sumMin, numFunc, marcar, acumulados);

	//escribir sol
	std::cout << sumMin << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt:
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}