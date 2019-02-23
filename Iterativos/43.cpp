// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const& v) { // O(n) siendo n el tamaño del vector;
	int suma = 0, contMax = 0, max = v[0];

	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i] > max) {
			suma += (contMax * max);
			max = v[i];
			contMax = 1;
		} 
		else if (v[i] == max) contMax++;
		else suma += v[i];
	}

	return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num; 
	std::cin >> num;

	std::vector<int> v(num);
	for (int & aux : v) std::cin >> aux;

	int sol = resolver(v);
	
	// escribir sol
	std::cout << sol << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to casos.txt
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