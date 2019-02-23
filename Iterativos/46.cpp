// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/*
	COSTE FUNCIÓN resolver();

	O(n) --> siendo n el numero de elementos de la matriz;
*/

// función que resuelve el problema
int resolver(std::vector<std::vector<int>> const& matriz, int n, int m) {
	int cont = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (matriz[i][j] == i) cont++;
		}
	}
	
	return cont;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m;
	std::cin >> n >>  m;
	if (!std::cin) return false;

	std::vector<std::vector<int>> matriz(n, std::vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> matriz[i][j];
		}
	}

	int sol = resolver(matriz, n, m);

	// escribir sol
	std::cout << sol << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to casos.txt
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