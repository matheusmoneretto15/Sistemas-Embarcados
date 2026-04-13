const int leds[] = {5, 6, 7, 8};
int indice = 0;
unsigned long tempoAnterior = 0;
const int intervalo = 200;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    for (int i = 0; i < 4; i++) {
      digitalWrite(leds[i], LOW);
    }

    digitalWrite(leds[indice], HIGH);
    indice = (indice + 1) % 4;
  }
}