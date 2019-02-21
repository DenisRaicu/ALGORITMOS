// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

// función que resuelve el problema
void resolver(tMatriz const& matriz, int k, int sumAct, 
	int & sumMin, int numFunc, std::vector<int> & marcar) {

	//Con el for recorroemos las columnas:
	for (int i = 0; i < numFunc; ++i) {
		sumAct += matriz[k][i]; //sumo una tarea de un funcionario nuevo;
		marcar[i] += 1; //marcamos la columna usada;

		if (marcar[i] <= 1) { //¿es valida?
			if (k == numFunc - 1) { //¿hemos recorrido todas las filas?
				if (sumAct < sumMin)  //¿es solucion?
					sumMin = sumAct; //actualizo la suma minima;
			} 
			
			//seguimos con la siguiente etapa (fila):
			else resolver(matriz, k+1, sumAct, sumMin, numFunc, marcar);
		}

		sumAct -= matriz[k][i]; //resto lo sumado (cuando no es valido, o no es solucion);
		marcar[i] -= 1; //desmarco la columna usada;
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

	for (int i = 0; i < numFunc; i++) {
		for (int j = 0; j < numFunc; j++) {
			std::cin >> matriz[i][j];

			//Sumar la primera solución valida (la diagonal): 
			if (i == j) sumMin += matriz[i][j];
		}
	}

	//Creamos un vector para marcar la columna usada:
	std::vector<int> marcar (numFunc, 0);

	resolver(matriz, k, sumAct, sumMin, numFunc, marcar);

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