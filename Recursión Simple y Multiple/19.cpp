// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(int a, int b, std::vector<std::vector<int>> & m) {
	
	// Comprobamos los dos casos base: (b == 0 || a == b) ==> 1; 
	if (b == 0 || b == a) return m[a][b] = 1; 
	else { // Si no estamos en ningun caso base, montamos la formula;
		// Si la el numero combinatorio no esta calculado, seguimos con la recursion:
		if (m[a][b] == -1 ) { 
			// Busco la  primera parte de la formula (a-1, b-1):
			if (m[a-1][b-1] == -1) m[a-1][b-1] = resolver(a-1, b-1, m); 
			// Busco la segunda parte de la formula (a-1, b):
			if (m[a-1][b] == -1) m[a-1][b] = resolver(a-1, b, m); 
			
			return m[a][b] = m[a-1][b-1] + m[a-1][b]; // Sumamos las dos partes;
		} 

		//En el caso de  que el numero combinatorio buscado ya se ha calculado de antes:
		else return m[a][b];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int a, b;
	std::cin >> a;

	if (!std::cin) return false;
	std::cin >> b;

	std::vector<std::vector<int>> m(a+1, std::vector<int>(b+1, -1));

	// escribir sol
	std::cout << resolver(a, b, m) << "\n";

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