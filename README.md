# Arduino-Watchdog

```c++
#include <avr/wdt.h>
 
void setup()
{
  wdt_disable(); 
  wdt_enable(WDTO_4S);
                       
}
 
void loop()
{
  wdt_reset(); // Actualizar el watchdog para que no produzca un reinicio
}
```


## Codigo que demuestra lo que sucede que si el timer watchdog pasan mas de 4 segundos se reinicia
```c++
#include <avr/wdt.h> // Incluir la librería que contiene el watchdog (wdt.h)

void setup()
{
  wdt_disable(); // Desactivar el watchdog mientras se configura, para que no se resetee
  wdt_enable(WDTO_4S); // Configurar watchdog a cuatro segundos
  Serial.begin(9600);
  Serial.println("En ciclo setup");
  delay(1000);

}

void loop()
{
  wdt_reset(); // Actualizar el watchdog para que no produzca un reinicio
  Serial.println("En ciclo loop");
}
```
