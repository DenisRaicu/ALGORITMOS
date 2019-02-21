// Denis Raicu
// E49

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//Función para comprobar cada solución: (NO SE USA PARA EL JUEZ)
void escribirSol(std::vector<int> const& sol) {
	for (size_t i = 0; i < sol.size(); ++i)
		std::cout << sol[i] << " ";

	std::cout << "\n";
}

//Comprueba que cumple las condiciones requeridas:S
bool esValida(int consMax, int k, std::vector<int> const& sol, 
	int cons, int i, std::vector<int> const& cont) {

	if (cons > consMax) return false; //Comprueba que no supere el coste maximo;
	//Comprueba que no haya mas de 2 bombillas del mismo color seguidas:
	if (k >= 2 && (sol[k - 2] == sol[k - 1] && sol[k - 1] == sol[k])) return false; 
	
	//Comprueba que la suma todas las bombillas + 1 no sea menor que 
	//la suma de una bombilla del mismo tipo:
	if (cont.size() > 1 && (cont[i] > (k/2) + 1)) return false;

	return true;
}

//Marcamos el numero de bombillas usadas de un color 
//acumulamos el consumo en una variable:
void marcar(std::vector<int> const& consumo, int & suma, 
	int i, std::vector<int> & cont) {
	cont[i] += 1;
	suma += consumo[i];
}

//Desmarcar el numero de bombillas usadas de un color 
//y desincrementamos el consumo:
void desmarcar(std::vector<int> const& consumo, int & suma, 
	int i, std::vector<int> & cont) {
	cont[i] -= 1;
	suma -= consumo[i];
}

// función que resuelve el problema
void resolver(std::vector<int> const& consumo, int longTira, int numColor,
	int consMax, int k, std::vector<int> & sol, 
	int suma, std::vector<int> & cont, int & total) {

	//Cada valor de i es igual a un color:
	for (int i = 0; i < numColor; ++i) {
		sol[k] = i; //metemos la primera bombilla;

		//marcamos:
		marcar(consumo, suma, i, cont);

		if (esValida (consMax, k, sol, suma, i, cont)) {
			//Comprobamos si es una solucion e incrementamos el numero de soluciones:
			if ((longTira - 1) == k) total++;
			//Vamos a la siguiente etapa:
			else resolver(consumo, longTira, numColor, consMax, k+1, sol, suma, cont, total); 
		}

		//desmarcamos:
		desmarcar(consumo, suma, i, cont);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int longTira, numColor, consMax;
	std::cin >> longTira;

	if (!std::cin) return false;

	std::cin >> numColor >> consMax;

	//Vector de consumos de cada bombilla:
	std::vector<int> vConsumo(numColor);

	for (int & aux : vConsumo)
		std::cin >> aux;

	//Vector solucion:
	std::vector<int> sol(longTira);
	//Vector en el que guardamos cuantas veces se ha 
	//usado cada tipo de bombilla:
	std::vector<int> cont(numColor);

	int suma = 0; //acumulador del consumo actual;
	int total = 0; //total de solcuines validas;
	resolver(vConsumo, longTira, numColor, consMax, 0, sol, suma, cont, total);

	// escribir sol
	std::cout << total << "\n";
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