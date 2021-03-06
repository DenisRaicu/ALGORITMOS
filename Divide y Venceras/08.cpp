﻿// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const& v, int const& ini, int const& fin) {

	if (ini == fin) return v[ini];
	else {
		int m = (fin + ini) / 2;

		if (v[ini] < v[fin]) {
			if (v[m] < v[m + 1]) return v[m];
			else if (v[m] > v[ini]) return resolver(v, ini, m);
			else return resolver(v, m+1, fin);
		}
		else return v[fin];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	std::cin >> tam;

	if (!std::cin)return false;
	std::vector<int> v(tam);

	for (size_t i = 0; i < v.size(); ++i)
		std::cin >> v[i];

	int sol = resolver(v, 0, tam-1);

	// escribir sol
	std::cout << sol << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}