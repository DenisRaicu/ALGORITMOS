// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

//Comprueba si hasta hasta el momento el llenado del vector es valido:
bool esValida(int altura, int azul, int rojo, int verde, std::vector<std::string> & sol,
	int nAzul, int nRojo, int nVerde, int k) {
	
	if (nAzul > azul || nRojo > rojo || nVerde > verde ||
		(sol[k] == "verde" && sol[k - 1] == "verde") || 
		(nVerde > nAzul)) return false;
	else return true;
}

//Marca el color que se va a usar y lo devuelve para asignarlo al vector:
std::string asignarMarcar(int i, int & nAzul, int & nRojo, int & nVerde) {
	switch (i) {
	case 0: ++nAzul;  return "azul";
	case 1: ++nRojo;  return "rojo";
	case 2: ++nVerde;  return "verde";
	default:return"";
	}
}

//Desmarcamos el color que se ha usado y no sido valido:
void desmarcar(int i, int & nAzul, int & nRojo, int & nVerde) {
	switch (i) {
	case 0: --nAzul;  break;
	case 1: --nRojo;  break;
	case 2: --nVerde;  break;
	}
}

//Escribe una solucion:
void escribirSolucion(std::vector<std::string> const& sol) {
	
	std::cout << sol[0];

	for (size_t i = 1; i < sol.size(); ++i)
		std::cout << " " << sol[i];

	std::cout << "\n";
}

// función que resuelve el problema
void resolver(int altura, int azul, int rojo, int verde, std::vector<std::string> & sol, 
	int nAzul, int nRojo, int nVerde, int k, bool & ok) {

	// nAzul --> i = 0, nRojo --> i = 1, nVerde --> i = 2;
	for (int i = 0; i < 3; ++i) {
		
		//Asigna un color en la etapa respectiva y marco el color usado:
		sol[k] = asignarMarcar(i, nAzul, nRojo, nVerde);

		//Comprueba si hasta el momento se cumplen las condiciones:
		if (esValida(altura, azul, rojo, verde, sol, nAzul, nRojo, nVerde, k)) {
	
			//Compruebo si se ha llenado el vector:
			if (k == altura-1) {
				//Comprueba si es solucion:
				if (nRojo > (nAzul + nVerde)) {
					escribirSolucion(sol); //Escribo la solucion encontrada;
					ok = true; //Marco que he tenido al menos una solucion;
				}
			}

			else { //Si el vector no se ha llenado seguimos con la siguiente etapa;
				//Comprueba si en el espacio que queda aun se podria encontrar una solucion valida:
				if ((altura - 1) - k > (nVerde + nAzul - nRojo) && (rojo > nVerde + nAzul))
					//Pasamos a la siguiente etapa:
					resolver(altura, azul, rojo, verde, sol, nAzul, nRojo, nVerde, k + 1, ok);
			}
		}

		//Desmarco el color que no cumple la condicion:
		desmarcar(i, nAzul, nRojo, nVerde);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int altura, azul, rojo, verde;

	std::cin >> altura >> azul >> rojo >> verde;
	
	//Comprobamos centinela --> 0000:
	if (altura == 0 && azul == 0 && rojo == 0 && verde  == 0) 
		return false;

	std::vector<std::string> sol(altura);

	//Si no cumple estas condiciones iniciales, no hay solucion:
	if ((rojo <= 1) || (altura < 2) || (azul + rojo + verde < altura))
		std::cout << "SIN SOLUCION" << "\n";
	else {
		sol[0] = "rojo"; //Primera ficha siempre roja;
		bool ok = false;
		resolver(altura, azul, rojo, verde, sol, 0, 1, 0, 1, ok);

		//Si no ha  encontrado ni una solucion valida: 
		if (!ok) std::cout << "SIN SOLUCION" << "\n";
	}
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