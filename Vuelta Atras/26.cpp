// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using tMatriz = std::vector<std::vector<int>>;

//Comprueba que todo es correcto hasta la etapa actual:
bool esValida(int satMin, std::vector<int> const& jugDisp, std::vector<std::string> const& tipJug,
	std::vector<int> const& sol, tMatriz const& satisfacion, int k, int ninAct) {

	if (k % 2 != 0) { //si es impar, es decir, ya tenemos los dos juguetes asignados al niño actual;

		// Comprueba que los juguetes no son del mismo tipo:
		if (tipJug[sol[k - 1]] == tipJug[sol[k]]) return false; 
		
		// Comprueba que la suma de las satifacciones de los dos juguetes es menor que la suma minima:
		if ((satisfacion[ninAct - 1][sol[k - 1]] + satisfacion[ninAct - 1][sol[k]]) < satMin) return false;

		// Comprueba que el orden de los juguetes no importa:
		if (sol[k-1] > sol[k]) return false;
	}

	if (jugDisp[sol[k]] < 0) return false;

	return true;
}

//Desincrementar el total de juguetes disponible cuando se usa  
//e incrementa el numero del niño actual si es posicion par:
void marcar(std::vector<int> & jugDisp, int & ninAct, int i, int k) {
	--jugDisp[i];
	if (k % 2 == 0) ++ninAct;
}

//Incrementa el total de juguetes disponible cuando deja de usarlo  
//y desincremento el numero del niño actual si es posicion par:
void desmarcar(std::vector<int> & jugDisp, int & ninAct, int i, int k) {
	++jugDisp[i];
	if (k % 2 == 0) --ninAct;
}

//Escribimos una solucion que es valida:
void escribirSol(std::vector<int> const& sol) {
	std::cout << sol[0];

	for (size_t i = 1; i < sol.size(); ++i)
		std::cout << " " << sol[i];

	std::cout << "\n";
}

// función que resuelve el problema
void resolver(int numJug, int numNin, int satMin, std::vector<int> & jugDisp,
	std::vector<std::string> const& tipJug, tMatriz const& satisfacion,
	std::vector<int> & sol, int k, bool & ok, int ninAct) {

	for (int i = 0; i < numJug; i++) {
		sol[k] = i; //asigno el primer juguete a un niño;

		marcar(jugDisp, ninAct, i, k); //marco el juguete usado;

		if (esValida(satMin, jugDisp, tipJug, sol, satisfacion, k, ninAct)) {
			if (sol.size() - 1 == k) { //si hemos matado todas las etapas;
				ok = true; //marcamos que al menos hay una solucion;
				escribirSol(sol);
			}

			else { //avanzamos una etapa:
				resolver(numJug, numNin, satMin, jugDisp, tipJug, 
					satisfacion, sol, k + 1, ok, ninAct);
			}
		}

		desmarcar(jugDisp, ninAct, i, k); //desmarco el juguete usado;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int numJug, numNin, satMin;
	int k = 0;
	bool ok = false;
	int ninAct = 0;

	std::cin >> numJug;

	if (!std::cin) return false;

	std::cin >> numNin >> satMin;

	std::vector<int> jugDisp(numJug);
	for (int & aux : jugDisp) std::cin >> aux;

	std::vector<std::string> tipJug(numJug);
	for (std::string & tip : tipJug) std::cin >> tip;

	tMatriz satisfacion(numNin, std::vector<int>(numJug));

	for (int i = 0; i < numNin; ++i) {
		for (int j = 0; j < numJug; ++j) {
			std::cin >> satisfacion[i][j];
		}
	}

	//vector solucion --> con dos posiciones para cada niño:
	std::vector<int> sol(numNin * 2);

	resolver(numJug, numNin, satMin, jugDisp, tipJug, satisfacion, sol, k, ok, ninAct);

	// escribir sol
	if (!ok) std::cout << "SIN SOLUCION" << "\n";

	std::cout << "\n";
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