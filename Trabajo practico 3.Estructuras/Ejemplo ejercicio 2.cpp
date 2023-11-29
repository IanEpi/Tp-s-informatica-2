#include <iostream>
#include <string>

using namespace std;

// Definici�n de la estructura
struct Imagen {
	int codigo;
	string nombreArchivo;
	string extension;
	int tamanoBytes;
	float precio;
};

const int MAX_IMAGENES = 100;  // M�ximo n�mero de im�genes en el stock
Imagen stock[MAX_IMAGENES];    // Arreglo de estructuras para el stock
int numImagenes = 0;           // N�mero actual de im�genes en el stock

// Funci�n para agregar una nueva imagen al stock
void agregarImagen() {
	if (numImagenes < MAX_IMAGENES) {
		cout << "Ingrese el c�digo de inventario: ";
		cin >> stock[numImagenes].codigo;
		
		cout << "Ingrese el nombre del archivo: ";
		cin >> stock[numImagenes].nombreArchivo;
		
		cout << "Ingrese la extensi�n del archivo: ";
		cin >> stock[numImagenes].extension;
		
		cout << "Ingrese el tama�o en bytes: ";
		cin >> stock[numImagenes].tamanoBytes;
		
		cout << "Ingrese el precio de la imagen: ";
		cin >> stock[numImagenes].precio;
		
		numImagenes++;
		cout << "Imagen agregada al stock." << endl;
	} else {
		cout << "El stock est� lleno. No se pueden agregar m�s im�genes." << endl;
	}
}

// Funci�n para eliminar una imagen del stock
void eliminarImagen(int codigo) {
	for (int i = 0; i < numImagenes; i++) {
		if (stock[i].codigo == codigo) {
			for (int j = i; j < numImagenes - 1; j++) {
				stock[j] = stock[j + 1];
			}
			numImagenes--;
			cout << "Imagen eliminada del stock." << endl;
			return;
		}
	}
	cout << "Imagen con c�digo " << codigo << " no encontrada." << endl;
}

// Funci�n para modificar los datos de una imagen en el stock
void modificarImagen(int codigo) {
	for (int i = 0; i < numImagenes; i++) {
		if (stock[i].codigo == codigo) {
			cout << "Ingrese el nuevo nombre del archivo: ";
			cin >> stock[i].nombreArchivo;
			
			cout << "Ingrese la nueva extensi�n del archivo: ";
			cin >> stock[i].extension;
			
			cout << "Ingrese el nuevo tama�o en bytes: ";
			cin >> stock[i].tamanoBytes;
			
			cout << "Ingrese el nuevo precio de la imagen: ";
			cin >> stock[i].precio;
			
			cout << "Datos de la imagen actualizados." << endl;
			return;
		}
	}
	cout << "Imagen con c�digo " << codigo << " no encontrada." << endl;
}

// Funci�n principal
int main() {
	int opcion;
	do {
		cout << "Seleccione una opci�n:" << endl;
		cout << "1. Agregar imagen" << endl;
		cout << "2. Eliminar imagen" << endl;
		cout << "3. Modificar imagen" << endl;
		cout << "4. Salir" << endl;
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			agregarImagen();
			break;
		case 2:
			int codigoEliminar;
			cout << "Ingrese el c�digo de inventario de la imagen a eliminar: ";
			cin >> codigoEliminar;
			eliminarImagen(codigoEliminar);
			break;
		case 3:
			int codigoModificar;
			cout << "Ingrese el c�digo de inventario de la imagen a modificar: ";
			cin >> codigoModificar;
			modificarImagen(codigoModificar);
			break;
		case 4:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opci�n inv�lida." << endl;
		}
		
	} while (opcion != 4);
	
	return 0;
}
