# 📊 Datalogger IoT con ESP32 y Almacenamiento Local/Remoto

Sistema embebido modular desarrollado en C++ para la adquisición, registro local y transmisión de telemetría ambiental en entornos inteligentes.

## 📂 Arquitectura del Software (Módulos)

* **`Datalogger.ino`** - Archivo principal (Core) que gestiona el ciclo de vida y la máquina de estados.
* **`Sensors.h`** - Adquisición de señales de sensores conectados.
* **`Actuators.h`** - Gestión de salidas y actuadores del sistema.
* **`MicroSD.h`** - Control de escritura y almacenamiento local de datos persistentes.
* **`MQTT.h`** - Protocolo de comunicación y transmisión de telemetría en tiempo real.
* **`RTC.h`** - Sincronización horaria y marcas de tiempo (Timestamps).
* **`Display.h`** - Interfaz visual y despliegue local de métricas.
* **`Tasks.h`** - Planificación y ejecución de tareas periódicas.
* **`JSONS.h`** - Serialización y empaquetado de estructuras de datos.
* **`Config.h`** - Credenciales, pines y parámetros globales del sistema.
