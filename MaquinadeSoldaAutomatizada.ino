const int botao = 2;
const int pot = A0;

const int pressao = 5;
const int solda = 6;
const int pronto = 7;

int etapa = 0;
unsigned long tempo = 0;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(pressao, OUTPUT);
  pinMode(solda, OUTPUT);
  pinMode(pronto, OUTPUT);
}

void loop() {
  if (digitalRead(botao) == LOW && etapa == 0) {
    etapa = 1;
    tempo = millis();
  }

  if (etapa == 1 && millis() - tempo >= 800) {
    digitalWrite(pressao, HIGH);
    etapa = 2;
    tempo = millis();
  }

  if (etapa == 2 && millis() - tempo >= 200) {
    int pwm = map(analogRead(pot), 0, 1023, 0, 255);
    analogWrite(solda, pwm);
    etapa = 3;
    tempo = millis();
  }

  if (etapa == 3 && millis() - tempo >= 1500) {
    analogWrite(solda, 0);
    etapa = 4;
    tempo = millis();
  }

  if (etapa == 4 && millis() - tempo >= 500) {
    digitalWrite(pressao, LOW);
    digitalWrite(pronto, HIGH);
    etapa = 5;
    tempo = millis();
  }

  if (etapa == 5 && millis() - tempo >= 2000) {
    digitalWrite(pronto, LOW);
    etapa = 0;
  }
}