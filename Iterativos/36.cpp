// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(std::vector<int> & v, int num) {
	int aux = 0;

	for (int i = 0; i < num; ++i) {
		if (v[i] % 2 == 0) {
			std::swap(v[i], v[aux]);
			aux++;
		}
	}

	v.resize(aux);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num; 
	std::cin >> num; 

	std::vector<int> v(num);

	for (int i = 0; i < num; ++i)
		std::cin >> v[i];

	resolver(v, num);
	
	// escribir sol:
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " " ;

	std::cout <<"\n";
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