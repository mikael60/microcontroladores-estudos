/circuito de leds usando resistor LDR controlando a iluminação dos leds usando arduino uno

int pinos[9] = {12,11,10,9,8,7,6,5,4};
int i;

float minimo = 85;
float maximo = 1020;
float valorLDR;
float luminosidade;

void setup(){
  for(i = 0;i <= 8;i++){
    pinMode(pinos[i],OUTPUT);
  
  }
  pinMode(A0,INPUT);
  
}
void loop(){
	valorLDR = analogRead(A0);
  	luminosidade = ((valorLDR - minimo) / (maximo - minimo)) * 10;
  	luminosidade = (luminosidade - 10) * -1;
  
  	for(i = 0;i <= 8;i++){
      if(i < luminosidade){
      	digitalWrite(pinos[i],HIGH);
      }else{
		digitalWrite(pinos[i],LOW);
		
  }
	delay(500);
  }
}