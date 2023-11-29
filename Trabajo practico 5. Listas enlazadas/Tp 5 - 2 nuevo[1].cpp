#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definición de la estructura "sensor" que representa un tipo de sensor
struct sensor {
	char marca[25];
	char model[20];
	char tipo[20];
	char unidad[10];
};

// Definición de la estructura "medicion" que representa una medición con su sensor asociado
struct medicion {
	struct sensor sens_us; // Sensor asociado a la medición
	char fecha[11];
	char hora[6];
	int valor_med;
	char coment[50];
	struct medicion *siguiente; // Puntero al siguiente nodo en la lista
	struct medicion *anterior;  // Puntero al nodo anterior en la lista (no se utiliza en este código) ???
};

// Declaración de funciones utilizadas en el programa
void nueva_med(struct medicion *&);
void imp_str(struct medicion *);
void elim_med(struct medicion *&, int);
void bus_sen(struct medicion *, char[]);
void bus_val_med(struct medicion *, int);
void recuperar_lista();
void guardarMediciones();
void ordenar_lista();

// Declaración y definición de la lista (inicialmente vacía)
struct medicion *lista = NULL;

// Función principal del programa
int main() {
	int n, el, val;
	char tipo[20];
	
	// Definición de sensores predefinidos
	struct sensor list_sen[3];
	
	// Sensor 1 (de luz)
	strcpy(list_sen[0].marca, "Texsalux");
	strcpy(list_sen[0].model, "F1000");
	strcpy(list_sen[0].tipo, "Sensor de luz");
	strcpy(list_sen[0].unidad, "Lux");
	
	// Sensor 2 (de temperatura)
	strcpy(list_sen[1].marca, "Candy-Ho");
	strcpy(list_sen[1].model, "Lm35");
	strcpy(list_sen[1].tipo, "Sensor de temperatura");
	strcpy(list_sen[1].unidad, "°C");
	
	// Sensor 3 (de sonido)
	strcpy(list_sen[2].marca, "Candy-Ho");
	strcpy(list_sen[2].model, "Lm386");
	strcpy(list_sen[2].tipo, "Sensor de sonido");
	strcpy(list_sen[2].unidad, "dB");
	
	int cont = 0;
	
	printf("     --    Bienvenido a la base de datos de mediciones    --\n");
	
	// Menú principal del programa
	do {
		printf("\n  Seleccione una opción:\n");
		printf("  1- Agregar una nueva medición.\n");
		printf("  2- Eliminar una medición existente.\n");
		printf("  3- Búsqueda por sensor.\n");
		printf("  4- Búsqueda por valor medido.\n");
		printf("  5- Guardar en archivo.\n");
		printf("  6- Recuperar mediciones del Archivo.\n");
		printf("  7- Mostrar Mediciones ordenadas por fecha\n");
		printf("  8- Salir.\n\n");
		printf("Opción seleccionada: ");
		scanf("%d", &n);
		
		switch (n) {
		case 1:
			// Opción para agregar una nueva medición
			if (cont != 10) {
				nueva_med(lista);
				imp_str(lista);
				cont++;
				getchar(); // Limpia el buffer de entrada
			} else {
				printf("\n Ya ingresó el máximo de mediciones soportadas.");
			}
			break;
		case 2:
			// Opción para eliminar una medición existente
			if (cont == 0) {
				printf("\nERROR, no ingresó ninguna medición.");
			} else {
				printf("\n Ingrese el número de medición a eliminar: ");
				scanf("%d", &el);
				elim_med(lista, el);
			}
			break;
		case 3:
			// Opción para buscar por tipo de sensor
			if (cont == 0) {
				printf("\nERROR, no ingresó ninguna medición.");
			} else {
				printf("\n Ingrese el tipo de sensor a buscar: ");
				getchar(); // Limpia el buffer de entrada
				fgets(tipo, 20, stdin);
				bus_sen(lista, tipo);
			}
			break;
		case 4:
			// Opción para buscar por valor medido
			if (cont == 0) {
				printf("\nERROR, no ingresó ninguna medición.");
			} else {
				printf("\n Ingrese el valor a buscar: ");
				scanf("%d", &val);
				bus_val_med(lista, val);
			}
			break;
		case 5:
			// Opción para guardar mediciones en un archivo binario
			guardarMediciones();
			break;
		case 6:
			// Opción para recuperar mediciones desde un archivo binario
			recuperar_lista();
			break;
		case 7:
			// Opción para mostrar mediciones ordenadas por fecha
			ordenar_lista();
			break;
		case 8:
			// Opción para salir del programa
			printf("\n  --  Adiós  --\n");
			break;
		default:
			// Opción por defecto en caso de entrada no válida
			printf("\nOpción no válida, por favor intente nuevamente.");
			break;
		}
	} while (n != 8); // Continúa el bucle hasta que se selecciona la opción de salir
}

