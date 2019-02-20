// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>

// función que resuelve el problema
/* El coste de la función es el siguiente: 
	T(n)  = {
				T(1) = 1;
				T(n) = 2T(n/2) + 1;
	}  *siendo n el numero de submoviles existentes en cada lado.

	==> O(n);
*/
bool estaBalanceado(int &peso) {
	int pIzq, dIzq, pDer, dDer;
	bool okIzq = true, okDer = true;
	std::cin >> pIzq >> dIzq >> pDer >> dDer; // Lee la entrada estandar de un movil

	// Comprueba si el lado iquierdo tiene un submovil y si es asi 
	// hace la  llamada recursiva para comprobar el submovil izquierdo:
	if (pIzq == 0) okIzq = estaBalanceado(pIzq); // --> O(log (n));

	// Comprueba si el lado derecho tb. tiene un submovil y si es  asi
	// hace la  llamada recursiva para comprobar el submovil derecho:
	if (pDer == 0) okDer = estaBalanceado(pDer); // --> O(log (n));
		
	// Comprobamos que los dos lados estan balanceados y miramos la formula 
	// del equilibrio para ver si la cumple en el momento actual:
	if (okIzq && okDer && ((pIzq * dIzq) == (pDer * dDer))) { // --> O(1);
		peso = pDer + pIzq;
		return true;
	} else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int peso;

	// escribir sol
	if (estaBalanceado(peso)) std::cout << "SI" << "\n";
	else std::cout << "NO" << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to datos.txt
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}