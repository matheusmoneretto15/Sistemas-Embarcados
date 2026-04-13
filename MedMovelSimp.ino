const int pot = A0;
const int led = 7;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  long soma = 0;

  for (int i = 0; i < 10; i++) {
    soma += analogRead(pot);
    delay(10);
  }

  int media = soma / 10;

  if (media > 700) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}