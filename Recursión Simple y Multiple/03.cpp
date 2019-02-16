// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>

struct sol {
	long unsigned int num;
	int pot = 0;
};

// función que resuelve el problema
sol resolver(long unsigned int n) {

	if (n == 0) {
		sol s;
		s.num = 0;
		s.pot = 1;
		return s;
	} else {
		sol s = resolver(n / 10);
		sol p;
		p.num = s.num + (n % 10 * s.pot);
		p.pot = s.pot * 10;
		return p;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
	long unsigned int x;
	std::cin >> x;

	if (!std::cin) return false;

    sol solucion = resolver(x);
    
    // escribir sol
	std::cout << solucion.num << "\n";

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