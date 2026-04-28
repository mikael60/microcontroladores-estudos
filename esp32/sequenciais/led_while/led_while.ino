//circuito usando leds, usando a estrutura de repetição while no esp32
//enquanto nao for digitado 'P' no serial monitor, os leds continuarão o loop
 

int pinLed[9] = {23,22,21,19,18,5,4,2,26};
int Nled;
char digitado;

void setup(){
  int i;

  for(i=0;i<=8;i++){
    pinMode(pinLed[i],OUTPUT);
  }
  Serial.begin(9600);
}
void loop(){
  digitado = ' ';
  Nled = 0;


  while(digitado != 'P'){
    digitalWrite(pinLed[Nled],LOW);
    Nled++;
    if(Nled >= 8){
      Nled = 0;
    }
    digitalWrite(pinLed[Nled],HIGH);
    if(Serial.available()){
      digitado = Serial.read();
    }
    delay(50);
  }
   delay(5000);
}