char message = 'A';
#define touch_sensor 7

void setup(){
  pinMode(touch_sensor,INPUT);
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("UART");
}

void loop(){
  if(digitalRead(touch_sensor) == 1){
  Serial1.println(message);
  Serial.println(message);
  message++;
  }
  if(message > 'z'){
    message = 'A';
  }  
  delay(1000);
}