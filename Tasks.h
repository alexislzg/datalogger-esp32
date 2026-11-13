#ifndef TASKS_H
#define TASKS_H
#include <Arduino.h>

/**
/  TareaTemporizada
/  Clase base para la gestión de multitarea cooperativa.
/  Sustituye la función bloqueante delay() mediante el cálculo de 
/  diferenciales de tiempo con millis(), cumpliendo los requisitos 
/  del datalogger IoT.
*/
class TareaTemporizada {
  protected:
    unsigned long tiempoAnterior = 0;
    unsigned long intervalo;

  public:
    /**
    /    Constructor de la clase base.
    /    _intervalo Tiempo en milisegundos que debe transcurrir entre ejecuciones.
    */
    TareaTemporizada(unsigned long _intervalo) : intervalo(_intervalo) {}

    /**
    /    Verifica si el intervalo de tiempo ha transcurrido.
    /    return true si es momento de ejecutar la tarea, false en caso contrario.
    */
    bool debeEjecutarse() {
      if (millis() - tiempoAnterior >= intervalo) {
        tiempoAnterior = millis();
        return true;
      }
      return false;
    }
};
#endif