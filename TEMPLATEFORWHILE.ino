```cpp id="loops_template"
/*
=====================================================
🧠 TEMPLATE - LAÇOS DE REPETIÇÃO + ARRAYS (PROVA)
=====================================================

✔ for → quando sabe quantas vezes repetir
✔ while → quando depende de condição
✔ do...while → executa pelo menos 1 vez
✔ arrays → organizar vários pinos/dados

👉 APAGUE o que não usar
👉 ADAPTE conforme o enunciado

=====================================================
*/

// =====================
// 📌 PINOS / ARRAYS
// =====================
int leds[3] = {8, 9, 10};   // vetor de LEDs
int botao = 2;

// =====================
// 📌 VARIÁVEIS
// =====================
int contador = 0;

// =====================
// 📌 SETUP
// =====================
void setup() {
  Serial.begin(9600);

  // configurar todos os LEDs com FOR
  for (int i = 0; i < 3; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(botao, INPUT_PULLUP);
}

// =====================
// 📌 LOOP
// =====================
void loop() {

  // ==========================================
  // 🔹 1. FOR (repetição com quantidade fixa)
  // ==========================================
  // exemplo: acender LEDs em sequência
  for (int i = 0; i < 3; i++) {
    digitalWrite(leds[i], HIGH);
    delay(300);
    digitalWrite(leds[i], LOW);
  }

  // ==========================================
  // 🔹 2. WHILE (espera condição)
  // ==========================================
  // exemplo: aguarda botão ser pressionado
  while (digitalRead(botao) == HIGH) {
    Serial.println("Aguardando botão...");
    delay(200);
  }

  Serial.println("Botão pressionado!");

  // ==========================================
  // 🔹 3. DO...WHILE (executa pelo menos 1 vez)
  // ==========================================
  int tentativa = 0;

  do {
    Serial.println("Executando tentativa...");
    tentativa++;
    delay(300);

  } while (tentativa < 3);

  // ==========================================
  // 🔹 4. CONTADOR COM WHILE
  // ==========================================
  contador = 0;

  while (contador < 5) {
    Serial.print("Contador: ");
    Serial.println(contador);
    contador++;
  }

  // ==========================================
  // 🔹 5. LEITURA DE VÁRIOS SENSORES (ARRAY)
  // ==========================================
  int sensores[4] = {A0, A1, A2, A3};

  for (int i = 0; i < 4; i++) {
    int valor = analogRead(sensores[i]);
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(valor);
  }

  delay(1000); // pausa geral (pode remover em prova)
}
```

