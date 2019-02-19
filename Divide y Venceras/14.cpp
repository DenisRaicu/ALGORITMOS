// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// El coste de la función es O(n) --> siendo n el numero de elementos del vector:
bool resolver(std::vector<int> const& v, int ini, int fin, int & acumulado) {
	
	if (ini >= fin) return true; //Si hay un solo elemento;

	else if (ini + 1 == fin) { //Si hay solo 2 elementos;
		//Guardamos el acumulado por si existe un lado derecho para comprobar:
		acumulado = v[ini] + v[fin];
		//Comprobamos la condición del degradado para dos elementos:
		if (v[ini] < v[fin]) return true;
		else return false;
	}
	
	else { //Si hay más de 2 elementos;
		int m = (ini + fin) / 2;
		int acIz = 0, acDr = 0;

		bool ladoIzq = resolver(v, ini, m, acIz);
		bool ladoDer = resolver(v, m + 1, fin, acDr);

		//Comprobamos la condición y actualizamos el acumulado tras 
		//cada nivel de profundidad de la recursión:
		if (ladoIzq && ladoDer && acIz < acDr) {
			acumulado = acIz + acDr;
			return true;
		}else return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int filas; 
	std::cin >> filas;

	if (!std::cin) return false;

	int columnas;
	std::cin >> columnas;

	//Declaramos la matriz:
	std::vector<std::vector<int>> v(filas);

	//Rellenamos la matriz:
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j){
			int aux;
			std::cin >> aux;
			v[i].push_back(aux);
		}
	}

	bool sol = true;

	for (int i = 0; sol && (i < filas); ++i) {
		int acumulado = 0;
		sol = resolver(v[i], 0, columnas-1, acumulado);
	}

	// escribir sol
	if (sol) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt
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