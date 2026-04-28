//semaforo duplo com 6 leds

#define Vermelho1 13
#define Amarelo1 12
#define Verde1 11

#define Vermelho2 4
#define Amarelo2 3
#define Verde2 2


void setup() {
  pinMode(Vermelho1, OUTPUT);
  pinMode(Amarelo1, OUTPUT);
  pinMode(Verde1, OUTPUT);

  pinMode(Vermelho2, OUTPUT);
  pinMode(Amarelo2, OUTPUT);
  pinMode(Verde2, OUTPUT);
}

void loop() {
  digitalWrite(Vermelho1, HIGH);
  digitalWrite(Vermelho2, HIGH);
  delay(1000);
  digitalWrite(Vermelho1,LOW);
  digitalWrite(Verde1,HIGH);
  delay(3000);
  digitalWrite(Verde1,LOW);
  digitalWrite(Amarelo1,HIGH);
  delay(1000);
  digitalWrite(Amarelo1,LOW);
  digitalWrite(Vermelho1,HIGH);
  delay(1000);
  digitalWrite(Vermelho2,LOW);
  digitalWrite(Verde2,HIGH);
  delay(3000);
  digitalWrite(Verde2,LOW);
  digitalWrite(Amarelo2,HIGH);
  delay(1000);
  digitalWrite(Amarelo2,LOW);
  digitalWrite(Vermelho2,HIGH);
}
