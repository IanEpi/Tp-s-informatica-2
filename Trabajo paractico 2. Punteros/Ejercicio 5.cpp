#include <stdio.h>
const M=100;

void contar_cadena (char *puntero){
		int cantidad = 1;
		int digitos = 0; 
		int simbolos = 0;
		while (*puntero != '\0'){
			if (*puntero >= '0' && *puntero <= '9' ){
				digitos++;
			}
			if (!((*puntero <= 'z' && *puntero>='a')||(*puntero <= 'Z' && *puntero>='A')||(*puntero >= '0' && *puntero <= '9' ))){
				simbolos++;
			}
			if (*puntero == ' '){
				cantidad++;
			}
			*puntero++;
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
		int i;
		char cadena1[N][M];
			printf("Ingresar cantidad de caracteres para almacenar: ");
			gets(N);
		for(i=0; i<N; i++){
			printf("\nIngrese una cadena: ");
			gets(cadena1[i]);
			contar_cadena(cadena1);
			}
			return 0;
		}
	
	

