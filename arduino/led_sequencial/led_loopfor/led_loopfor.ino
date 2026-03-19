//ex de circuito com leds usando o loop for com arrays


int pinLed[9] = {12,11,10,9,8,7,6,5,4};
int nLed;

void setup() {
int i;

  for(i = 0;i <= 8;i++){
    pinMode(pinLed[i], OUTPUT);
  }

}

void loop() {
  for(nLed = 0;nLed <= 8; nLed++){
    digitalWrite(pinLed[nLed], HIGH);
    delay(200);
  }
  for(nLed = 8;nLed >= 0; nLed--){
    digitalWrite(pinLed[nLed], LOW);
    delay(200);
  }
}
