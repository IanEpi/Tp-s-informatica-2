#include <stdio.h>
#include <string.h>
#include <iostream>
//#include <file.h>


#define MAX_MEDIDAS 100

// Definición de la estructura de imagen
//Ian, fijate en la funcion de eliminar imagen 
struct medida {
	int codigo;
	char nombre[50];
	char extension[10];
	int tamanoBytes;
	float precio;
};

int numMedidas = 0;

medida stock[MAX_MEDIDAS];

// Función para agregar una nueva imagen al stock
void agregarMedida(struct medida stock[], int *numMedidas) {
	if (*numMedidas < MAX_MEDIDAS) {
		struct medida nuevaMedida;
		
		printf("Ingrese el código de inventario: ");
		scanf("%d", &nuevaMedida.codigo);
		
		printf("Ingrese el nombre del archivo: ");
		scanf("%s", nuevaMedida.nombre);
		
		printf("Ingrese la extensión del archivo: ");
		scanf("%s", nuevaMedida.extension);
		
		printf("Ingrese el tamaño en bytes: ");
		scanf("%d", &nuevaMedida.tamanoBytes);
		
		printf("Ingrese el precio de la imagen: ");
		scanf("%f", &nuevaMedida.precio);
		
		stock[*numMedidas] = nuevaMedida;
		(*numMedidas)++;
		
		printf("Imagen agregada al stock.\n");
	} else {
		printf("El stock de imágenes está lleno.\n");
	}
}

// Función para mostrar el stock de imágenes
void mostrarStock(struct medida stock[], int numMedidas) {
	printf("Stock de imágenes:\n");
	for (int i = 0; i < numMedidas; i++) {
		printf("Código: %d\n", stock[i].codigo);
		printf("Nombre: %s\n", stock[i].nombre);
		printf("Extensión: %s\n", stock[i].extension);
		printf("Tamaño (bytes): %d\n", stock[i].tamanoBytes);
		printf("Precio: %.2f\n\n", stock[i].precio);
	}
}

//Funcion eliminar Imagen
void eliminarImagen(int codigo) {
	for (int i = 0; i < numMedidas; i++) {
		if (stock[i].codigo == codigo) {
			for (int j = i; j < numMedidas - 1; j++) {
				stock[j] = stock[j + 1];
			}
			numMedidas--;
			printf("Imagen eliminada del stock.");
			return;
		}
	}
	printf("Imagen con código %d no encontrada.\n", codigo);
}

int main() {
	int opcion;
	int codigo; // Si tiene que agregar la variable para eliminar la imagen 
	
	do {
		printf("Menu:\n");
		printf("1. Agregar Medida al stock\n");
		printf("2. Mostrar stock de Medidas\n");
		printf("3. Eliminar Media del stock\n"); 
		printf("4. Salir\n");
		printf("Seleccione una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			agregarMedida(stock, &numMedidas);
			break;
		case 2:
			mostrarStock(stock, numMedidas);
			break;
		case 3:
			printf("Ingrese el código de la Medida a eliminar: ");
			scanf("%d", &codigo);
			eliminarImagen(codigo);
			break;
		case 4:
			printf("Saliendo...\n");
			break;
		default:
			printf("Opción no válida.\n");
		}
	} while (opcion != 4);
	
	return 0;
}
