// =====================
// 📌 PINOS
// =====================
int botaoInicio = 2;      // botão para iniciar/resetar sistema
int botaoContagem = 3;    // botão para incrementar contador
int potenciometro = A0;   // pino analógico
int motor = 9;            // saída (motor/LED principal)
int ledFinal = 10;        // LED que pisca ao final

// =====================
// 📌 VARIÁVEIS
// =====================
int contador = 0;         // contador de eventos
bool sistemaAtivo = false;

// controle de clique
bool ultimoInicio = HIGH;
bool ultimoContagem = HIGH;

// potenciômetro
int valorADC = 0;         // leitura (0–1023)
int limite = 0;           // limite definido pelo potenciômetro

// millis
unsigned long tempoAnterior = 0;
int intervalo = 500;
bool estadoLed = false;

// =====================
// 📌 SETUP
// =====================
void setup() {
  pinMode(botaoInicio, INPUT_PULLUP);
  pinMode(botaoContagem, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
  pinMode(ledFinal, OUTPUT);

  Serial.begin(9600);
}

// =====================
// 📌 LOOP
// =====================
void loop() {

  // =====================
  // 🔹 LEITURAS
  // =====================
  bool inicio = digitalRead(botaoInicio);
  bool cont = digitalRead(botaoContagem);

  valorADC = analogRead(potenciometro);

  // converte 0–1023 → 1–60 (limite ajustável)
  limite = map(valorADC, 0, 1023, 1, 60);

  // =====================
  // 🔹 BOTÃO INICIO
  // =====================
  if (inicio == LOW && ultimoInicio == HIGH) {
    contador = 0;                 // zera contador
    sistemaAtivo = true;          // ativa sistema
    digitalWrite(motor, HIGH);    // liga motor

    Serial.println("Sistema iniciado");
  }
  ultimoInicio = inicio;

  // =====================
  // 🔹 CONTAGEM
  // =====================
  if (sistemaAtivo && cont == LOW && ultimoContagem == HIGH) {
    contador++;

    Serial.print("Contador: ");
    Serial.print(contador);
    Serial.print(" / Limite: ");
    Serial.println(limite);

    // verifica limite
    if (contador >= limite) {
      sistemaAtivo = false;       // para sistema
      digitalWrite(motor, LOW);   // desliga motor

      Serial.println("Limite atingido!");
    }
  }
  ultimoContagem = cont;

  // =====================
  // 🔹 LED FINAL (millis)
  // =====================
  if (!sistemaAtivo && contador >= limite) {

    unsigned long tempoAtual = millis();

    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;

      estadoLed = !estadoLed;     // alterna
      digitalWrite(ledFinal, estadoLed);
    }

  } else {
    digitalWrite(ledFinal, LOW);
  }
}
