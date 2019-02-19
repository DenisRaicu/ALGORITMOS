// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolver(std::vector<int> const& v, int const& ini, int const& fin, int const& num, int & n) {

	if (ini > fin) return false;
	else {
		int m = (ini + fin) / 2;

		if (v[m] == m + num) {
			n = v[m];
			return true;
		} else {
			if (v[m] > m + num) return resolver(v, ini, m-1, num, n);
			else return resolver(v, m + 1, fin, num, n);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam, num;
	std::cin >> tam >> num;
	std::vector<int> v(tam);

	for (size_t i = 0; i < v.size(); ++i)
		std::cin >> v[i];

	int n; 
	bool sol = resolver(v, 0, tam-1, num, n);

	// escribir sol
	if (!sol) std::cout << "NO" << "\n";
	else std::cout << n << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
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