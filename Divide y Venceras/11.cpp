// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// O(log n) --> n es el numero de elementos del vector:
int resolverIzq(std::vector<int> const & v, int ini, int fin, int alt) {
	
	if (ini >= fin) return ini;
	else {
		int mitad = (ini + fin) / 2;
		
		if (v[mitad] < alt) return resolverIzq(v, mitad + 1, fin, alt);
		else return resolverIzq(v, ini, mitad, alt);
	}
}

// función que resuelve el problema
// O(log n) --> n es el numero de elementos del vector:
int resolverDer(std::vector<int> const & v, int ini, int fin, int alt) {

	if (ini >= fin && v[ini] == alt) return ini;
	else if(ini >= fin && v[ini] != alt) return ini - 1;
	else {
		int mitad = (ini + fin) / 2;

		if (v[mitad] > alt) return resolverDer(v, ini, mitad, alt);
		else return resolverDer(v, mitad+1, fin, alt);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam; 
	std::cin >> tam;

	if (!std::cin) return false;

	int alt;
	std::cin >> alt;

	std::vector<int> v(tam);

	for (int i = 0; i < tam; ++i)
		std::cin >> v[i];

	int solIzq = resolverIzq(v, 0, tam-1, alt);

	if (v[solIzq] != alt) {
		std::cout << "NO EXISTE" << "\n";
	} else {
		int solDer = resolverDer(v, 0, tam - 1, alt);
		if (solIzq == solDer) std::cout << solIzq << "\n";
		else std::cout << solIzq << " " << solDer << "\n";
	}
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to casos.txt:
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