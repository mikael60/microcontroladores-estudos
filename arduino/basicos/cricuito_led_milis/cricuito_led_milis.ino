//exemplo de circuito usando arduino explicando a diferença entre delay e milis
//delay é um bloqueante onde ele espera um determinado tempo para depois executar o código

#define ledv 10
#define ledver 9
#define botao 2


boolean estadoBotao = true;    //estado atual do botao
boolean estadoAntBotao = true; //estado anterior do botao
boolean estadoPisca = false;    //controla o pisca do led

unsigned long delay1 = 0; //guarda o tempo inicial do milis

void setup() {
  pinMode(ledv, OUTPUT);
  pinMode(ledver, OUTPUT);
  pinMode(botao, INPUT_PULLUP); //define o botao como pull_up
  
  digitalWrite(ledver, HIGH);
}

void loop() {

  //Le o botao
  estadoBotao = digitalRead(botao);
  //condição para ver se o botao estava apertado
  if(estadoBotao == LOW && estadoAntBotao){
      estadoPisca = !estadoPisca; //inversao do estado do pisca
  }
  estadoAntBotao = estadoBotao;

  if(estadoPisca){


    if(millis() - delay1 >= 500){
      digitalWrite(ledv, HIGH);
    }
    if(millis() - delay1 < 500){
      digitalWrite(ledv, LOW);
    }
    if(millis() - delay1 >= 1000){
      delay1 = millis();
    }
  } 
}
