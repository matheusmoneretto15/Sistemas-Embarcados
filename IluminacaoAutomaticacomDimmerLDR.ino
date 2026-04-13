const int ldr = A0;
const int botao = 2;
const int led = 5;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  int luz = analogRead(ldr);

  // Galpão vazio → 10%
  if (digitalRead(botao) == HIGH) {
    analogWrite(led, 25);
    return;
  }

  // Compensação de luz
  int brilho = map(luz, 0, 1023, 255, 0);
  analogWrite(led, brilho);
}