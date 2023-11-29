/* Tema 3: Variables electricas
Funciones del programa:

·         Solicitar datos permanentemente, hasta que el usuario lo desee.  (Aprobado Básico)

·         Contener algunos o todos los datos, en alguna etapa del programa en una lista enlazada.  (Aprobado Básico)

·         Utilización de estructuras adecuadamente. (Aprobado Básico)

-----------------

·         Utilización de funciones. (+1)

·         Resguardar datos en un archivo.  (+1)

·         Permitir obtener los datos, posteriormente desde un archivo. (+1)

·         Permitir realizar búsquedas de datos al usuario, según algún criterio elegido. (+2)

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <>

struct Electrica {
	char dispositivo[50];
	float voltaje;
	float corriente;
	struct Electrica* siguiente;
};

//Primer función para el ingreso de datos electricos
void solicitarElectrica(struct Electrica** listaElectricas) {
	struct Electrica* nuevaElectrica = (struct Electrica*)malloc(sizeof(struct Electrica));
	printf("**********************************************\n");
	printf("Ingrese el nombre del dispositivo: ");
	scanf("%s", nuevaElectrica->dispositivo);
	printf("Ingrese el voltaje: ");
	scanf("%f", &nuevaElectrica->voltaje);
	printf("Ingrese la corriente: ");
	scanf("%f", &nuevaElectrica->corriente);
	nuevaElectrica->siguiente = *listaElectricas;
	*listaElectricas = nuevaElectrica;
	printf("**********************************************\n");
}

void mostrarElectricas(struct Electrica* listaElectricas) {
	printf("\n--- Variables eléctricas ---\n");
	while (listaElectricas != NULL) {
		printf("Dispositivo: %s, Voltaje: %.2f, Corriente: %.2f\n", listaElectricas->dispositivo, listaElectricas->voltaje, listaElectricas->corriente);
		listaElectricas = listaElectricas->siguiente;
	}
}
// Función principal
int main() {
	
	struct Electrica* listaElectricas = NULL;
	char opcion; 
	do {
		printf("\nOpciones:\n");
		
		printf("1. Ingresar Variable eléctrica.\n");
		printf("2. Mostrar Variables eléctricas.\n");
		printf("0. Salir.\n");
		printf("Ingrese una opción: ");
		scanf(" %c", &opcion);
		
		switch (opcion) {
		
		case '1':
			solicitarElectrica(&listaElectricas);
			break;
		case '2':
			mostrarElectricas(listaElectricas);
			break;
		case '0':
			printf("Saliendo del programa.\n");
			break;
		default:
			printf("Opción no válida.\n");
		}
	} while (opcion != '0');
	
	while (listaElectricas != NULL) {
		struct Electrica* temp = listaElectricas;
		listaElectricas = listaElectricas->siguiente;
		free(temp);
	}
	
	return 0;
}

