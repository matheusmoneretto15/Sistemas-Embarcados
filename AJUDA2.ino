```cpp id="mini123"
/*
=====================================================
💻 EXEMPLOS PRONTOS (MINI CÓDIGOS DE PROVA)
=====================================================

🔘 1. BOTÃO LIGA/DESLIGA LED
-----------------------------------------------------
int botao = 2;
int led = 9;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(botao) == LOW) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}

=====================================================

🔁 2. TOGGLE (aperta → liga/desliga)
-----------------------------------------------------
int botao = 2;
int led = 9;

bool estado = false;
bool ultimo = HIGH;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  bool leitura = digitalRead(botao);

  if (leitura == LOW && ultimo == HIGH) {
    estado = !estado;
    digitalWrite(led, estado);
  }

  ultimo = leitura;
}

=====================================================

🔢 3. CONTADOR COM BOTÃO
-----------------------------------------------------
int botao = 2;
bool ultimo = HIGH;
int contador = 0;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bool leitura = digitalRead(botao);

  if (leitura == LOW && ultimo == HIGH) {
    contador++;
    Serial.println(contador);
  }

  ultimo = leitura;
}

=====================================================

⏱️ 4. PISCAR COM MILLIS (SEM DELAY)
-----------------------------------------------------
int led = 9;

unsigned long tempoAnt = 0;
int intervalo = 1000;
bool estado = false;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  if (millis() - tempoAnt >= intervalo) {
    tempoAnt = millis();
    estado = !estado;
    digitalWrite(led, estado);
  }
}

=====================================================

🎚️ 5. POTENCIÔMETRO (LEITURA)
-----------------------------------------------------
int pot = A0;
int valor;

void setup() {
  Serial.begin(9600);
}

void loop() {
  valor = analogRead(pot);
  Serial.println(valor);
}

=====================================================

⚙️ 6. POT + PWM (CONTROLE DE BRILHO)
-----------------------------------------------------
int pot = A0;
int led = 9;

int valor;
int pwm;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  valor = analogRead(pot);
  pwm = map(valor, 0, 1023, 0, 255);
  analogWrite(led, pwm);
}

=====================================================

🔴 7. CONTADOR COM LIMITE
-----------------------------------------------------
int contador = 0;

if (contador >= 10) {
  // ação (ex: desligar LED)
}

=====================================================

🔁 8. SISTEMA COM INÍCIO (2 BOTÕES)
-----------------------------------------------------
int botaoInicio = 2;
int botaoCont = 3;
int led = 9;

bool ativo = false;
int contador = 0;

bool ultInicio = HIGH;
bool ultCont = HIGH;

void setup() {
  pinMode(botaoInicio, INPUT_PULLUP);
  pinMode(botaoCont, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  bool inicio = digitalRead(botaoInicio);
  bool cont = digitalRead(botaoCont);

  if (inicio == LOW && ultInicio == HIGH) {
    ativo = true;
    contador = 0;
    digitalWrite(led, HIGH);
  }
  ultInicio = inicio;

  if (ativo && cont == LOW && ultCont == HIGH) {
    contador++;

    if (contador >= 20) {
      ativo = false;
      digitalWrite(led, LOW);
    }
  }
  ultCont = cont;
}

=====================================================

🎯 9. PISCAR APÓS CONDIÇÃO
-----------------------------------------------------
if (contador >= 10) {
  if (millis() - tempoAnt >= intervalo) {
    tempoAnt = millis();
    estado = !estado;
    digitalWrite(led, estado);
  }
}

=====================================================

🏁 DICA FINAL

Misture os blocos:
- botão → evento
- contador → controle
- pot → valor variável
- millis → tempo

=====================================================
*/
```
