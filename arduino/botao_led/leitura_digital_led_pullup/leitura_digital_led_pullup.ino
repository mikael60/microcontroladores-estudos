//uso do metodo input_pullup do botao com resistencia interna

#define ledverde 10
#define  ledvermelho 9
#define botao 7


void setup(){
  pinMode(ledverde,OUTPUT);
  pinMode(ledvermelho,OUTPUT);
  pinMode(botao,INPUT_PULLUP);
}


void loop(){
	int estadobotao;
  	estadobotao = digitalRead(botao);
  
  	digitalWrite(ledverde,estadobotao);
  	digitalWrite(ledvermelho,!estadobotao);
  
}
