const int botaoA = 2;
const int botaoB = 3;
const int led = 5;

unsigned long tempoInicio = 0;
bool ativo = false;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(botaoA) == LOW) {
    ativo = true;
    tempoInicio = millis();
    digitalWrite(led, HIGH);
  }

  if (ativo && digitalRead(botaoB) == LOW) {
    ativo = false;
    digitalWrite(led, LOW);
  }

  if (ativo && millis() - tempoInicio >= 5000) {
    ativo = false;
    digitalWrite(led, LOW);
  }
}