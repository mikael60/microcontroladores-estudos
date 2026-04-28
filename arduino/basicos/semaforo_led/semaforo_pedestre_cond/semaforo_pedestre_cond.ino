//ex de circuito com semaforo de carro e pedestre usando variaveis condicionais

#define led_vermelho1 10
#define led_amarelo1 9
#define led_verde1 8
#define botao 7
#define led_vermelho2 4
#define led_verde2 3

int faseSemaforo;     // guarda a fase atual do semáforo
int estadobotao;       // leitura atual do botão
int estadoanteriorbotao;   // leitura atual do botão
int tempopisca;         // contador para controlar o pisca
int estadopisca;        // estado atual do LED que vai piscar

void setup() {
  pinMode(led_vermelho1, OUTPUT);
  pinMode(led_amarelo1, OUTPUT);
  pinMode(led_verde1, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(led_vermelho2, OUTPUT);
  pinMode(led_verde2, OUTPUT);

  faseSemaforo = 1;     //começa na fase 1
  estadoanteriorbotao = digitalRead(botao);

  tempopisca = 0;
  estadopisca = HIGH;     //led começa ligado na fase de pisca
}

void loop() {

  estadobotao = digitalRead(botao);
  // detecta o momento em que o botão foi pressionado
  // (transição de LOW para HIGH)
  if((estadobotao == HIGH) && (estadoanteriorbotao == LOW)){
    if(faseSemaforo < 4){
      faseSemaforo++;
    }else{
      faseSemaforo = 1;  // volta para a fase inicial
    }
  }
  // atualiza o estado anterior do botão
  estadoanteriorbotao = estadobotao;

  if(faseSemaforo == 1){  // fase 1: semáforo 1 verde, semáforo 2 vermelho
    digitalWrite(led_verde1, HIGH);
    digitalWrite(led_amarelo1, LOW);
    digitalWrite(led_vermelho1, LOW);

    digitalWrite(led_verde2, LOW);
    digitalWrite(led_vermelho2, HIGH);

  }
  if(faseSemaforo == 2){ // fase 2: semáforo 1 amarelo, semáforo 2 vermelho
    digitalWrite(led_verde1, LOW);
    digitalWrite(led_amarelo1, HIGH);
    digitalWrite(led_vermelho1, LOW);

    digitalWrite(led_verde2, LOW);
    digitalWrite(led_vermelho2, HIGH);

  }
  if(faseSemaforo == 3){ // fase 3: semáforo 1 vermelho, semáforo 2 verde
    digitalWrite(led_verde1, LOW);
    digitalWrite(led_amarelo1, LOW);
    digitalWrite(led_vermelho1, HIGH);

    digitalWrite(led_verde2, HIGH);
    digitalWrite(led_vermelho2, LOW);
  }
  if(faseSemaforo == 4){ // fase 4: semáforo 1 vermelho e semáforo 2 vermelho piscando
    digitalWrite(led_verde1, LOW);
    digitalWrite(led_amarelo1, LOW);
    digitalWrite(led_vermelho1, HIGH);
    
    tempopisca++;// alterna o estado do LED vermelho 2 a cada 2 ciclos do loop
    if(tempopisca == 2){
      estadopisca = !estadopisca;
      tempopisca = 0;
    }
    digitalWrite(led_verde2, LOW);
    digitalWrite(led_vermelho2, estadopisca);
    
  }
  delay(200);  //delay pra desacelerar o loop

}