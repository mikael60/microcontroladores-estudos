//uso do metodo pull_down para acionamento de um botao, com resistor externo 1Kohm


#define ledverde 10
#define  ledvermelho 9
#define botao 7


void setup(){
  pinMode(ledverde,OUTPUT);
  pinMode(ledvermelho,OUTPUT);
  pinMode(botao,INPUT);
}


void loop(){
	int estadobotao;
  	estadobotao = digitalRead(botao);
  
  	digitalWrite(ledverde,estadobotao);
  	digitalWrite(ledvermelho,!estadobotao);
  
}
