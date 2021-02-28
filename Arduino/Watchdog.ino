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
