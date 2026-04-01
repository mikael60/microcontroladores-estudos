//exemplo de codigo no esp32 usando um display de 7 segmentos, usando a estrutura de repetição for com arrays


#define botao 32
byte portas[8] = {23,22,21,19,18,5,33,15};   //array dos pinos do display
int numero = 0;
bool botaoAnt = HIGH;

byte displayConfig[11][8] = { //array pra guardar os digitos do display de 7 segmentos
  {1,1,1,1,1,1,0,0}, //0
  {0,1,1,0,0,0,0,0},//1
  {1,1,0,1,1,0,1,0},//2
  {1,1,1,1,0,0,1,0},//3
  {0,1,1,0,0,1,1,0},//4
  {1,0,1,1,0,1,1,0},//5
  {1,0,1,1,1,1,1,0},//6
  {1,1,1,0,0,0,0,0},//7
  {1,1,1,1,1,1,1,0},//8
  {1,1,1,1,0,1,1,0},//9
  {0,0,0,0,0,0,0,0}//dp
};

void setup() {
  pinMode(botao,INPUT_PULLUP);
  for(int i = 0;i <8;i++){ //loop for com array pra definir os pinos como saida
    pinMode(portas[i],OUTPUT);
  }


}

void loop() {
  //detecta quando o botao esta pressionado
  bool leitura = digitalRead(botao);
  if(leitura == LOW && botaoAnt == HIGH){
    numero++;
    if(numero > 9){
      numero = 0;
    }
  }  
  botaoAnt = leitura;

  //array pra percorrer as portas do display e ligar ou desligar conforme os leds do display, dentro da array display config.
  for(int dp = 0; dp < 8; dp++){
    digitalWrite(portas[dp], displayConfig[numero][dp]);
  }
}

