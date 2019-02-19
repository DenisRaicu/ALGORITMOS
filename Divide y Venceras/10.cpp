// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
// En el caso peor la función tiene un coste O(n) siendo n el numero
// de elementos del vector.
// El caso peor: es que todos los numeros del vector son distintos, 
// eso nos obliga a mirar uno a uno todos los elementos del vector. 
// Pero con el caso base indicado descartamos los rangos donde los numeros
// son iguales.
// El caso mejor: es cuando todos los unmeros son iguales y eso provocara que el coste
// sea constante por el primer caso base. O(c);
int resolver(std::vector<int> const& v, int ini, int fin) {
	if (v[ini] == v[fin]) return 1; // Descarta rango de numeros iguales --> O(c);
	else if (ini >= fin) return 1; // Un solo elemento
	else if (ini + 1 == fin) { // Dos elementos
		if (v[ini] == v[fin]) return 1;
		else return 2;
	} else {
		int m = (fin + ini) / 2;

		int ladoIzq = resolver(v, ini, m); //O(log n)
		int ladoDer = resolver(v, m+1, fin); //O(log n)

		if (v[m] == v[m + 1]) return ladoIzq + (ladoDer - 1);
		else return ladoIzq + ladoDer;
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

	int sol = resolver(v, 0, num-1);

	// escribir sol
	std::cout << sol << "\n";

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