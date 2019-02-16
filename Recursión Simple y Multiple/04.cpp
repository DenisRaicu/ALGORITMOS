// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
unsigned long int resolver(unsigned long int n) {

	if (n < 10) {
		if (n % 2 != 0) return n;
		else return 0;
	}
	else {
		int resto = n % 10;
		if (resto % 2 != 0) return resolver(n / 10) * 10 + resto;
		else return resolver(n / 10);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	unsigned long int datos;

	std::cin >> datos;
	if (!std::cin)return false;

	unsigned long int solucion = resolver(datos);

	// escribir sol
	std::cout << solucion << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}