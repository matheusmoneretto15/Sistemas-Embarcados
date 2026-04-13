const int botao1 = 2;
const int botao3 = 4;
const int led1 = 5;

void setup() {
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao3, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  if (digitalRead(botao1) == LOW && digitalRead(botao3) == LOW) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}