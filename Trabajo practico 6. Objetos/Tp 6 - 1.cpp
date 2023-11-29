/*Desarrollar una clase “Cadena” para el manejo de cadenas de caracteres.
Además del constructor debe implementar como mínimo 5 métodos con
funcionalidades referidas a la manipulación de cadenas: longitud, Concatenar,
Copiar, Buscar coincidencias por carácter o por subcadena, etc. Demostrar el
funcionamiento de dicha Clase Cadena en el programa principal.*/

#include <iostream>
#include <cstring>

class Cadena {
private:
	char* cadena;
	
public:
	// Constructor
	Cadena(const char* str) {
		cadena = new char[strlen(str) + 1];
		strcpy(cadena, str);
	}
	
	// Destructor
	~Cadena() {
		delete[] cadena;
	}
	
	// longitud de la cadena
	int longitud() const {
		return strlen(cadena);
	}
	
	// concatenar dos cadenas
	void concatenar(const char* str) {
		char* nuevaCadena = new char[strlen(cadena) + strlen(str) + 1];
		strcpy(nuevaCadena, cadena);
		strcat(nuevaCadena, str);
		delete[] cadena;
		cadena = nuevaCadena;
	}
	
	// copiar la cadena a otra
	void copiarEn(Cadena& destino) const {
		destino.cadena = new char[strlen(cadena) + 1];
		strcpy(destino.cadena, cadena);
	}
	
	// buscar una subcadena en la cadena
	bool buscar(const char* subcadena) const {
		return strstr(cadena, subcadena) != nullptr;
	}
	
	// buscar un carácter en la cadena
	bool buscarCaracter(char caracter) const {
		return strchr(cadena, caracter) != nullptr;
	}
	
	// imprimir la cadena
	void imprimir() const {
		std::cout << cadena << std::endl;
	}
};

int main() {
	char entrada[100];  // Buffer para la entrada del usuario
	
	std::cout << "Ingrese una cadena: ";
	std::cin.getline(entrada, sizeof(entrada));
	
	Cadena miCadena(entrada);
	std::cout << "Longitud de la cadena: " << miCadena.longitud() << std::endl;
	
	std::cout << "Ingrese una cadena para concatenar: ";
	std::cin.getline(entrada, sizeof(entrada));
	miCadena.concatenar(entrada);
	std::cout << "Cadena concatenada: ";
	miCadena.imprimir();
	
	// Crear una nueva instancia de Cadena y copiar la cadena original en ella
	Cadena copiaCadena("");
	miCadena.copiarEn(copiaCadena);
	std::cout << "Copia de la cadena: ";
	copiaCadena.imprimir();
	
	std::cout << "Ingrese una subcadena para buscar: ";
	std::cin.getline(entrada, sizeof(entrada));
	if (miCadena.buscar(entrada)) {
		std::cout << "La subcadena '" << entrada << "' se encuentra en la cadena." << std::endl;
	} else {
		std::cout << "La subcadena '" << entrada << "' no se encuentra en la cadena." << std::endl;
	}
	
	std::cout << "Ingrese un carácter para buscar: ";
	std::cin.getline(entrada, sizeof(entrada));
	char caracterBuscado = entrada[0];
	if (miCadena.buscarCaracter(caracterBuscado)) {
		std::cout << "El carácter '" << caracterBuscado << "' se encuentra en la cadena." << std::endl;
	} else {
		std::cout << "El carácter '" << caracterBuscado << "' no se encuentra en la cadena." << std::endl;
	}
	
	return 0;
}
