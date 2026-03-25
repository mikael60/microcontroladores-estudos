//circuito usando o resistor LDR para medir uma escala de luminosidade com arrays de LED'S

#define entrada_analog 4  //pino do esp que le o LDR
int pinos[8] = {23,22,21,19,18,17,16,2};
int i;
int minimo = 900;         // Leitura real no escuro
int maximo = 4000;        // Leitura real na luz forte
int valorLDR;
int luminosidade;

void setup() {
  for(i=0;i<=7;i++){
    pinMode(pinos[i],OUTPUT);
  }
  Serial.begin(9600);     // Inicia a comunicação com o PC
}

void loop() {
  valorLDR = analogRead(entrada_analog);

  // Trava a leitura entre 900 e 4000 para não quebrar a memória do array
  valorLDR = constrain(valorLDR, minimo, maximo);

  // Espreme a escala grande (900-4000) na escala pequena (0-8 LEDs)
  luminosidade = map(valorLDR, minimo, maximo, 0, 8);
  
  for(i=0;i<=7;i++){
    if(i < luminosidade){
      digitalWrite(pinos[i], HIGH);
    }else{
      digitalWrite(pinos[i], LOW);
    }
  }
  Serial.print("Leitura LDR: ");
  Serial.print(valorLDR);
  Serial.print(" | LEDs acesos: ");
  Serial.println(luminosidade);
  
  delay(200);
}