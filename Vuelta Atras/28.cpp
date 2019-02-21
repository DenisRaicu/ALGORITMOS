// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

// función que resuelve el problema
void resolver(std::vector<std::vector<int>> const& matriz, int sup, int prod, 
	int sumAct, int & sumMin, int k, std::vector<int> & marcarSup) {

	for (int i = 0; i < sup; ++i)
	{
		sumAct += matriz[i][k]; //agrego lo que cuesta un producto;
		++marcarSup[i]; //Marco el supermercado usado;

		//Es valida --> compruebo que no se haya comprado mas de 3 prdocutos del mismo super:
		if (marcarSup[i] <= 3) { 
			if (k == prod-1) { //¿todos los productos agregados?
				//Es solucion --> compruebo si la solucion actual es mejor que la que tengo guardada:
				if (sumMin > sumAct) { 
					sumMin = sumAct; //Actualizo la mejor solucion;
				}
			}

			else resolver(matriz, sup, prod, sumAct, sumMin, k + 1, marcarSup); //Pasamos a la siguiente etapa;
		}

		sumAct -= matriz[i][k]; //Resto ultimo producto agregado cuando no es valido;
		--marcarSup[i]; //Desmarco el super usado;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int sup, prod, k = 0;
	int sumAct = 0, sumMin = 0;

	std::cin >> sup >> prod;

	tMatriz matriz(sup, std::vector<int>(prod));

	//Relleno la matriz:
	for (int i = 0; i < sup; ++i) {
		for (int j = 0; j < prod; ++j) {
			std::cin >> matriz[i][j];
		}
	}

	int i = 1, j = 0;

	//inicio la suma minima a la primera solucion valida:
	while (i-1 < sup && j < prod) {
		while (j < 3 * i && j < prod) {
			sumMin += matriz[i - 1][j];
			++j;
		}
		++i;
	}

	std::vector<int> marcarSup(sup, 0); // vector para marcar los supermercados usados;

	resolver(matriz, sup, prod, sumAct, sumMin, k, marcarSup);

	// escribir sol
	std::cout << sumMin << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt:
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}