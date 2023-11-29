
#include <stdio.h>
int tamano (char *palabra){
	int x=0;
	while(*palabra != '\0'){
		*palabra++;
		x++;
	}
	return x;
}
	void concatenar (int i, char *palabra1, char *palabra2){
		char cadena3[201];
		int j=0;
		while(*palabra1 != '\0'){
			cadena3[j] = *palabra1;
			*palabra1++;
			j++;
		}
		j=i;
		cadena3[j]=' ';
		while(*palabra2 != '\0'){
			j++;
			cadena3[j] = *palabra2;
			*palabra2++;
		}
		cadena3[j+1]='\0';
		printf("\nLa cadena es: \"%s\"",cadena3);
	}
		int main(int argc, char *argv[]) {
			char cadena1[100], cadena2[100];
			int lon;
			printf("\nIngrese una cadena: ");
			gets(cadena1);
			printf("\nIngrese otra cadena: ");
			gets(cadena2);
			printf("%d", *palabra);
			lon = tamano(cadena1);
			concatenar (lon, cadena1, cadena2);
			return 0;
		}
		
