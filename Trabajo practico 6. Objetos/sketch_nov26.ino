// Definición de la clase Timer
class Timer {
public:
  Timer() : running(false), startTime(0), elapsedTime(0) {}

  void start() {
    if (!running) {
      startTime = millis();
      running = true;
    }
  }

  void stop() {
    if (running) {
      elapsedTime += millis() - startTime;
      running = false;
    }
  }

  void reset() {
    elapsedTime = 0;
    if (running) {
      startTime = millis();
    }
  }

  unsigned long getElapsedTime() const {
    if (running) {
      return elapsedTime + (millis() - startTime);
    } else {
      return elapsedTime;
    }
  }

  bool isRunning() const {
    return running;
  }

private:
  bool running;
  unsigned long startTime;
  unsigned long elapsedTime;
};

// Crear una instancia de la clase Timer
Timer myTimer;

void setup() {
  // Inicialización del puerto serie
  Serial.begin(9600);
}

void loop() {
  // Si hay datos disponibles en el puerto serie
  if (Serial.available() > 0) {
    char command = Serial.read(); // Lee el carácter recibido

    // Realiza la acción correspondiente al carácter recibido
    switch (command) {
      case 'A':
        myTimer.start();
        break;
      case 'D':
        myTimer.stop();
        break;
      case 'R':
        myTimer.reset();
        break;
      default:
        break;
    }
  }

  // Realiza otras tareas en el bucle principal

  // Obtén y muestra el tiempo transcurrido en el temporizador
  if (myTimer.isRunning()) {
    Serial.println("Temporizador en ejecución. Tiempo transcurrido: " + String(myTimer.getElapsedTime()) + " ms");
  } else {
    Serial.println("Temporizador detenido. Tiempo transcurrido: " + String(myTimer.getElapsedTime()) + " ms");
  }

  delay(1000); // Espera un segundo antes de volver a verificar el puerto serie
}
