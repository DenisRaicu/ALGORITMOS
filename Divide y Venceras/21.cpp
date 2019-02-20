// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// El coste de la funcion en el caso peor va  a ser O(n) --> va a ser lineal con
// respecto al numero de elementos del vector, aunque si en cualquier momento
// una de las mitades no cumple la condicion descartamos la otra mitad.
// Esto nos dice que siempre que el numero sea caucásico tenemos un coste O(n), 
// lineal, pero en los demas casos siempre descartaremos alguna mitad. 
bool resolver(std::vector<int> const &v, int ini, int fin, int & cont) {
	
	if (ini >= fin) { //Si solo hay un elemento (caucasico por definicion).
		cont = 0;
		return true;
	}

	else if (ini + 1 == fin) { //Caso base para 2 numeros
		if ((v[ini] % 2 == 0) && (v[fin] % 2 == 0)) cont = 2; //Si los dos son pares
		else if ((v[ini] % 2 == 0) || (v[fin] % 2 == 0)) cont = 1; //Si solo uno es par
		else cont = 0; //Si ninguno es par

		return true;
	}

	else {
		int m = (ini + fin) / 2;
		int izq, der;

		if (resolver(v, ini, m, izq)) { //llamamos el lado izquierdo
			if (resolver(v, m + 1, fin, der)) { //llamamos al lado derecho
				if (abs(izq - der) <= 2) { //comprobamos que la resta sea <= 2
					cont = izq + der;
					return true;
				} else return false;
			} else return false;
		} else return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;

	if (num == 0) return false;

	std::vector<int> v(num);

	for (int i = 0; i < num; ++i)
		std::cin >> v[i];

	// escribir sol
	int cont = 0;

	if (resolver(v, 0, num - 1, cont)) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";

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