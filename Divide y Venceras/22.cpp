// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct datos {
	bool jugador; // True --> jugador se presento, False --> no se presento;
	int numJuegos; // Numero de juegos acumulados;
};

// Función que resuelve el problema
/* El coste de la función es:

	T(n) = {
			T(1) = 1;
			T(n) = 2T(n/2) + 1;
	}

	--> Tras resolver la recurrencia obtenemos un coste de O(n), 
	siendo n el numero de elementos del vector;
*/
datos resolver(std::vector<std::string> const& partidos, int ini, int fin, int rondaLimite, int & rondaActual) {

	if (ini + 1 == fin) { // Cuando tenemos 2 jugadores ---> O(1);
		rondaActual = 1;

		if ((partidos[ini] != "NP") && (partidos[fin] != "NP")) return {true, 1}; // Si se presentaron los dos jugadores;
		else if ((partidos[ini] != "NP") || (partidos[fin] != "NP")) return {true, 0}; // Si solo se presento un jugador;
		else return {false, 0}; // Si ningun jugador se presento;
	}
	
	else { // Cuando hay mas de 2 jugadores;
		int mitad = (ini + fin) / 2;

		datos izq = resolver(partidos, ini, mitad, rondaLimite, rondaActual); // ---> O(log n);
		datos der = resolver(partidos, mitad + 1, fin, rondaLimite, rondaActual); // ---> O(log n);

		// Si se presentaran los dos jugadores (Ronda siguiente):
		if ((rondaLimite > rondaActual) && izq.jugador && der.jugador) {
			++rondaActual;
			return {true, (izq.numJuegos + der.numJuegos + 1)};
		}

		// Si solo se presentara uno de los dos jugadores (Ronda siguiente): 
		else if (izq.jugador || der.jugador) {
			++rondaActual;
			return {true, (izq.numJuegos + der.numJuegos)};
		}

		// Si se no se presentara ninguno de los dos jugadores (Ronda siguiente):
		else {
			++rondaActual;
			return {false, (izq.numJuegos + der.numJuegos)};
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int tam;
	std::cin >> tam;
	if (!std::cin) return false;

	int rondaLimite; 
	std::cin >> rondaLimite;

	std::vector<std::string> partidos(tam);

	for (std::string & jugador: partidos)
		std::cin >> jugador;

	int rondaActual;

	datos sol = resolver(partidos, 0, tam-1, rondaLimite, rondaActual);

	// Escribir sol:
	std::cout << sol.numJuegos << "\n";

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