#include <stdio.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

struct Imagen 
{
	int codigo;
	char nombreArchivo[50];
	char extension[10];
	int tamano;
	float precio;
	Imagen *siguiente;
};

void mostrarImagen(struct Imagen *imagen);
void agregarImagen();
void eliminarImagen();
void buscarPorNombreArchivo();
void buscarPorExtension();
void buscarPorTamano();
void buscarPorCodigo();
void guardarImagenes();
void mostrarLista();
void recuperar_lista();

Imagen *lista = NULL;

int main() 
{
	int opcion;
	
	do
	{
		printf("==== Menú ====\n");
		printf("1. Agregar una nueva imagen\n");
		printf("2. Eliminar una imagen existente\n");
		printf("3. Buscar imágenes por nombre de archivo\n");
		printf("4. Buscar imágenes por extensión\n");
		printf("5. Buscar imágenes por tamaño\n");
		printf("6. Buscar imágenes por codigo\n");
		printf("7. Guardar Imagenes\n");
		printf("8. Mostrar Lista Ordenada Alfabeticamente\n");
		printf("9. Recuperar Lista de Archivo\n");
		printf("10. Salir\n\n");
		printf("Ingrese una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) 
		{
		case 1:
			agregarImagen();
			
			break;
		case 2:
			eliminarImagen();
			
			break;
		case 3:
			buscarPorNombreArchivo();
			
			break;
		case 4:
			buscarPorExtension();
			
			break;
		case 5:
			buscarPorTamano();
			
			break;
		case 6:
			buscarPorCodigo();
			
			break;
		case 7:
			guardarImagenes();
			
			break;
		case 8:
			mostrarLista();
			
			break;
		case 9:
			recuperar_lista();
			
			break;
		case 10:
			printf("\n\n¡Hasta luego!\n");
			
			break;
		default:
			printf("Opción inválida. Por favor, intente nuevamente.\n");
			
			break;
		}
		printf("\n");
		
	} while (opcion != 10);
}

void mostrarImagen(struct Imagen *imagen) 
{
	printf("\n\nCódigo de inventario: %d\n", imagen->codigo);
	printf("Nombre del archivo: %s\n", imagen->nombreArchivo);
	printf("Extensión: %s\n", imagen->extension);
	printf("Tamaño: %d bytes\n", imagen->tamano);
	printf("Precio: $%.2f\n", imagen->precio);
}

void agregarImagen() 
{
	struct Imagen *nueva_Imagen = new Imagen();
	
	printf("\nIngrese el código de inventario: ");
	scanf("%d", &nueva_Imagen->codigo);
	getchar();
	
	printf("\nIngrese el nombre del archivo: ");
	fgets(nueva_Imagen->nombreArchivo, 50, stdin);
	nueva_Imagen->nombreArchivo[strcspn(nueva_Imagen->nombreArchivo, "\n")] = '\0'; // Elimina el carácter de nueva línea
	
	printf("\nIngrese la extensión del archivo: ");
	fgets(nueva_Imagen->extension, 10, stdin);
	nueva_Imagen->extension[strcspn(nueva_Imagen->extension, "\n")] = '\0'; // Elimina el carácter de nueva línea
	
	printf("\nIngrese el tamaño en bytes: ");
	scanf("%d", &nueva_Imagen->tamano);
	
	printf("\nIngrese el precio de la imagen: ");
	scanf("%f", &nueva_Imagen->precio);
	
	nueva_Imagen->siguiente = lista; // El nuevo nodo apunta al antiguo primer nodo
	lista = nueva_Imagen;            // El puntero lista se actualiza para apuntar al nuevo nodo
	
	printf("\n\nImagen agregada correctamente.\n");
}

void eliminarImagen() 
{
	int codigoEliminar;
	printf("\nIngrese el código de inventario de la imagen a eliminar: ");
	scanf("%d", &codigoEliminar);
	
	if (lista != NULL)
	{
		Imagen *aux_borrar;
		Imagen *anterior = NULL;
		
		aux_borrar = lista;
		
		// Recorre la lista
		while((aux_borrar != NULL) && (aux_borrar->codigo != codigoEliminar))
		{
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		
		// Elemento no encontrado
		if(aux_borrar == NULL)
		{
			printf("\nLa imagen no existe");
		}
		// El primer elemento es el que se elimina 
		else if(anterior == NULL)
		{
			lista = lista->siguiente;
			delete aux_borrar;
		}
		// El elemento está en la lista pero no es el primero
		else
		{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
	else
	{
		printf("\nLa Lista de Imagenes está vacía");
	}
}

void buscarPorNombreArchivo() 
{
	char nombreArchivo[100];
	printf("\nIngrese el nombre de archivo a buscar: ");
	scanf("%s", nombreArchivo);
	
	Imagen* actual = lista;
	bool band = false;
	
	while (actual != NULL)
	{
		if (strcmp(actual->nombreArchivo, nombreArchivo) == 0)
		{
			band = true;
			mostrarImagen(actual);  // Simplemente pasa el puntero actual a la función
			break;
		}
		actual = actual->siguiente;
	}
	
	if (!band)
	{
		printf("\nLa Imagen con nombre %s no fue encontrada en la lista\n", nombreArchivo);
	}
}

void buscarPorExtension() 
{
	char extension[20];
	printf("\nIngrese la extensión a buscar: ");
	scanf("%s", extension);
	
	Imagen* actual = lista;
	bool band = false;
	
	while (actual != NULL)
	{
		if (strcmp(actual->extension, extension) == 0)
		{
			band = true;
			mostrarImagen(actual);  // Simplemente pasa el puntero actual a la función
			break;
		}
		actual = actual->siguiente;
	}
	if (!band)
	{
		printf("\nLa Imagen con nombre %s no fue encontrada en la lista\n", extension);
	}
}

void buscarPorTamano() 
{
	int tamano;
	printf("\nIngrese el tamaño a buscar: ");
	scanf("%d", &tamano);
	
	Imagen* actual = lista;
	bool band = false;
	
	while (actual != NULL)
	{
		if (actual->tamano == tamano)
		{
			band = true;
			mostrarImagen(actual);  // Simplemente pasa el puntero actual a la función
			break;
		}
		actual = actual->siguiente;
	}
	if (!band)
	{
		printf("\nLa Imagen con nombre %d no fue encontrada en la lista\n", tamano);
	}
}

void buscarPorCodigo() 
{
	int codigoBuscar;
	printf("\nIngrese el código de inventario a buscar: ");
	scanf("%d", &codigoBuscar);
	
	Imagen* actual = lista;
	bool band = false;
	
	while (actual != NULL)
	{
		if (actual->codigo == codigoBuscar)
		{
			band = true;
			mostrarImagen(actual);  // Simplemente pasa el puntero actual a la función
			break;
		}
		actual = actual->siguiente;
	}
	
	if (!band)
	{
		printf("\nLa Imagen con nombre %d no fue encontrada en la lista\n", codigoBuscar);
	}
}

void guardarImagenes()
{
	FILE *archivo = fopen("Imagenes.bin","ab+");
	if(archivo == NULL)
	{
		printf("\nNo se pudo abrir el archivo para escritura.");
		return;
	}
	
	// Recorro la lista y escribo cada elemento en el archivo 
	Imagen *actual = lista;
	while(actual != NULL)
	{
		fwrite(actual, sizeof(struct Imagen), 1, archivo);
		actual = actual->siguiente;
	}
	
	fclose(archivo);
	printf("\nEl archivo se guardo correctamente.");
}

void mostrarLista()
{
	if(lista == NULL)
	{
		printf("No hay imagenes en la lista");
		return;
	}
	else if (lista->siguiente == NULL) 
	{
		// No hay elementos o solo hay uno, no se necesita ordenar
		return;
	}
	
	struct Imagen *nueva_Lista = NULL;
	struct Imagen *actual = lista;
	
	while (actual != NULL)
	{
		struct Imagen *siguiente = actual->siguiente;
		if (nueva_Lista == NULL || strcmp(actual->nombreArchivo, nueva_Lista->nombreArchivo) < 0)
		{
			actual->siguiente = nueva_Lista;
			nueva_Lista = actual;
		}
		else
		{
			struct Imagen *temp = nueva_Lista;
			while (temp->siguiente != NULL && strcmp(actual->nombreArchivo, temp->siguiente->nombreArchivo) > 0)
			{
				temp = temp->siguiente;
			}
			actual->siguiente = temp->siguiente;
			temp->siguiente = actual;
		}
		actual = siguiente;
	}
	
	lista = nueva_Lista;
	printf("Lista ordenada alfabéticamente por nombre de archivo.\n");
	
	printf("Lista de Imágenes:\n");
	struct Imagen *actual1 = lista;
	while (actual1 != NULL)
	{
		mostrarImagen(actual1);
		actual1 = actual1->siguiente;
	}
}

void recuperar_lista() 
{
	FILE *archivo = fopen("Imagenes.bin", "rb");
	if (archivo == NULL) 
	{
		printf("No se pudo abrir el archivo para lectura.\n");
		return;
	}
	
	struct Imagen imagen;
	
	while (fread(&imagen, sizeof(struct Imagen), 1, archivo) == 1) 
	{
		struct Imagen *nuevaImagen = new Imagen();
		if (nuevaImagen == NULL) 
		{
			printf("Error al asignar memoria para la nueva imagen.\n");
			break;
		}
		
		*nuevaImagen = imagen;
		
		nuevaImagen->siguiente = lista;
		lista = nuevaImagen;
	}
	
	fclose(archivo);
	printf("La lista se recuperó correctamente.\n");
	
	Imagen *actual = lista;
	
	while(actual != NULL)
	{
		mostrarImagen(actual);
		actual = actual->siguiente;
	}
}
