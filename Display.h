#ifndef DISPLAY_H
#define DISPLAY_H
#include <LiquidCrystal_I2C.h>
#include "Config.h"

// Instancia de la pantalla LCD utilizando dirección I2C estándar
LiquidCrystal_I2C lcd(0x27, 16, 2);

/**
 /          TareaPantalla
 /          Módulo de interfaz humano-máquina (HMI).
 /          Muestra en tiempo real los datos consolidados del sistema en una 
 /          matriz LCD de 16x2 caracteres.
 */
class TareaPantalla {
  public:
    void inicializar() {
      lcd.init();
      lcd.backlight();
    }

    /**
     /        Formatea e inyecta los datos en los segmentos de la LCD.
     /        Optimiza el espacio de 16 caracteres para mostrar Fecha, Hora,
     /        estado numérico del sensor y etiqueta de estado del actuador.
     */
    void actualizar() {
      lcd.setCursor(0, 0);
      lcd.print(fechaActual.substring(0, 5) + " " + horaActual);
      
      lcd.setCursor(0, 1);
      lcd.print("S:" + String(valorSensor) + " ");
      if (actuadorActivo) {
        lcd.print("B:ON       ");
      } else {
        lcd.print("B:OFF      ");
      }
    }
};
#endif