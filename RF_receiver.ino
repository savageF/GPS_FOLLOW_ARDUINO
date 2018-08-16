//struct receive
#include <Distance.h>
#include <VirtualWire.h>
#include <TinyGPS.h>

struct DATA{
 float X;
 float Y;
};

struct DATA *DataIn;
TinyGPS gps;
boolean validGPS = false;
void setup()
{
  Serial2.begin(9600);
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_rx_pin(11);
  vw_rx_start();
}

float flat , flon;

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) 
  {
       if (Serial2.available())
       {
          validGPS = gps.encode(Serial2.read());
       }
       if (validGPS)
       {
          gps.f_get_position(&flat, &flon);
       }
    DataIn = (struct DATA*)buf;
    Serial.println();
    Serial.println("위도 와 경도");
    Serial.println(DataIn->X);
    Serial.println(DataIn->Y);

    Serial.println("위도 와 경도2");
    Serial.println(flat);
    Serial.println(flon);

    Serial.println();
    Serial.println("대상 까지의 거리");
    Serial.print(get_dist((double)flat,(double)flon,(double)DataIn->X , (double)DataIn->Y) * 1000);
    Serial.print(" Meter");

    Serial.println();
    Serial.println("대상에 대한 각");
    Serial.print(get_bear((double)flat,(double)flon,(double)DataIn->X , (double)DataIn->Y) - 360);
    Serial.print(" deg");
    Serial.println();
   
    delay(500);
  }
}
