// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema:
int resolver(std::vector<int> const& v, int num, int & suma) { // O(n)
	int sumaAux = 0, pos = 0;

	//Calcula la primera suma: 
	for (int i = 0; i < num; ++i)  sumaAux += v[i];
	
	//Va actualizando la suma y se queda con la mejor, también 
	//devuelve la posicion del vagon a atracar:
	for (size_t i = num; i < v.size(); ++i) {
		if (suma <= sumaAux) { 
			suma = sumaAux;
			pos = (i - num);
		}

		sumaAux -= v[i - num]; //Resta la primera cantidad de la suma actual;
		sumaAux += v[i]; //Añade el siguiente elemento (el actual);
	}

	//Vuelve a actualizar la suma y la posicion cuando el subconjunto valido es el ultimo:
	if (suma <= sumaAux) {
		suma = sumaAux;
		pos = (v.size() - num);
	}

	return pos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tam, num, suma = 0;
	std::cin >> tam >> num;
	
	std::vector<int> v(tam);
	for (int & valor : v) std::cin >> valor;

	int sol = resolver(v, num, suma);
	
	// escribir sol
	std::cout << sol << " " << suma <<"\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	//save old buf and redirect std::cin to casos.txt
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