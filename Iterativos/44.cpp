// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/* 
	COSTE FUNCIÓN resolver():

	O(n) --> siendo "n" el tamaño del vector de entrada;

*/

// función que resuelve el problema
std::vector<int> resolver(std::vector<int> const& v, int sec) {
	// Declaro el vector resultado con 2 posiciones (secuencia maxima y numero de llanos) inicializados a 0:
	std::vector<int> res(2,0); 
	int max = v[v.size() - 1]; //Pongo el maximo en la ultima posición (el primer elemento que recorro);
	int posMax = v.size() - 1; //Me guardo también la posición del ultimo elemento por si resulta ser el inicio de un llano;
	int contMax = 1; //Inicializo el contador de maximos a 1 ya que me he guardado el primer elemento;
	int numLlanos = 0; //El numero de llanos se inicializa a 0 ya que no sabamoes si tenemos alguno en un inicio;
	
	if (v.size() > 1) { //Cumple la condicion (l > 1) del enunciado;
		// Recorremos el vector en sentido inverso, desde el penultimo elemento 
		//(el ultimo ya lo hemos tenido en cuenta al inicializar las variables):
		for (int i = v.size() - 2; i >= 0; i--) { 
			if (v[i] > max) { //CASO 1: Se encuentra un nuevo maximo;
				if (contMax >= sec) { 
					numLlanos++; 
					if (contMax > res[0]) res[0] = contMax;
					res[1] = numLlanos;
					res.push_back(posMax);
				}
				max = v[i];
				posMax = i;
				contMax = 1;
			}

			else if (v[i] == max) { //CASO 2: El maximo encontrado es el mismo que el que teniamos;
				if (contMax == 0) posMax = i; //Caso especial, cuando hay dos maximos iguales separados por un dato pequeño: (*ej: 6 6 6 2 6 6 6)
				++contMax;
			}

			else { //CASO 3: Se encuentra un elemento que nuevo que es menor que un maximo;
				if (contMax >= sec) {
					numLlanos++;
					if (contMax > res[0]) res[0] = contMax;
					res[1] = numLlanos;
					res.push_back(posMax);
				}
				contMax = 0;
			}
		}
	
		// Caso especial, cuando el ultimo elemento recorrido v[0] solo ha incrementado el contador del maximo. 
		// Volvemos a preguntar si al incrementar el contador del maximo algo ha cambiado y si hay que actualizar:
		if (contMax >= sec) {
			numLlanos++;
			if (contMax > res[0]) res[0] = contMax;
			res[1] = numLlanos;
			res.push_back(posMax);
		}
	}

	return res; // Devolvemos el vector de resultados;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int num, sec;
	std::cin >> num >> sec;
	
	if (!std::cin) return false;

	std::vector<int> v(num);
	for (int & aux : v) std::cin >> aux;

	std::vector<int> sol = resolver(v, sec);

	// escribir sol
	for (int & aux : sol) std::cout << aux << " ";
	std::cout << "\n";

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