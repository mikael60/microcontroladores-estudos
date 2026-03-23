//circuito led usando um resistor LDR, controlando a iluminação dos leds no esp32

int pinos[9] = {23,22,21,19,18,5,4,2,26};
int i;

float minimo = 0;
float maximo = 4095;
float valorLDR;
float luminosidade;

void setup() {
  for(i = 0; i < 9; i++){
    pinMode(pinos[i], OUTPUT);
  }
  
  pinMode(35, INPUT);
}

void loop() {
  valorLDR = analogRead(35);

  // Normaliza o valor do LDR para uma escala de 0 a 10
  luminosidade = ((valorLDR - minimo) / (maximo - minimo)) * 10;

  // Inverte (quanto mais escuro, mais LEDs acesos)
  luminosidade = (luminosidade - 10) * -1;

  // Garante que fique entre 0 e 9
  if(luminosidade < 0) luminosidade = 0;
  if(luminosidade > 9) luminosidade = 9;

  for(i = 0; i < 9; i++){
    if(i < luminosidade){
      digitalWrite(pinos[i], HIGH);
    } else {
      digitalWrite(pinos[i], LOW);
    }
  }

  delay(500); // delay geral
}