
#include <TinyGPS.h>
#include <VirtualWire.h>
TinyGPS gps;
boolean validGPS = false;

struct {
  float flat1;
  float flon1;
}DATA;

void setup()
{
  
  Serial1.begin(9600); 
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_tx_pin(12);
}

float flat,flon;

void loop()
{
  if (Serial1.available())
  {
    validGPS = gps.encode(Serial1.read());
  }
  if (validGPS)
  {
    gps.f_get_position(&flat, &flon);
    DATA.flat1 = flat;
    DATA.flon1 = flon;
    Serial.println(DATA.flat1);
    Serial.println(DATA.flon1);
    
    vw_send((uint8_t*)&DATA , sizeof(DATA));
    vw_wait_tx();
  }
}
