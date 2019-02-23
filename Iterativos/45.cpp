// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
	int suma = 0;
	int ini = 0;
	int tam = 0;
};

/*
	COSTE FUNCIÓN resolver();

	O(n) --> siendo n el tamaño del vector de entrada;

*/

// función que resuelve el problema
tSol resolver(std::vector<int> const& v, int num) {
	tSol sol;
	int cont = 0, sum = 0, ini = 0;

	for (int i = 0; i < num; ++i) {
		sum += v[i];

		if (sum > 0) { //CASO 1: suma positiva;
			if (cont == 0) ini = i;
			cont++;

			if (sol.suma < sum) {
				sol.suma = sum;
				sol.tam = cont;
				sol.ini = ini;
			}

			//Elige la secuencia mas corta si la suma es igual:
			if (sol.suma == sum && sol.tam > cont) { 
				sol.tam = cont;
				sol.ini = ini;
			}
		}

		else { //CASO 2: suma = 0 o suma negativa;
			if (sol.suma < sum) {
				sol.suma = sum;
				sol.tam = cont;
				sol.ini = ini;
			}

			//Elige la secuencia mas corta si la suma es igual:
			if (sol.suma == sum && sol.tam > cont) {
				sol.tam = cont;
				sol.ini = ini;
			}

			cont = 0;
			sum = 0;
		}
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num; 
	std::cin >> num;
	if (!std::cin) return false;

	std::vector<int> v(num);
	for (int & aux : v) std::cin >> aux;

	tSol sol = resolver(v, num);

	// escribir sol
	std::cout << sol.suma << " " << sol.ini << " " << sol.tam << "\n";
 
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to casos.txt
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