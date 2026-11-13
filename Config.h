#ifndef CONFIG_H
#define CONFIG_H
#include <Arduino.h>
#include <PubSubClient.h>

/*
/     Asignación de pines físicos para el ESP32 NodeMCU.
/     Se utilizan pines compatibles con I2C, SPI y soporte capacitivo.
*/

#define PIN_TOUCH 4
#define PIN_BUZZER 15
#define PIN_SD_CS 5
#define PIN_LED_R 12
#define PIN_LED_G 13

/**
/     Variables de estado global compartidas entre módulos.
/     El uso de 'extern' permite que cualquier archivo que incluya 
/     esta cabecera pueda leer y modificar el estado del sistema.
*/
extern String fechaActual;
extern String horaActual;
extern int valorSensor;
extern bool actuadorActivo;
extern String horaActivacion;
extern String horaDesactivacion;
extern PubSubClient client;

#endif