#ifndef JSONS_H
#define JSONS_H

#include "Config.h"
#include <ArduinoJson.h> 

/**
 /          JSON_Factory (Implementación funcional)
 /          Motor de empaquetado y estructuración de datos.
 /          Utiliza la librería ArduinoJson para crear un documento dinámico 
 /          que previene la fragmentación de memoria (heap) en el ESP32.
 */

/**
 /          Genera el payload de telemetría en formato JSON.
 /          Estructura la fecha, hora, valor del sensor y anida el estado 
 /          del actuador junto con su marca de tiempo exacta de activación.
 /          String serializado listo para almacenamiento SD o transmisión MQTT.
 */
String generarJSON() {
  DynamicJsonDocument doc(1024);
  String salidaJSON = "";

  doc["fecha"] = fechaActual;
  doc["hora"] = horaActual;
  doc["sensor"] = valorSensor;

  JsonObject actuador = doc.createNestedObject("actuador");
  
  if (actuadorActivo) {
    actuador["estado"] = "activado";
    actuador["hora_accion"] = horaActivacion;
  } else {
    actuador["estado"] = "desactivado";
    actuador["hora_accion"] = horaDesactivacion;
  }

  serializeJson(doc, salidaJSON);
  return salidaJSON;
}
#endif