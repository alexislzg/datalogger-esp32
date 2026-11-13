#ifndef MICROSD_H
#define MICROSD_H
#include <SPI.h>
#include <SD.h>
#include "Config.h"
#include "Tasks.h"
#include "JSONS.h"

/**
 /     TareaSD
 /     Manejador del sistema de archivos local vía protocolo SPI.
 /     Almacena un registro JSON cada 10 segundos en archivos diarios.
 */
class TareaSD : public TareaTemporizada {
  public:
    TareaSD() : TareaTemporizada(10000) {} 
    
    void inicializar() {
      if (!SD.begin(PIN_SD_CS)) Serial.println("Error SD");
    }
    
    /**
     /      Construye el nombre del archivo diario y adjunta el registro.
     /      Utiliza el formato <AAAA_MM_DD>.json sin sobrescribir el historial.
     */
    void guardarDatos() {
      if (debeEjecutarse()) {
        String anio = fechaActual.substring(6, 10);
        String mes = fechaActual.substring(3, 5);
        String dia = fechaActual.substring(0, 2);
        String nombreArchivo = "/" + anio + "_" + mes + "_" + dia + ".json";
        
        File dataFile = SD.open(nombreArchivo, FILE_APPEND);
        if (dataFile) {
          String datos = generarJSON();
          dataFile.println(datos);
          dataFile.close();
          Serial.println("Guardado SD: " + nombreArchivo);
        }
      }
    }
};
#endif