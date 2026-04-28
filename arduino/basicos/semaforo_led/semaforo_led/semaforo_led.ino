//cricuito de semaforo montado na vertical usando define para os leds
#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4


void setup(){
	pinMode(LED_VERDE,OUTPUT);
  	pinMode(LED_AMARELO	,OUTPUT);
  	pinMode(LED_VERMELHO,OUTPUT);
}

void loop(){
  //led verde
	digitalWrite(LED_VERDE,HIGH);
  	digitalWrite(LED_AMARELO,LOW);
  	digitalWrite(LED_VERMELHO,LOW);
  	delay(5000);

  //led amarelo
	digitalWrite(LED_VERDE,LOW);
  	digitalWrite(LED_AMARELO,HIGH);
  	digitalWrite(LED_VERMELHO,LOW);
  	delay(2000);
  
  //led vermelho
  	digitalWrite(LED_VERDE,LOW);
  	digitalWrite(LED_AMARELO,LOW);
  	digitalWrite(LED_VERMELHO,HIGH);
  	delay(5000);
  	
}

