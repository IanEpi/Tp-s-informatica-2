#include <stdio.h>

void contar_cadena (char *puntero){
	int cantidad = 1;
	int digitos = 0; 
	int simbolos = 0;
	while (*puntero != '\0'){
		if (*puntero == ' '){
			cantidad++;
		}
		if (*puntero >= '0' && *puntero <= '9' ){
			digitos++;
		}
		if (!((*puntero <= 'z' && *puntero>='a')||(*puntero <= 'Z' && *puntero>='A')||(*puntero >= '0' && *puntero <= '9' ))){
			simbolos++;
		}
		*puntero++;//cambio de lugar
	}
	printf("\n---------------------------------------------\n");
	printf("\nCantidad de palabras: %d", cantidad);
	printf("-\n");
	printf("\n---------------------------------------------\n");
	printf("\nDígitos: %d", digitos);
	printf("-\n");
	printf("\n---------------------------------------------\n");
	printf("\nCaracteres especiales o simbolos: %d", simbolos);
	printf("-\n");
	printf("\n---------------------------------------------\n");
}
	int main(int argc, char *argv[]) {
		char cadena1[100];
		printf("\nIngrese una cadena: ");
		gets(cadena1);
		contar_cadena(cadena1);
		return 0;
	}
	