// Función para agregar una nueva medición a la lista
void nueva_med(struct medicion *&lista) {
	medicion *nuevo_nodo = new medicion();
	
	// Captura de información sobre la nueva medición
	printf("\nIngrese la marca del sensor: ");
	scanf("%s", nuevo_nodo->sens_us.marca);

	
	printf("\nIngrese el modelo del sensor: ");
	scanf("%s", nuevo_nodo->sens_us.model);
	
	printf("\nIngrese el tipo del sensor: ");
	scanf("%s", nuevo_nodo->sens_us.tipo);
	
	printf("\nIngrese la unidad de medida: ");
	scanf("%s", nuevo_nodo->sens_us.unidad);
	
	printf("\nIngrese la fecha (formato dd/mm/yyyy): ");
	scanf("%s", nuevo_nodo->fecha);
	
	printf("\nIngrese la hora (formato hh:mm): ");
	scanf("%s", nuevo_nodo->hora);
	
	printf("\nIngrese el valor medido: ");
	scanf("%d", &nuevo_nodo->valor_med);
	
	printf("\nIngrese comentario: ");
	getchar(); // Limpia el buffer de entrada
	fgets(nuevo_nodo->coment, 50, stdin);
	
	// Agrega el nuevo nodo al inicio de la lista
	nuevo_nodo->siguiente = lista;
	lista = nuevo_nodo;
	printf("\nMedición insertada correctamente en la lista");
}

// Función para imprimir los detalles de una medición
void imp_str(struct medicion *actual) {
	printf("\nMarca del sensor: %s\n", actual->sens_us.marca);
	printf("Modelo del sensor: %s\n", actual->sens_us.model);
	printf("Tipo del sensor: %s\n", actual->sens_us.tipo);
	printf("Unidad de medida: %s\n", actual->sens_us.unidad);
	printf("Fecha: %s\n", actual->fecha);
	printf("Hora: %s\n", actual->hora);
	printf("Valor medido: %d\n", actual->valor_med);
	printf("Comentario: %s\n", actual->coment);
}

// Función para eliminar una medición de la lista
void elim_med(struct medicion *&lista, int el) {
	if (lista != NULL) {
		struct medicion *aux_borrar = lista;
		struct medicion *anterior = NULL;
		
		// Busca el nodo a borrar en la lista
		while (aux_borrar != NULL && aux_borrar->valor_med != el) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		if (aux_borrar == NULL) {
			printf("\nLa medición no existe.");
			return;
		}
		
		if (anterior == NULL) {
			// El nodo a borrar está al inicio de la lista
			lista = lista->siguiente;
		} else {
			// El nodo a borrar está en medio o al final de la lista
			anterior->siguiente = aux_borrar->siguiente;
		}
		
		// Libera la memoria del nodo borrado
		free(aux_borrar);
		printf("\nLa medición se eliminó correctamente.");
	} else {
		printf("\nLa lista está vacía.");
	}
}

