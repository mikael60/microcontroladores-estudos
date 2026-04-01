//exemplo de circuito no arduino usando um diplay de 7 segmentos usando arrays com loop for.


#define botao 2

byte portas[8] = {10,9,6,7,8,11,12,5}; //array de pinos do arduino
int numero = 0;
bool botaoAnt = HIGH;

byte displayConfig[11][8] = {//array pra guardar os numeros do display
  {1,1,1,1,1,1,0,0},
  {0,1,1,0,0,0,0,0},
  {1,1,0,1,1,0,1,0},
  {1,1,1,1,0,0,1,0},
  {0,1,1,0,0,1,1,0},
  {1,0,1,1,0,1,1,0},
  {1,0,1,1,1,1,1,0},
  {1,1,1,0,0,0,0,0},
  {1,1,1,1,1,1,1,0},
  {1,1,1,1,0,1,1,0},
  {0,0,0,0,0,0,0,0}
};

void setup() {
  pinMode(botao, INPUT_PULLUP);

  for(int i = 0; i < 8; i++){
    pinMode(portas[i], OUTPUT);
  }
}

void loop() {
  bool leitura = digitalRead(botao);

  if(leitura == LOW && botaoAnt == HIGH){ //leitura do botao, se esta pressionado ou nao
    numero++;
    if(numero > 9){
      numero = 0;
    }
    delay(200);
  }

  botaoAnt = leitura;

  for(int dp = 0; dp < 8; dp++){//loop for que percorre as portas do display, e liga ou desliga conforme as linhas da array displayConfig
    digitalWrite(portas[dp], displayConfig[numero][dp]);
  }
}
