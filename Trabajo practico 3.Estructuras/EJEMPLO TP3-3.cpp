#include <iostream>
#include <string>
#include <vector>

using namespace std;

	
// Definición de estructuras

struct Sensor {
	string marca;
	string tipo;
	string unidadMedida;
};

struct Medicion {
	int fecha;
	string hora;
	Sensor sensor;
	double valor;
	string comentarios;
};

// Variables globales

vector<Medicion> baseDeDatos;

// Funciones

void agregarMedicion() {
	Medicion nuevaMedicion;
	
	cout << "Fecha (AAAAMMDD): ";
	cin >> nuevaMedicion.fecha;
	
	cout << "Hora (HH:MM:SS): ";
	cin.ignore();
	getline(cin, nuevaMedicion.hora);
	
	cout << "Marca del sensor: ";
	getline(cin, nuevaMedicion.sensor.marca);
	
	cout << "Tipo del sensor: ";
	getline(cin, nuevaMedicion.sensor.tipo);
	
	cout << "Unidad de medida: ";
	getline(cin, nuevaMedicion.sensor.unidadMedida);
	
	cout << "Valor medido: ";
	cin >> nuevaMedicion.valor;
	
	cout << "Comentarios: ";
	cin.ignore();
	getline(cin, nuevaMedicion.comentarios);
	
	baseDeDatos.push_back(nuevaMedicion);
	
	cout << "Medición agregada correctamente." << endl;
}

void eliminarMediciones() {
	int fecha;
	cout << "Ingrese la fecha (AAAAMMDD) de las mediciones a eliminar: ";
	cin >> fecha;
	
	int eliminadas = 0;
	
	for (auto it = baseDeDatos.begin(); it != baseDeDatos.end(); ) {
		if (it->fecha == fecha) {
			it = baseDeDatos.erase(it);
			eliminadas++;
		} else {
			++it;
		}
	}
	
	cout << eliminadas << " mediciones eliminadas." << endl;
}

void modificarMedicion() {
	int fecha;
	cout << "Ingrese la fecha (AAAAMMDD) de la medición a modificar: ";
	cin >> fecha;
	
	bool encontrada = false;
	
	for (auto& medicion : baseDeDatos) {
		if (medicion.fecha == fecha) {
			encontrada = true;
			
			cout << "Fecha (AAAAMMDD): ";
			cin >> medicion.fecha;
			
			cout << "Hora (HH:MM:SS): ";
			cin.ignore();
			getline(cin, medicion.hora);
			
			cout << "Marca del sensor: ";
			getline(cin, medicion.sensor.marca);
			
			cout << "Tipo del sensor: ";
			getline(cin, medicion.sensor.tipo);
			
			cout << "Unidad de medida: ";
			getline(cin, medicion.sensor.unidadMedida);
			
			cout << "Valor medido: ";
			cin >> medicion.valor;
			
			cout << "Comentarios: ";
			cin.ignore();
			getline(cin, medicion.comentarios);
			
			cout << "Medición modificada correctamente." << endl;
			break;
		}
	}
	
	if (!encontrada) {
		cout << "No se encontró ninguna medición con la fecha especificada." << endl;
	}
}

void buscarPorFecha() {
	int fecha;
	cout  <<
		
