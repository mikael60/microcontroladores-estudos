/**
 * GUIA DE MANIPULAÇÃO DE STRINGS (PARTE 2)
 * Este código demonstra funções avançadas de edição, busca e conversão.
 */

String textoRecebido = "";
unsigned long delay1 = 0;

// Protótipos de funções utilitárias (implementadas ao final do código)
String padR(String texto, int tamanho, char caractere = ' ');
String padL(String texto, int tamanho, char caractere = ' ');
String strZero(String texto, int tamanho);
String replicate(char caractere, int vezes);

void setup() {
  Serial.begin(9600);
  delay(1000); // Pequena espera para abrir o monitor
  
  String texto = "Brincando com ideias";
  Serial.println("--- Texto Original ---");
  Serial.println(texto);
  Serial.println();

  // 1. SUBSTITUIÇÃO (replace)
  texto.replace("com", "nas minhas");
  Serial.print("1. Replace: ");
  Serial.println(texto);

  // 2. SUBSTRINGS (Extração de parte do texto)
  // Pega do índice 4 até o 7 (o 8 é o limite exclusivo)
  Serial.print("2. Substring (4,8): ");
  Serial.println(texto.substring(4, 8));

  // 3. ALTERAR E ACESSAR CARACTERES (setCharAt e charAt)
  texto.setCharAt(10, 'C'); // Troca o caractere na posição 10
  Serial.print("3a. Caractere na pos(2): ");
  Serial.println(texto.charAt(2)); 
  Serial.print("3b. Texto após setCharAt: ");
  Serial.println(texto);

  // 4. REMOÇÃO (remove)
  texto.remove(10, 4); // Remove 4 caracteres a partir da posição 10
  Serial.print("4a. Após remove(10,4): ");
  Serial.println(texto);
  
  texto.remove(9); // Remove tudo a partir da posição 9
  Serial.print("4b. Após remove(9): ");
  Serial.println(texto);

  // 5. BUSCA (indexOf e lastIndexOf)
  texto = "Arduino e Ideias"; // Reset para teste de busca
  Serial.print("5a. Posicao de 'Ideias': ");
  Serial.println(texto.indexOf("Ideias"));
  Serial.print("5b. Ultima ocorrencia de 'e': ");
  Serial.println(texto.lastIndexOf("e"));

  // 6. TRANSFORMAÇÃO (UpperCase e LowerCase) - ADICIONADO
  String transformar = "Aprendendo Arduino";
  transformar.toUpperCase();
  Serial.print("6a. Maiúsculas: ");
  Serial.println(transformar);
  
  transformar.toLowerCase();
  Serial.print("6b. Minúsculas: ");
  Serial.println(transformar);

  Serial.println("\n--- Digite algo com espaços extras ou números no Serial ---");
}

void loop() {
  char caractere;

  // Captura de texto via Serial com timer (millis)
  if (Serial.available()) {
    caractere = Serial.read();
    textoRecebido += caractere;
    delay1 = millis();
  }

  // Quando o envio termina (10ms de silêncio)
  if (((millis() - delay1) > 10) && (textoRecebido != "")) {
    
    // 7. LIMPEZA (trim) - ADICIONADO
    // Remove espaços, \n e \r do início e do fim
    textoRecebido.trim(); 
    
    Serial.print("Recebido (limpo): [");
    Serial.print(textoRecebido);
    Serial.println("]");

    // 8. CONVERSÃO (toInt e toFloat)
    int valorInteiro = textoRecebido.toInt();
    
    Serial.print("Concatenado (Texto + 200): ");
    Serial.println(textoRecebido + 200); // Trata o 200 como texto
    
    Serial.print("Calculado (Número + 200): ");
    Serial.println(valorInteiro + 200);   // Soma matemática

    textoRecebido = ""; // Limpa para a próxima
  }
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES UTILITÁRIAS ---

// Preenche com caracteres à direita
String padR(String texto, int tamanho, char caractere) {
  while (texto.length() < tamanho) {
    texto += caractere;
  }
  return texto;
}

// Preenche com caracteres à esquerda
String padL(String texto, int tamanho, char caractere) {
  while (texto.length() < tamanho) {
    texto = caractere + texto;
  }
  return texto;
}

// Adiciona zeros à esquerda
String strZero(String texto, int tamanho) {
  return padL(texto, tamanho, '0');
}

// Cria uma sequência repetida de caracteres
String replicate(char caractere, int vezes) {
  String temp = "";
  for (int i = 0; i < vezes; i++) temp += caractere;
  return temp;
}