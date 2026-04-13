const int pot = A0;
const int ledBaixo = 5;
const int ledMedio = 6;
const int ledAlto = 7;

unsigned long tempo = 0;
bool pisca = false;

void setup() {
  pinMode(ledBaixo, OUTPUT);
  pinMode(ledMedio, OUTPUT);
  pinMode(ledAlto, OUTPUT);
}

void loop() {
  int nivel = analogRead(pot);

  // Limpa
  digitalWrite(ledBaixo, LOW);
  digitalWrite(ledMedio, LOW);
  digitalWrite(ledAlto, LOW);

  // Crítico (baixo ou alto)
  if (nivel < 200 || nivel > 900) {
    if (millis() - tempo >= 200) {
      tempo = millis();
      pisca = !pisca;
      digitalWrite(ledBaixo, pisca);
      digitalWrite(ledAlto, pisca);
    }
  }
  else if (nivel < 400) {
    digitalWrite(ledBaixo, HIGH);
  }
  else if (nivel < 700) {
    digitalWrite(ledMedio, HIGH);
  }
  else {
    digitalWrite(ledAlto, HIGH);
  }
}