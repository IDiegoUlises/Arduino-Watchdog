# Arduino Watchdog

El Watchdog o perro guardian es un timer que incorpora el arduino de forma independiente en el cual se debe actualizar el tiempo del contador en caso que no se actualize el tiempo salta el watchdog y reinicia el programa automaticamente.



```c++
#include <avr/wdt.h>
 
void setup()
{
  wdt_disable(); 
  wdt_enable(WDTO_2S); //Configurar el watchdog cada 2 segundos
                       
}
 
void loop()
{
  wdt_reset(); // Actualizar el watchdog para que no produzca un reinicio
}
```


## Codigo que demuestra lo que sucede que si el timer watchdog pasan mas de 4 segundos se reinicia
```c++
#include <avr/wdt.h> 

void setup()
{
  wdt_disable(); // Desactivar el watchdog mientras se configura
  wdt_enable(WDTO_2S); // Configurar watchdog a cuatro segundos
  Serial.begin(9600); //Inicia el puerto serial
  Serial.println("En un reinicio");
  delay(1000); 

}

void loop()
{
  wdt_reset(); // Actualizar el watchdog para que no produzca un reinicio
  Serial.println("En ciclo loop");
  delay(3000); //Este delay es para producir el reinicio
}
```
