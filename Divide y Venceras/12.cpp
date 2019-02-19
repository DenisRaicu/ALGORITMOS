// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// O(n) --> O(log n) + O(log n): siendo n el tamaño del vector.
bool resolver(std::vector<int> const& v, int ini, int fin, int dist) {

	if (ini >= fin) return true; // O(c) --> constante
	else if (ini + 1 == fin) { // O(c) --> constante
		if (dist <= std::abs(v[ini + 1] - v[ini])) return true;
		else return false;
	} else { // O(n) --> lineal
		int m = (ini + fin) / 2;
		
		bool ladoIzq = resolver(v, ini, m, dist); // O(log n) --> primera mitad del vector;
		bool ladoDer = resolver(v, m+1, fin, dist); // O(log n) --> segunda mitad del vector;

		if (ladoIzq && ladoDer && dist <= std::abs(v[ini] - v[fin])) return true;
		else return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;
	if (!std::cin) return false;
	
	int dist;
	std::cin >> dist;
	std::vector<int> v(num);

	for (int i = 0; i < num; ++i)
		std::cin >> v[i];

	bool ok = resolver(v, 0, num - 1, dist);

	// escribir sol
	if (ok) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

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