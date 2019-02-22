// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct intervalo {
	int ini;
	int fin;
};

// función que resuelve el problema
intervalo resolver(std::vector<int> const& v, int altura) { // O(n)
	int cont = 0, suma = 0;
	intervalo in;

	size_t i = 0;
	while (i < v.size()) {
		if (v[i] > altura) cont++;
		 
		else {
			if (suma < cont) {
				suma = cont;
				in.ini = i - cont;
				in.fin = i - 1;
			}
			cont = 0;
		}
		++i;
	}

	if (suma < cont) {
		in.ini = i - cont;
		in.fin = i - 1;
	}

	return in;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num, altura;
	std::cin >> num >> altura;

	std::vector<int> v(num);
	for (int & alturas : v) std::cin >> alturas;

	intervalo sol = resolver(v, altura);

	// escribir sol
	std::cout << sol.ini << " " << sol.fin << "\n";
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