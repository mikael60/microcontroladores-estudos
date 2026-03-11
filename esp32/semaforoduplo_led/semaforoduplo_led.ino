#define ledvermelho1 23
#define ledamarelo1 22
#define ledverde1 21
#define ledvermelho2 19
#define ledamarelo2 18
#define ledverde2 5

void setup() {
  pinMode(ledvermelho1,OUTPUT);  
  pinMode(ledamarelo1,OUTPUT);
  pinMode(ledverde1,OUTPUT);    
  pinMode(ledvermelho2,OUTPUT);  
  pinMode(ledamarelo2,OUTPUT);
  pinMode(ledverde2,OUTPUT); 
}
void loop() {
  digitalWrite(ledvermelho1,HIGH);
  digitalWrite(ledvermelho2,HIGH);
  delay(1000);
  digitalWrite(ledvermelho1,LOW);
  digitalWrite(ledverde1,HIGH);
  delay(3000);
  digitalWrite(ledverde1,LOW);
  digitalWrite(ledamarelo1,HIGH);
  delay(1000);
  digitalWrite(ledamarelo1,LOW);
  digitalWrite(ledvermelho1,HIGH);
  delay(1000);
  digitalWrite(ledvermelho2,LOW);
  digitalWrite(ledverde2,HIGH);
  delay(3000);
  digitalWrite(ledverde2,LOW);
  digitalWrite(ledamarelo2,HIGH);
  delay(1000);
  digitalWrite(ledamarelo2,LOW);
  digitalWrite(ledvermelho2,HIGH);
  delay(1000);

}
