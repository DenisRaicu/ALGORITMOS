// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

enum piedrasPreciosas{diamante, rubi, esmeralda, zafiro, jade};

std::istream& operator >> (std::istream& entrada, piedrasPreciosas& p) {
	char num; 
	entrada >> num;

	switch (num) {
	case 'd': p = diamante; break;
	case 'r': p = rubi; break;
	case 'e': p = esmeralda; break;
	case 'z': p = zafiro; break;
	case 'j': p = jade; break;
	}

	return entrada;
}

// función que resuelve el problema
int resolver(std::vector<piedrasPreciosas> const& v, int secuencia, 
	piedrasPreciosas tipo1, int num1, piedrasPreciosas tipo2, int num2) { // O(n)
	int contn1 = 0, contn2 = 0, suma = 0;

	for (int i = 0; i < secuencia; ++i) {
		if (v[i] == tipo1) contn1++;
		else if (v[i] == tipo2) contn2++;
	}

	if (num1 <= contn1 && num2 <= contn2) suma++;

	for (size_t i = secuencia; i < v.size(); ++i) {
		if (v[i - secuencia] == tipo1) contn1--;
		else if (v[i - secuencia] == tipo2) contn2--;

		if (v[i] == tipo1) contn1++;
		else if (v[i] == tipo2) contn2++;

		if (num1 <= contn1 && num2 <= contn2) suma++;
	}

	return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numPiedras, secuencia;
	piedrasPreciosas tipo1, tipo2;
	int num1, num2;

	std::cin >> numPiedras >> secuencia >> tipo1 >> num1 >> tipo2 >> num2;

	std::vector<piedrasPreciosas> v(numPiedras);
	for (piedrasPreciosas & i : v) std::cin >> i;

	int sol = resolver(v, secuencia, tipo1, num1, tipo2, num2);
	
	// escribir sol
	std::cout << sol << "\n";
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