// Denis Raicu	
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(std::vector<int> const& v, int p) { //O(n)
	bool ok = true;
	int max = v[0];

	for (int i = 0; i <= p; ++i) {
		if (v[i] > max) max = v[i];
	}

	for (size_t i = p + 1; i < v.size() && ok; ++i) {
		if (max >= v[i]) ok = false;
	}

	return ok;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam = 0, p = 0;
	std::cin >> tam >> p; 

	std::vector<int> v(tam);
	for (int & dato : v) 
		std::cin >> dato;

	bool sol = resolver(v, p);
	// escribir sol

	if (sol) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to casos.txt:
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