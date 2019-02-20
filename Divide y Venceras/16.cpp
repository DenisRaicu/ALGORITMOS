// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>

// función que resuelve el problema
// El coste de la funcion es de O (n log(n)) siendo n el numero de elementos del 
// vector. Como hay 2 llamadas recursivas para cada mitad eso es equivalente a n (log n + log n)
// y el metodo de ordenar sort es O (n log(n)) + O (n) ---> O (n log(n)).
int resolver(std::vector<int> &  v, int ini, int fin) {

	if (ini >= fin) return 0;

	else {
		int m = (ini + fin) / 2;

		int izq = resolver(v, ini, m); // O (log n)
		int der = resolver(v, m + 1, fin); // O (log n)

		int i = ini, j = m + 1, cont = 0;

		while (i <= m && j <= fin) {
			
			if (v[i] > v[j]) {
				cont += (m - i + 1);
				++j;
			} else ++i;
		}

		std::sort(v.begin() + ini, v.begin() + fin+1); // O(n log(n))
		return izq + der + cont;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;

	if (!std::cin)
		return false;

	std::vector<int> v(num);

	for (int & aux : v)
		std::cin >> aux;

	int sol = resolver(v, 0, num - 1);

	// escribir sol
	std::cout << sol << "\n";

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