//exemplo de codigo implementando tres estruturas de repetição distintas, implementando funções adicionais usando um botao
//goto, continue,break


#define botao 2

void setup() {
  pinMode(botao, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int n2 = 0;
  int n3 = 0;
  int i;

  //laço dos numeros
  for(i = 0;i <50;i++){
    Serial.print(char(i % 10) + 48); //gera numeros de 0 a 9 repetidamente, convertendo pra ASCII
    if(digitalRead(botao) == LOW){ //se o botao for apertado, sai do loop
      delay(400);
      break;
    }
    delay(50);
  }
  Serial.println();

  //laço das letras maiusculas
  letrasMaiusculas:
  while(n2 < 50){
    Serial.print(char(n2 % 25) + 65); //percorre o alfabeto trasnformado em maisuculo com ASCII
    n2++;
    if(digitalRead(botao) == LOW){//sai do loop
      delay(400);
      continue;
    }
  } delay(50);
  Serial.println();

  //laço das letras minusculas
  //usando do while, executa ao menos uma vez o codigo
  do{
    n3 = random(25); //numero aleatorio de 0 a 24
    Serial.println(char(n3 + 97)); //imprime as letras minusculas, segundo o ASCII
    if(digitalRead(botao) == LOW){   //se o botao for pressionado, reinicia o bloco das letras maiusculas com goto
      delay(400);
      Serial.println();
      n2 = 0;
      goto letrasMaiusculas;  //pula o fluxo do programa para outro ponto do codigo(letrasMaiusculas)
    }
    delay(50);
  }while(n3 != 16);
  Serial.println();
  
  }

