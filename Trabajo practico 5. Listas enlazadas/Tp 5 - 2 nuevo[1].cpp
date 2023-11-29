#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definici�n de la estructura "sensor" que representa un tipo de sensor
struct sensor {
	char marca[25];
	char model[20];
	char tipo[20];
	char unidad[10];
};

// Definici�n de la estructura "medicion" que representa una medici�n con su sensor asociado
struct medicion {
	struct sensor sens_us; // Sensor asociado a la medici�n
	char fecha[11];
	char hora[6];
	int valor_med;
	char coment[50];
	struct medicion *siguiente; // Puntero al siguiente nodo en la lista
	struct medicion *anterior;  // Puntero al nodo anterior en la lista (no se utiliza en este c�digo) ???
};

// Declaraci�n de funciones utilizadas en el programa
void nueva_med(struct medicion *&);
void imp_str(struct medicion *);
void elim_med(struct medicion *&, int);
void bus_sen(struct medicion *, char[]);
void bus_val_med(struct medicion *, int);
void recuperar_lista();
void guardarMediciones();
void ordenar_lista();

// Declaraci�n y definici�n de la lista (inicialmente vac�a)
struct medicion *lista = NULL;

// Funci�n principal del programa
int main() {
	int n, el, val;
	char tipo[20];
	
	// Definici�n de sensores predefinidos
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
	strcpy(list_sen[1].unidad, "�C");
	
	// Sensor 3 (de sonido)
	strcpy(list_sen[2].marca, "Candy-Ho");
	strcpy(list_sen[2].model, "Lm386");
	strcpy(list_sen[2].tipo, "Sensor de sonido");
	strcpy(list_sen[2].unidad, "dB");
	
	int cont = 0;
	
	printf("     --    Bienvenido a la base de datos de mediciones    --\n");
	
	// Men� principal del programa
	do {
		printf("\n  Seleccione una opci�n:\n");
		printf("  1- Agregar una nueva medici�n.\n");
		printf("  2- Eliminar una medici�n existente.\n");
		printf("  3- B�squeda por sensor.\n");
		printf("  4- B�squeda por valor medido.\n");
		printf("  5- Guardar en archivo.\n");
		printf("  6- Recuperar mediciones del Archivo.\n");
		printf("  7- Mostrar Mediciones ordenadas por fecha\n");
		printf("  8- Salir.\n\n");
		printf("Opci�n seleccionada: ");
		scanf("%d", &n);
		
		switch (n) {
		case 1:
			// Opci�n para agregar una nueva medici�n
			if (cont != 10) {
				nueva_med(lista);
				imp_str(lista);
				cont++;
				getchar(); // Limpia el buffer de entrada
			} else {
				printf("\n Ya ingres� el m�ximo de mediciones soportadas.");
			}
			break;
		case 2:
			// Opci�n para eliminar una medici�n existente
			if (cont == 0) {
				printf("\nERROR, no ingres� ninguna medici�n.");
			} else {
				printf("\n Ingrese el n�mero de medici�n a eliminar: ");
				scanf("%d", &el);
				elim_med(lista, el);
			}
			break;
		case 3:
			// Opci�n para buscar por tipo de sensor
			if (cont == 0) {
				printf("\nERROR, no ingres� ninguna medici�n.");
			} else {
				printf("\n Ingrese el tipo de sensor a buscar: ");
				getchar(); // Limpia el buffer de entrada
				fgets(tipo, 20, stdin);
				bus_sen(lista, tipo);
			}
			break;
		case 4:
			// Opci�n para buscar por valor medido
			if (cont == 0) {
				printf("\nERROR, no ingres� ninguna medici�n.");
			} else {
				printf("\n Ingrese el valor a buscar: ");
				scanf("%d", &val);
				bus_val_med(lista, val);
			}
			break;
		case 5:
			// Opci�n para guardar mediciones en un archivo binario
			guardarMediciones();
			break;
		case 6:
			// Opci�n para recuperar mediciones desde un archivo binario
			recuperar_lista();
			break;
		case 7:
			// Opci�n para mostrar mediciones ordenadas por fecha
			ordenar_lista();
			break;
		case 8:
			// Opci�n para salir del programa
			printf("\n  --  Adi�s  --\n");
			break;
		default:
			// Opci�n por defecto en caso de entrada no v�lida
			printf("\nOpci�n no v�lida, por favor intente nuevamente.");
			break;
		}
	} while (n != 8); // Contin�a el bucle hasta que se selecciona la opci�n de salir
}

// Funci�n para agregar una nueva medici�n a la lista
void nueva_med(struct medicion *&lista) {
	medicion *nuevo_nodo = new medicion();
	
	// Captura de informaci�n sobre la nueva medici�n
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
	printf("\nMedici�n insertada correctamente en la lista");
}

// Funci�n para imprimir los detalles de una medici�n
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

// Funci�n para eliminar una medici�n de la lista
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
			printf("\nLa medici�n no existe.");
			return;
		}
		
		if (anterior == NULL) {
			// El nodo a borrar est� al inicio de la lista
			lista = lista->siguiente;
		} else {
			// El nodo a borrar est� en medio o al final de la lista
			anterior->siguiente = aux_borrar->siguiente;
		}
		
		// Libera la memoria del nodo borrado
		free(aux_borrar);
		printf("\nLa medici�n se elimin� correctamente.");
	} else {
		printf("\nLa lista est� vac�a.");
	}
}

// Funci�n para buscar y mostrar mediciones por tipo de sensor
void bus_sen(struct medicion *lista, char tipo[]) {
	struct medicion *actual = lista;
	bool band = false;
	
	while (actual != NULL) {
		tipo[strcspn(tipo, "\n")] = '\0'; // Elimina el salto de l�nea si est� presente
		
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

// Funci�n para buscar y mostrar mediciones por valor medido
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

// Funci�n para recuperar mediciones desde un archivo binario
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
	printf("La lista se recuper� correctamente.\n");
	
	// Imprime todas las mediciones recuperadas
	struct medicion *actual = lista;
	while (actual != NULL) {
		imp_str(actual);
		actual = actual->siguiente;
	}
}

// Funci�n para guardar mediciones en un archivo binario
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
	printf("\nLa medici�n se guard� correctamente.");
}

// Funci�n para ordenar la lista de mediciones por fecha
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
