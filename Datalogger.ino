/**
 /            Datalogger.ino
 /            Sistema Datalogger IoT modular con ESP32.
 /            Integra sensores, actuadores, almacenamiento local (MicroSD) 
 /            y comunicación remota (MQTT) utilizando multitarea cooperativa.
 / 
 /                   Carlos Alexis López Jiménez  7A Telematica
 
 */

#include <Wire.h>
#include "Config.h"
#include "Tasks.h"
#include "RTC.h"
#include "JSONS.h"
#include "Sensors.h"
#include "Actuators.h"
#include "MicroSD.h"
#include "MQTT.h"
#include "Display.h"

/** 
 /       Inicialización en memoria de las variables globales de estado. 
 */
String fechaActual = "00-00-0000";
String horaActual = "00:00:00";
int valorSensor = 0;
bool actuadorActivo = false;
String horaActivacion = "N/A";
String horaDesactivacion = "N/A";

/** 
 /        Instancias globales de los módulos del sistema. 
 */
TareaSensor tSensor;
TareaActuador tActuador;
TareaSD tSD;
TareaMQTT tMQTT;
TareaPantalla tPantalla;

/**
 /        Configuración inicial del hardware y periféricos.
 /        Inicializa buses de comunicación (Serial, I2C) y manda llamar 
 /        a los métodos de arranque de cada módulo independiente.
 */
void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  inicializarRTC();
  tSensor.inicializar();
  tActuador.inicializar();
  tSD.inicializar();
  tMQTT.inicializar();
  tPantalla.inicializar();
}

/**
 /         Ciclo infinito de ejecución (Super Loop).
 /         Orquesta la ejecución concurrente de todas las tareas del sistema 
 /         sin utilizar retardos bloqueantes, garantizando tiempo real.
 */
void loop() {
  actualizarReloj();
  tSensor.actualizar();
  tActuador.actualizar();
  tPantalla.actualizar();
  tSD.guardarDatos();
  tMQTT.publicar();
}