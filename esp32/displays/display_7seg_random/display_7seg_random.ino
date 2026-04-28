//ex de circuito usando um display de 7 segmentos no esp32 usando a função random


#define botao 32
#define pinA 23
#define pinB 22
#define pinC 21
#define pinD 19
#define pinE 18
#define pinF 5
#define pinG 33
#define pinPD 15

int numero = 10;
boolean botaoAtu = false;  // estado atual do botao
boolean botaoAnt = false;  //estado anterior do botao

void setup() {
  pinMode(botao,INPUT_PULLUP);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinPD, OUTPUT);
  
  //função para gerar uma lista de numeros aleatorios dentro de um intervalo de 0 a 1023 da entrada analogica
  randomSeed(analogRead(35));
}

void loop() {
  //inversao da logica devido ao pulldown
  botaoAtu = !digitalRead(botao);

  //verifica se o botao estava pressionado ou nao
  if(botaoAtu && !botaoAnt){
      numero = random(10);    //função para gerar numeros aleatorios dentro de um intervalo definido
  }
  botaoAnt = botaoAtu;        // o estado do botao atual passa a ser o anterior

  switch(numero){
    case 0:
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
    digitalWrite(pinPD, LOW);
    break;

    case 1:
    digitalWrite(pinA,LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinPD, LOW);
    break;

    case 2:
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinPD, LOW);
    break;

    case 3:
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinPD, LOW);
    break;

    case 4:
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinPD, LOW);
    break;

    case 5:
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinPD, LOW);
    break;


    case 6:
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinPD, LOW);
    break;

    case 7:
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinPD, LOW);
    break;

    case 8:
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB,HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinPD, LOW);
    break;

    case 9:
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    digitalWrite(pinPD, LOW);
    break;

    case 10:
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
    digitalWrite(pinPD, HIGH);
    
    default:
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinPD, HIGH);
    break;
    
  }
}