// Función para buscar y mostrar mediciones por tipo de sensor
void bus_sen(struct medicion *lista, char tipo[]) {
	struct medicion *actual = lista;
	bool band = false;
	
	while (actual != NULL) {
		tipo[strcspn(tipo, "\n")] = '\0'; // Elimina el salto de línea si está presente
		
		// Compara el tipo de sensor y muestra detalles si coincide
		if (strcmp(actual->sens_us.tipo, tipo) == 0) {
			band = true;
			imp_str(actual);
		}
		actual = actual->siguiente;
	}
	if (!band) {
		printf("\nEl tipo de sensor no fue encontrado");
	}
}

// Función para buscar y mostrar mediciones por valor medido
void bus_val_med(struct medicion *lista, int val) {
	struct medicion *actual = lista;
	bool band = false;
	
	while (actual != NULL) {
		// Compara el valor medido y muestra detalles si coincide
		if (actual->valor_med == val) {
			band = true;
			imp_str(actual);
		}
		actual = actual->siguiente;
	}
	
	if (!band) {
		printf("\nEl valor del sensor no fue encontrado");
	}
}

// Función para recuperar mediciones desde un archivo binario
void recuperar_lista() {
	FILE *archivo = fopen("Mediciones.bin", "rb");
	if (archivo == NULL) {
		printf("No se pudo abrir el archivo para lectura.\n");
		return;
	}
	
	struct medicion medicion;
	
	// Lee cada registro desde el archivo y agrega a la lista
	while (fread(&medicion, sizeof(struct medicion), 1, archivo) == 1) {
		struct medicion *nuevaMedicion = (struct medicion *)malloc(sizeof(struct medicion));
		if (nuevaMedicion == NULL) {
			printf("Error al asignar memoria para la nueva medicion.\n");
			break;
		}
		
		*nuevaMedicion = medicion;
		
		// Agrega el nuevo nodo al inicio de la lista
		nuevaMedicion->siguiente = lista;
		lista = nuevaMedicion;
	}
	
	fclose(archivo);
	printf("La lista se recuperó correctamente.\n");
	
	// Imprime todas las mediciones recuperadas
	struct medicion *actual = lista;
	while (actual != NULL) {
		imp_str(actual);
		actual = actual->siguiente;
	}
}

// Función para guardar mediciones en un archivo binario
void guardarMediciones() {
	FILE *archivo = fopen("Mediciones.bin", "ab+");
	if (archivo == NULL) {
		printf("\nNo se pudo abrir el archivo para escritura.");
	}
	
	// Recorre la lista y escribe cada elemento en el archivo
	medicion *actual = lista;
	while (actual != NULL) {
		fwrite(actual, sizeof(struct medicion), 1, archivo);
		actual = actual->siguiente;
	}
	fclose(archivo);
	printf("\nLa medición se guardó correctamente.");
}

// Función para ordenar la lista de mediciones por fecha
void ordenar_lista() {
	if (lista == NULL) {
		printf("No hay mediciones en la lista");
		return;
	} else if (lista->siguiente == NULL) {
		// No hay elementos o solo hay uno, no se necesita ordenar
		return;
	}
	
	struct medicion *nueva_Lista = NULL;
	struct medicion *actual = lista;
	
	// Recorre la lista original y construye una nueva lista ordenada por fecha
	while (actual != NULL) {
		struct medicion *siguiente = actual->siguiente;
		if (nueva_Lista == NULL || strcmp(actual->fecha, nueva_Lista->fecha) < 0) {
			actual->siguiente = nueva_Lista;
			nueva_Lista = actual;
		} else {
			struct medicion *temp = nueva_Lista;
			while (temp->siguiente != NULL && strcmp(actual->fecha, temp->siguiente->fecha) > 0) {
				temp = temp->siguiente;
			}
			actual->siguiente = temp->siguiente;
			temp->siguiente = actual;
		}
		actual = siguiente;
	}
	
	lista = nueva_Lista; // Actualiza la lista original con la nueva lista ordenada
	printf("Lista ordenada por fecha:\n");
	
	// Imprime las mediciones ordenadas
	struct medicion *actual1 = lista;
	while (actual1 != NULL) {
		imp_str(actual1);
		actual1 = actual1->siguiente;
	}
}
