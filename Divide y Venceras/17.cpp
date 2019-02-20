// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// El coste de esta función es O(log n)--> siendo n el numero de elementos
// del vector.
int resolver(std::vector<int> const& v, std::vector<int> const& w, int ini, int fin) {

	if (ini >= fin) return v[ini];
	
	else if (ini + 1 == fin) {
		if (w[ini] == v[ini]) return v[fin];
		else return v[ini];
	}

	else {
		int m = (ini + fin) / 2;
		
		//Descartamos la mitad del vector (con esto conseguimos
		//un coste logaritmico):
		if (v[m] != w[m]) return resolver(v, w, ini, m);
		else return resolver(v, w, m + 1, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;

	std::vector<int> v(num), w(num - 1);

	for (int i = 0; i < num; ++i)
		std::cin >> v[i];

	for (int & n : w) 
		std::cin >> n;

	int sol = resolver(v, w, 0, num - 1);
	
	// escribir sol
	std::cout << sol << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt
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