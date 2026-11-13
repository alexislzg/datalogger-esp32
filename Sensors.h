#ifndef SENSORS_H
#define SENSORS_H
#include "Config.h"
#include "Tasks.h"

/**
 /          TareaSensor
 /          Gestiona el muestreo digital del sensor Touch.
 /          Hereda de TareaTemporizada para garantizar lecturas 
 /          estrictas cada 5 segundos de forma continua.
 */
class TareaSensor : public TareaTemporizada {
  public:
    TareaSensor() : TareaTemporizada(5000) {} 
    
    /**
     /        Configura el pin del sensor. Se usa PULLDOWN para estabilizar
     /        la lectura en el entorno de simulación virtual.
     */
    void inicializar() { 
      pinMode(PIN_TOUCH, INPUT_PULLDOWN); 
    }
    
    /**
     /       Actualiza la variable global con la lectura actual.
     */
    void actualizar() {
      if (debeEjecutarse()) {
        valorSensor = digitalRead(PIN_TOUCH);
        Serial.println("Sensor (5s): " + String(valorSensor));
      }
    }
};
#endif