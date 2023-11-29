#include <stdio.h>
#include <string.h>

#define MAX_PERSONS 3

struct Person {
	char apellido[50];
	char nombre[50];
	int edad;
	float altura;
};

void cargarPersonasPorValor(struct Person personas[]);
void cargarPersonasPorReferencia(struct Person *personas);
void mostrarPersonas(struct Person personas[]);

int main() {
	struct Person personasPorValor[MAX_PERSONS];
	struct Person personasPorReferencia[MAX_PERSONS];
	
	cargarPersonasPorValor(personasPorValor);
	cargarPersonasPorReferencia(personasPorReferencia);
	
	printf("Personas cargadas por valor:\n");
	mostrarPersonas(personasPorValor);
	
	printf("\nPersonas cargadas por referencia:\n");
	mostrarPersonas(personasPorReferencia);
	
	return 0;
}

void cargarPersonasPorValor(struct Person personas[]) {
	struct Person p1 = {"Lopez", "Juan", 25, 1.75};
	struct Person p2 = {"Gomez", "Maria", 32, 1.68};
	struct Person p3 = {"Martinez", "Carlos", 19, 1.82};
	
	personas[0] = p1;
	personas[1] = p2;
	personas[2] = p3;
}

void cargarPersonasPorReferencia(struct Person *personas) {
	struct Person p1 = {"Sanchez", "Ana", 28, 1.60};
	struct Person p2 = {"Rodriguez", "Luis", 40, 1.78};
	struct Person p3 = {"Fernandez", "Laura", 22, 1.70};
	
	personas[0] = p1;
	personas[1] = p2;
	personas[2] = p3;
}

void mostrarPersonas(struct Person personas[]) {
	for (int i = 0; i < MAX_PERSONS; i++) {
		printf("Persona %d:\n", i + 1);
		printf("Apellido: %s\n", personas[i].apellido);
		printf("Nombre: %s\n", personas[i].nombre);
		printf("Edad: %d\n", personas[i].edad);
		printf("Altura: %.2f\n\n", personas[i].altura);
	}
}

