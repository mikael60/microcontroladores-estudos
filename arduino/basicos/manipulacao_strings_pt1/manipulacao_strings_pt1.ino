/**
 * PROJETO: Guia de Manipulação de Strings em Microcontroladores (PARTE1)
 * DESCRIÇÃO: Exemplos de concatenação, conversão, comparação e filtros de Strings.
 * AUTOR: Adaptado de aula técnica
 */

// Variáveis Globais
String textoRecebido = "";
unsigned long delay1 = 0;
const String textoAlvo = "teste"; // Texto para fins de comparação

void setup() {
  Serial.begin(9600);
  Serial.println("--- Sistema Iniciado: Digite algo no Monitor Serial ---");

  // ============================================================
  // SEÇÃO 1: EXEMPLOS DE CONCATENAÇÃO (Para consulta)
  // ============================================================
  /*
    String t1 = "Arduino";
    String t2 = " Uno";
    t1.concat(t2);         // Resultado: "Arduino Uno"
    t1 += " R3";           // Resultado: "Arduino Uno R3"
    t1 = t1 + " " + 2024;  // Concatena números automaticamente
  */

  // ============================================================
  // SEÇÃO 2: EXEMPLOS DE CONVERSÃO (Para consulta)
  // ============================================================
  /*
    int num = 255;
    float real = 345.8765;
    
    String binario = String(num, BIN);    // "11111111"
    String hexadecimal = String(num, HEX);// "FF"
    String decimal = String(real, 2);     // "345.88" (2 casas decimais)
  */
}

void loop() {
  // --- LEITURA SERIAL ---
  if (Serial.available()) {
    char caracter = Serial.read();
    textoRecebido += caracter;
    delay1 = millis(); // Reinicia o cronômetro a cada caractere recebido
  }

  // --- PROCESSAMENTO DA MENSAGEM (Após 10ms de silêncio) ---
  if (((millis() - delay1) > 10) && (textoRecebido != "")) {
    
    // 1. Limpeza de caracteres invisíveis (\n ou \r)
    textoRecebido.trim(); 

    Serial.print("Texto recebido: ");
    Serial.println(textoRecebido);

    // 2. Exemplo: Tamanho da String
    Serial.print("Tamanho: ");
    Serial.println(textoRecebido.length());

    // 3. Exemplo: Comparação (Ignorando maiúsculas/minúsculas)
    if (textoRecebido.equalsIgnoreCase(textoAlvo)) {
      Serial.println("Resultado: O texto é IGUAL a 'teste'");
    } else {
      Serial.println("Resultado: O texto é DIFERENTE de 'teste'");
    }

    // 4. Exemplo: startsWith e endsWith
    // Verifica se começa com 'A' a partir da posição 0
    if (textoRecebido.startsWith("A")) {
      Serial.println("- Começa com a letra A");
    }

    // Verifica se termina com '!'
    if (textoRecebido.endsWith("!")) {
      Serial.println("- Termina com exclamação");
    }

    Serial.println("-----------------------");

    // 5. Limpa a variável para a próxima leitura
    textoRecebido = ""; 
  }
}