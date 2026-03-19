//ex de cicuitos com leds, usando o loop for no esp32

int pinLed[9] = {23,22,21,19,18,17,2,4,5};
int Ledn;

void setup() {
  int i;
  for(i = 0;i<= 8;i++){
    pinMode(pinLed[i], OUTPUT);
  }
}

void loop() {
  for(Ledn = 0;Ledn<= 8;Ledn++){
    digitalWrite(pinLed[Ledn], HIGH);
    delay(200);
  }
  for(Ledn = 8;Ledn>=0;Ledn--){
    digitalWrite(pinLed[Ledn], LOW);
    delay(100);
  }

}
