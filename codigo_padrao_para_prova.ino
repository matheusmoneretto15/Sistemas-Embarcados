```cpp id="fullkit"
/*
=====================================================
🚀 CÓDIGO PADRÃO DE PROVA (COMPLETO)
=====================================================

✔ botão início
✔ botão contagem
✔ contador
✔ potenciômetro (limite)
✔ controle de estado
✔ millis (piscar)
✔ pronto pra adaptar

👉 APAGUE o que não usar na prova
👉 MUDE apenas valores e condições

=====================================================
*/

// =====================
// 📌 PINOS
// =====================
int botaoInicio = 2;
int botaoCont = 3;
int pot = A0;

int saidaPrincipal = 9; // motor / LED
int ledFinal = 10;      // LED de piscar

// =====================
// 📌 VARIÁVEIS
// =====================
bool ativo = false;
int contador = 0;

// botões (controle de clique)
bool ultInicio = HIGH;
bool ultCont = HIGH;

// potenciômetro
int valorADC = 0;
int limite = 0;

// millis
unsigned long tempoAnt = 0;
int intervalo = 500;
bool estadoLed = false;

// =====================
// 📌 SETUP
// =====================
void setup() {
  pinMode(botaoInicio, INPUT_PULLUP);
  pinMode(botaoCont, INPUT_PULLUP);

  pinMode(saidaPrincipal, OUTPUT);
  pinMode(ledFinal, OUTPUT);

  Serial.begin(9600); // opcional
}

// =====================
// 📌 LOOP
// =====================
void loop() {

  // =====================
  // 🔹 LEITURA
  // =====================
  bool inicio = digitalRead(botaoInicio);
  bool cont = digitalRead(botaoCont);

  valorADC = analogRead(pot);

  // converte potenciômetro (ajuste aqui se quiser)
  limite = map(valorADC, 0, 1023, 1, 60);

  // =====================
  // 🔹 BOTÃO INÍCIO
  // =====================
  if (inicio == LOW && ultInicio == HIGH) {
    ativo = true;
    contador = 0;

    digitalWrite(saidaPrincipal, HIGH);
  }
  ultInicio = inicio;

  // =====================
  // 🔹 CONTAGEM
  // =====================
  if (ativo && cont == LOW && ultCont == HIGH) {
    contador++;

    // debug opcional
    Serial.print("Cont: ");
    Serial.print(contador);
    Serial.print(" Limite: ");
    Serial.println(limite);

    // condição principal
    if (contador >= limite) {
      ativo = false;
      digitalWrite(saidaPrincipal, LOW);
    }
  }
  ultCont = cont;

  // =====================
  // 🔹 AÇÃO FINAL (millis)
  // =====================
  if (!ativo && contador >= limite) {

    if (millis() - tempoAnt >= intervalo) {
      tempoAnt = millis();

      estadoLed = !estadoLed;
      digitalWrite(ledFinal, estadoLed);
    }

  } else {
    digitalWrite(ledFinal, LOW);
  }

}
```
