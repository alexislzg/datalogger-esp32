#ifndef ACTUATORS_H
#define ACTUATORS_H
#include "Config.h"
#include <WiFi.h>

/**
 /          TareaActuador
 /          Controlador físico del sistema (Buzzer y LEDs de estado).
 /          Reacciona instantáneamente a los estímulos del sensor y 
 /          supervisa la conectividad de red de forma pasiva.
 */
class TareaActuador {
  public:
    void inicializar() {
      pinMode(PIN_BUZZER, OUTPUT);
      pinMode(PIN_LED_R, OUTPUT);
      pinMode(PIN_LED_G, OUTPUT);
    }

    /**
     /      Evalúa las condiciones de activación y modifica las salidas.
     /      Registra la hora exacta de los eventos para auditoría en JSON.
     */
    void actualizar() {
      int estadoInmediato = digitalRead(PIN_TOUCH);
      
      // Lógica de alerta sonora instantánea
      if (estadoInmediato == HIGH && !actuadorActivo) {
        actuadorActivo = true;
        horaActivacion = horaActual;
        digitalWrite(PIN_BUZZER, HIGH);
      } else if (estadoInmediato == LOW && actuadorActivo) {
        actuadorActivo = false;
        horaDesactivacion = horaActual;
        digitalWrite(PIN_BUZZER, LOW);
      }

      // Lógica de semáforo de conectividad (Verde = OK, Rojo = Desconectado)
      if (WiFi.status() == WL_CONNECTED && client.connected()) {
        digitalWrite(PIN_LED_G, HIGH);
        digitalWrite(PIN_LED_R, LOW);
      } else {
        digitalWrite(PIN_LED_G, LOW);
        digitalWrite(PIN_LED_R, HIGH);
      }
    }
};
#endif