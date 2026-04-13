const int botao = 2;
const int led = 5;

unsigned long inicio = 0;
bool ativo = false;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(botao) == LOW) {
    inicio = millis();
    ativo = true;
    digitalWrite(led, HIGH);
  }

  if (ativo && millis() - inicio >= 5000) {
    digitalWrite(led, LOW);
    ativo = false;
  }
}