#ifndef RTC_H
#define RTC_H
#include <RTClib.h>
#include "Config.h"

RTC_DS1307 rtc;

/**
/     Inicializa el módulo reloj en tiempo real (DS1307) por I2C.
/     Si el módulo pierde energía o no está configurado, toma la 
/     fecha y hora de la compilación automáticamente.
*/
void inicializarRTC() {
  if (!rtc.begin() || !rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

/**
/     Extrae la información temporal del módulo físico.
/     Convierte los datos del RTC a formato String (DD-MM-YYYY y hh:mm:ss) 
/     para su inyección en la estructura de telemetría global.
*/
void actualizarReloj() {
  DateTime now = rtc.now();
  char bufF[] = "DD-MM-YYYY";
  char bufH[] = "hh:mm:ss";
  fechaActual = now.toString(bufF);
  horaActual = now.toString(bufH);
}
#endif