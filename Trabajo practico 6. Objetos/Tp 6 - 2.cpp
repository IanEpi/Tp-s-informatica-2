#include <iostream>
#include <ctime>

class Cronometro {
private:
	clock_t inicio;
	clock_t fin;
	bool detenido;
	
public:
	Cronometro() : detenido(false) {}
	
	// Iniciar el temporizador
	void iniciar() {
		inicio = clock();
		detenido = false;
	}
	
	// Detener el temporizador
	void detener() {
		fin = clock();
		detenido = true;
	}
	
	// Regresar la cantidad de tiempo transcurrido en milisegundos
	double tiempoTranscurridoMs() const {
		if (detenido) {
			return static_cast<double>(fin - inicio) * 1000.0 / CLOCKS_PER_SEC;
		} else {
			return 0.0;
		}
	}
	
	// Formato hh:mm:ss
	std::string tiempoTranscurridoHMS() const {
		if (detenido) {
			double tiempoMs = tiempoTranscurridoMs();
			int horas = static_cast<int>(tiempoMs / 3600000);
			int minutos = static_cast<int>((tiempoMs - horas * 3600000) / 60000);
			int segundos = static_cast<int>((tiempoMs - horas * 3600000 - minutos * 60000) / 1000);
			char buffer[20];
			snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", horas, minutos, segundos);
			return std::string(buffer);
		} else {
			return "00:00:00";
		}
	}
	
	// Resetear el temporizador (volverlo a cero)
	void resetear() {
		inicio = fin = 0;
		detenido = false;
	}
	
	// Obtener el tiempo actual
	std::string obtenerTiempoActual() const {
		time_t tiempoActual;
		time(&tiempoActual);
		return ctime(&tiempoActual);
	}
	
	// Otros métodos relacionados con fechas/tiempos si es necesario
};

int main() {
	Cronometro cronometro;
	cronometro.iniciar();
	
	std::cout << "Cronómetro iniciado. Presiona Enter para detener..." << std::endl;
	std::cin.get();
	
	cronometro.detener();
	
	std::cout << "Tiempo transcurrido en milisegundos: " << cronometro.tiempoTranscurridoMs() << " ms" << std::endl;
	std::cout << "Tiempo transcurrido en formato hh:mm:ss: " << cronometro.tiempoTranscurridoHMS() << std::endl;
	
	std::cout << "Tiempo actual: " << cronometro.obtenerTiempoActual() << std::endl;
	
	cronometro.resetear();
	std::cout << "Cronómetro reseteado." << std::endl;
	
	return 0;
}
