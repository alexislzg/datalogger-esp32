#ifndef MQTT_H
#define MQTT_H
#include <WiFi.h>
#include "Config.h"
#include "Tasks.h"
#include "JSONS.h"

// Credenciales estáticas de red y broker
const char* ssid = "Honor 200";
const char* password = "Laui361q";
const char* mqtt_server = "broker.hivemq.com";
const char* topico_mqtt = "20206826_Alexis"; 

WiFiClient espClient;
PubSubClient client(espClient);

/**
 /       TareaMQTT
 /       Administra el stack de red y el protocolo de telemetría.
 /       Publica el paquete de datos estructurado hacia el broker externo.
 */
class TareaMQTT : public TareaTemporizada {
  public:
    TareaMQTT() : TareaTemporizada(10000) {}
    
    void inicializar() {
      WiFi.begin(ssid, password);
      client.setServer(mqtt_server, 1883);
    }
    
    /**
    /     Supervisa el estado del socket y restablece conexiones caídas.
     */
    void reconectar() {
      if (!client.connected() && WiFi.status() == WL_CONNECTED) {
        client.connect("ESP32_20206826_Alexis");
      }
    }
    
    /**
     /      Ejecuta la transmisión de datos hacia la nube cada 10 segundos.
     */
    void publicar() {
      reconectar();
      client.loop();
      if (debeEjecutarse() && client.connected()) {
        String mensaje = generarJSON();
        client.publish(topico_mqtt, mensaje.c_str());
        Serial.println("MQTT: " + mensaje);
      }
    }
};
#endif