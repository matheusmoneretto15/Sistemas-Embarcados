```cpp id="tmpl123"
// =====================================================
// 📌 DEFINIÇÃO DE PINOS (ligação física)
// =====================================================
int botao1 = 2;   // botão principal (ex: INICIO)
int botao2 = 3;   // botão secundário (ex: CONTAGEM)
int led1 = 9;     // LED 1 (ex: motor / saída principal)
int led2 = 10;    // LED 2 (ex: aviso / piscar)

// =====================================================
// 📌 VARIÁVEIS DO SISTEMA (memória do programa)
// =====================================================
bool estadoSistema = false; // controla se o sistema está ativo (ligado/desligado)
int contador = 0;           // guarda quantidade de eventos (ex: cliques, espiras)

// =====================================================
// 📌 CONTROLE DE CLIQUE (EVITA CONTAGEM DUPLA)
// =====================================================
// IMPORTANTE: detecta apenas o momento do clique (borda), não enquanto segura
bool ultimoBotao1 = HIGH; // guarda estado anterior do botão1
bool ultimoBotao2 = HIGH; // guarda estado anterior do botão2

// =====================================================
// 📌 CONTROLE DE TEMPO (millis)
// =====================================================
unsigned long tempoAnterior = 0; // armazena último tempo registrado
int intervalo = 1000;            // tempo de espera (ms) → 1000 = 1 segundo
bool estadoLed = false;          // estado atual do LED de piscar

// =====================================================
// 📌 SETUP (executa uma vez)
// =====================================================
void setup() {
  // configuração dos pinos
  pinMode(botao1, INPUT_PULLUP); // botão com pull-up (solto=HIGH, pressionado=LOW)
  pinMode(botao2, INPUT_PULLUP);

  pinMode(led1, OUTPUT); // LED como saída
  pinMode(led2, OUTPUT);

  Serial.begin(9600); // inicia comunicação serial (debug / mostrar valores)
}

// =====================================================
// 📌 LOOP (executa infinitamente)
// =====================================================
void loop() {

  // =====================================================
  // 🔹 1. LEITURA DAS ENTRADAS
  // =====================================================
  bool leitura1 = digitalRead(botao1); // lê estado atual do botão1
  bool leitura2 = digitalRead(botao2); // lê estado atual do botão2

  // =====================================================
  // 🔹 2. BOTÃO 1 → AÇÃO DE INÍCIO / RESET
  // =====================================================
  // condição: detecta clique (HIGH → LOW)
  if (leitura1 == LOW && ultimoBotao1 == HIGH) {
    estadoSistema = true;   // ativa sistema
    contador = 0;           // zera contador
    digitalWrite(led1, HIGH); // liga saída principal

    Serial.println("Sistema iniciado");
  }

  // atualiza estado anterior (OBRIGATÓRIO)
  ultimoBotao1 = leitura1;

  // =====================================================
  // 🔹 3. BOTÃO 2 → AÇÃO DE CONTAGEM
  // =====================================================
  // só funciona se sistema estiver ativo
  if (estadoSistema && leitura2 == LOW && ultimoBotao2 == HIGH) {
    contador++; // incrementa contador

    Serial.print("Contagem: ");
    Serial.println(contador);
  }

  // atualiza estado anterior
  ultimoBotao2 = leitura2;

  // =====================================================
  // 🔹 4. CONDIÇÃO PRINCIPAL (ex: parar sistema)
  // =====================================================
  // aqui você muda conforme a questão (ex: 10, 20, 60...)
  if (contador >= 20) {
    estadoSistema = false;     // desativa sistema
    digitalWrite(led1, LOW);   // desliga saída principal
  }

  // =====================================================
  // 🔹 5. AÇÃO COM TEMPO (millis → NÃO trava)
  // =====================================================
  // executa apenas quando sistema terminou
  if (!estadoSistema && contador >= 20) {

    unsigned long tempoAtual = millis(); // pega tempo atual

    // verifica se passou o intervalo definido
    if (tempoAtual - tempoAnterior >= intervalo) {

      tempoAnterior = tempoAtual; // atualiza referência de tempo

      estadoLed = !estadoLed;     // alterna estado (liga/desliga)
      digitalWrite(led2, estadoLed); // aplica no LED
    }

  } else {
    // garante que LED fique desligado antes da condição
    digitalWrite(led2, LOW);
  }

}
```
