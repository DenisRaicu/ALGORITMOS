// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct datos {
	int racha = 0; //Digito 1 de los datos de salida;
	int numRachas = 0; //Digito 2 de los datos de salida;
	int numPartidosFinRacha = 0; //Digito 3 de los datos de salida;
};

// función que resuelve el problema
datos resolver(std::vector<int> const& v) { // O(n)
	datos info;
	int contR = 0;

	size_t i = 0;
	while (i < v.size()) {
		if (v[i] > 0) contR++; // Va contando partidos ganados (racha provisional);
		
		else { // Cuando se encuentra un partido empatado o perdido;
			// Preguntamos si antes habia contado algo, es decir, si habia una racha provisional:
			if (contR > 0) {  
				// Comprobamos que la racha provisional es mayor que la final y actualizamos los datos:
				if (contR > info.racha) { 
					info.racha = contR;
					info.numRachas = 1;
					info.numPartidosFinRacha = (v.size() - i);
				} 

				// Comprobamos que la racha provisional es igual que la racha final y actualizamos los datos:
				else if (contR == info.racha) {
					info.numRachas++;
					info.numPartidosFinRacha = (v.size() - i);
				}

				contR = 0; // Reinicializamos el contador;
			} 
		}
		++i;
	}

	// Cuando el ultimo partido ha sido ganado, actualizo los datos 
	// (dado que dentro del bucle no los ha actualizado, solo ha incrementado la racha provisional):
	if (contR > 0) {
		if (contR > info.racha) {
			info.racha = contR;
			info.numRachas = 1;
			info.numPartidosFinRacha = (v.size() - i);
		}

		else if (contR == info.racha) {
			info.numRachas++;
			info.numPartidosFinRacha = (v.size() - i);
		}
	}

	// Cuando no hay ninguna racha: 
	if (info.racha == 0) info.numPartidosFinRacha = v.size();

	return info;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int partidosJugados;
	std::cin >> partidosJugados;

	if (!std::cin) return false;

	std::vector<int> v(partidosJugados);
	for (int & goles : v) std::cin >> goles;

	datos sol = resolver(v);

	// escribir sol
	std::cout << sol.racha << " " << sol.numRachas << " " << sol.numPartidosFinRacha << "\n";
 
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