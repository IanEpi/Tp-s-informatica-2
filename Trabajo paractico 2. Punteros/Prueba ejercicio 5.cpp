#include <iostream>
#include <cstring>

using namespace std;

const int N = 5; // número de cadenas
const int M = 10; // longitud de cada cadena

int count_special_chars(char str[]) {
	int count = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (!isalnum(str[i])) {
			count++;
		}
	}
	return count;
}

int main() {
	char matrix[N][M];
	
	// ingresar las cadenas
	for (int i = 0; i < N; i++) {
		cout << "Ingrese la cadena " << i+1 << ": ";
		cin >> matrix[i];
	}
	
	// mostrar las longitudes y las cadenas más corta y larga
	int min_len = M;
	int max_len = 0;
	char* min_str = NULL;
	char* max_str = NULL;
	for (int i = 0; i < N; i++) {
		int len = strlen(matrix[i]);
		cout << "La cadena " << i+1 << " tiene longitud " << len << endl;
		if (len < min_len) {
			min_len = len;
			min_str = matrix[i];
		}
		if (len > max_len) {
			max_len = len;
			max_str = matrix[i];
		}
	}
	cout << "La cadena más corta es: " << min_str << endl;
	cout << "La cadena más larga es: " << max_str << endl;
	
	// mostrar la cadena con la mayor cantidad de caracteres especiales
	int max_special_chars = 0;
	char* max_special_chars_str = NULL;
	for (int i = 0; i < N; i++) {
		int special_chars_count = count_special_chars(matrix[i]);
		if (special_chars_count > max_special_chars) {
			max_special_chars = special_chars_count;
			max_special_chars_str = matrix[i];
		}
	}
	cout << "La cadena con la mayor cantidad de caracteres especiales es: " << max_special_chars_str << endl;
	
	return 0;
}
