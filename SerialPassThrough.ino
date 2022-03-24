void setup() {
  Serial.begin(9600); 
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    Serial.write(Serial.read());
  }

   if(Serial.available()){
      Serial.write(Serial.read());
  }
}
