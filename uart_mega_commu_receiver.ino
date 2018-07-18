void setup(){
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop(){
  while(Serial1.available()){
    char data = Serial1.read();
    Serial1.println(data);
    Serial.println(data);
  }  
}