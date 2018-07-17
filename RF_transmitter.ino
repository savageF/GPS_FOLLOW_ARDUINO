
#include <SoftwareSerial.h>
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
#include <TinyGPS.h>

// D12 <-- CONNECTING 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
// rx , tx .. follow order
SoftwareSerial ss(15,14);
TinyGPS gps;


void setup()
{
    // Initialize ASK Object
    ss.begin(9600);
    rf_driver.init();
    Serial.begin(9600);
}
 
void loop()
{
    float latitude, longitude;
    gps.f_get_position(&latitude, &longitude);
    //const char *msg = "Welcome to the Workshop!";
    //rf_driver.send((uint8_t *)msg, strlen(msg));
    //rf_driver.waitPacketSent();

    // Parsing 
    String str_latitude = String(latitude);
    String str_longitude = String(longitude);
    String str_out = str_latitude + " // " + str_longitude ;
    static char *msg = str_out.c_str();

    rf_driver.send( (uint8_t *)msg , strlen(msg) );
    rf_driver.waitPacketSent();

    


    delay(1000);
}

