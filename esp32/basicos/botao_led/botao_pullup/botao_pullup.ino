//// leitura de botão utilizando resistor interno do microcontrolador
// quando pressionado → estado LOW
// quando solto → estado HIGH

#define led_verde 23
#define led_vermelho 22
#define botao 21

void setup() {
  pinMode(led_verde,OUTPUT);  
  pinMode(led_vermelho,OUTPUT);
  pinMode(botao,INPUT_PULLUP);
}

void loop() {
      int estado_botao;
    estado_botao = digitalRead(botao);

    digitalWrite(led_verde,estado_botao);
    digitalWrite(led_vermelho,!estado_botao);
}
