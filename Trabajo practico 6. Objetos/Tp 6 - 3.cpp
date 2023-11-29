#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>

class Sensor {
private:
	std::string marca;
	std::string tipo;
	std::string unidadMedida;
	
public:
	Sensor(const std::string& marca, const std::string& tipo, const std::string& unidadMedida)
		: marca(marca), tipo(tipo), unidadMedida(unidadMedida) {}
	
	// Getters y Setters para los atributos del sensor
	std::string getMarca() const { return marca; }
	std::string getTipo() const { return tipo; }
	std::string getUnidadMedida() const { return unidadMedida; }
};

class Medicion {
private:
	std::time_t fechaHora;
	Sensor sensor;
	double valor;
	std::string comentarios;
	
public:
	Medicion(const std::time_t& fechaHora, const Sensor& sensor, double valor, const std::string& comentarios)
		: fechaHora(fechaHora), sensor(sensor), valor(valor), comentarios(comentarios) {}
	
	// Getters para los atributos de la medición
	std::time_t getFechaHora() const { return fechaHora; }
	Sensor getSensor() const { return sensor; }
	double getValor() const { return valor; }
	std::string getComentarios() const { return comentarios; }
};

class ListaMediciones {
private:
	std::vector<Medicion> mediciones;
	
public:
	// Agregar una medición a la lista
	void agregarMedicion(const Medicion& medicion) {
		mediciones.push_back(medicion);
	}
	
	// Eliminar una medición por índice
	void eliminarMedicion(int indice) {
		if (indice >= 0 && indice < mediciones.size()) {
			mediciones.erase(mediciones.begin() + indice);
		}
	}
	
	// Mostrar todas las mediciones
	void mostrarMediciones() {
		for (int i = 0; i < mediciones.size(); i++) {
			std::cout << "Medición " << i + 1 << ":" << std::endl;
			std::cout << "Fecha y Hora: " << std::ctime(&mediciones[i].getFechaHora());
			std::cout << "Marca del Sensor: " << mediciones[i].getSensor().getMarca() << std::endl;
			std::cout << "Tipo del Sensor: " << mediciones[i].getSensor().getTipo() << std::endl;
			std::cout << "Valor: " << mediciones[i].getValor() << " " << mediciones[i].getSensor().getUnidadMedida() << std::endl;
			std::cout << "Comentarios: " << mediciones[i].getComentarios() << std::endl;
		}
	}
	
	// Guardar las mediciones en un archivo
	void guardarMedicionesEnArchivo(const std::string& nombreArchivo) {
		std::ofstream archivo(nombreArchivo);
		if (archivo.is_open()) {
			for (const Medicion& medicion : mediciones) {
				archivo << "Fecha y Hora: " << std::ctime(&medicion.getFechaHora());
				archivo << "Marca del Sensor: " << medicion.getSensor().getMarca() << std::endl;
				archivo << "Tipo del Sensor: " << medicion.getSensor().getTipo() << std::endl;
				archivo << "Valor: " << medicion.getValor() << " " << medicion.getSensor().getUnidadMedida() << std::endl;
				archivo << "Comentarios: " << medicion.getComentarios() << std::endl;
				archivo << std::endl;
			}
			archivo.close();
			std::cout << "Mediciones guardadas en " << nombreArchivo << std::endl;
		} else {
			std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
		}
	}
};

int main() {
	Sensor sensor1("Sensor1", "Tipo1", "Unidad1");
	Sensor sensor2("Sensor2", "Tipo2", "Unidad2");
	
	ListaMediciones lista;
	
	// Crear algunas mediciones de ejemplo y agregarlas a la lista
	std::time_t ahora = std::time(0);
	Medicion medicion1(ahora, sensor1, 25.5, "Medición 1");
	lista.agregarMedicion(medicion1);
	
	ahora = std::time(0);
	Medicion medicion2(ahora, sensor2, 30.2, "Medición 2");
	lista.agregarMedicion(medicion2);
	
	// Mostrar las mediciones
	std::cout << "Mediciones registradas:" << std::endl;
	lista.mostrarMediciones();
	
	// Guardar las mediciones en un archivo
	lista.guardarMedicionesEnArchivo("mediciones.txt");
	
	return 0;
}
