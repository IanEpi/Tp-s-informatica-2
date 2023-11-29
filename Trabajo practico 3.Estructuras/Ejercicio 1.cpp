#include <stdio.h>
#include <string.h>

struct Persona {
	char apellido[50];
	char nombre[50];
	int edad;
	float altura;
};

void cargarPorValor(struct Persona persona, int indice, struct Persona personas[]) {
	personas[indice] = persona;
}

void cargarPorReferencia(struct Persona *persona, int indice, struct Persona personas[]) {
	personas[indice] = *persona;
}

int main() {
	struct Persona personas[13];
	
	// Cargar personas utilizando pasaje por valor
	struct Persona persona1;
	strcpy(persona1.apellido, "Lopez");
	strcpy(persona1.nombre, "Juan");
	persona1.edad = 25;
	persona1.altura = 1.75;
	cargarPorValor(persona1, 0, personas);
	
	// Cargar personas utilizando pasaje por referencia
	struct Persona persona2;
	strcpy(persona2.apellido, "Gomez");
	strcpy(persona2.nombre, "Maria");
	persona2.edad = 32;
	persona2.altura = 1.68;
	cargarPorReferencia(&persona2, 1, personas);
	
	// Cargar otra persona utilizando pasaje por referencia
	struct Persona persona3;
	strcpy(persona3.apellido, "Martinez");
	strcpy(persona3.nombre, "Carlos");
	persona3.edad = 19;
	persona3.altura = 1.82;
	cargarPorReferencia(&persona3, 2, personas);
	
	// Mostrar arreglo de estructuras
	printf("Personas:\n");
	for (int i = 0; i < 3; i++) {
		printf("Persona %d:\n", i+1);
		printf("Apellido: %s\n", personas[i].apellido);
		printf("Nombre: %s\n", personas[i].nombre);
		printf("Edad: %d\n", personas[i].edad);
		printf("Altura: %.2f\n", personas[i].altura);
		printf("\n");
	}
	
	int numPersonas;
	printf("Ingrese el número de personas a cargar (máximo 10): ");
	scanf("%d", &numPersonas);
	if (numPersonas > 10) {
		printf("El número de personas excede el límite. Se cargará un máximo de 10 personas.\n");
		numPersonas = 10;
	}
	
	for (int i = 0; i < numPersonas; i++) {
		struct Persona nuevaPersona;
		
		printf("Ingrese el apellido de la persona %d: ", i+1);
		scanf("%s", nuevaPersona.apellido);
		
		printf("Ingrese el nombre de la persona %d: ", i+1);
		scanf("%s", nuevaPersona.nombre);
		
		printf("Ingrese la edad de la persona %d: ", i+1);
		scanf("%d", &nuevaPersona.edad);
		
		printf("Ingrese la altura de la persona %d: ", i+1);
		scanf("%f", &nuevaPersona.altura);
		
		cargarPorValor(nuevaPersona, i, personas);
	}
	
	// Mostrar arreglo de estructuras
	printf("Personas:\n");
	for (int i = 0; i < numPersonas; i++) {
		printf("Persona %d:\n", i+1);
		printf("Apellido: %s\n", personas[i].apellido);
		printf("Nombre: %s\n", personas[i].nombre);
		printf("Edad: %d\n", personas[i].edad);
		printf("Altura: %.2f\n", personas[i].altura);
		printf("\n");
	}
	
	// Realizar cualquier otro análisis que necesites aquí
	
	return 0;
}
