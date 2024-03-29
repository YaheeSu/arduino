int16_t V;
int16_t R;
int16_t T;
int16_t Temp;

void setup(){
  Serial.begin(9600);
}

void loop() {
  V = ReadVoltage(A0); //accuracy improved
}

double ReadVoltage(byte pin){
  double reading = analogRead(pin); // Reference voltage is 3v3 so maximum reading is 3v3 = 4095 in range 0 to 4095
  if(reading < 1 || reading > 4095) return 0;
  // return -0.000000000009824 * pow(reading,3) + 0.000000016557283 * pow(reading,2) + 0.000854596860691 * reading + 0.065440348345433;
  return -0.000000000000016 * pow(reading,4) + 0.000000000118171 * pow(reading,3)- 0.000000301211691 * pow(reading,2)+ 0.001109019271794 * reading + 0.034143524634089;

  int16_t R0 = 8805;
  int16_t B  = 3950;

  V = ReadVoltage(A0); // ADC accuracy improved for ESP32
  R = 9990 * V / (5 - V); // assuming 9990 is the measured resistance of 10K resistor by a multi-meter.
  T = 1 / (1/T0 + (log(R)-log(R0)) / B ); // R0=8805 measured in room tempature at 28 celsius degree.
  Temp = T - 273.15;

Serial.println(Temp);
} // Added an improved polynomial, use either, comment out as required
