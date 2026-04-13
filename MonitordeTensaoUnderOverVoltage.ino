const int pot = A0;
const int ledVerde = 5;
const int ledAmarelo = 6;
const int ledVermelho = 7;
const int chave = 8;

unsigned long tempoFora = 0;
bool foraFaixa = false;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(chave, OUTPUT);
}

void loop() {
  int valor = analogRead(pot);
  float tensao = (valor / 1023.0) * 250.0;

  // Reset LEDs
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  if (tensao >= 210 && tensao <= 230) {
    digitalWrite(ledVerde, HIGH);
    foraFaixa = false;
  }
  else if (tensao < 210) {
    digitalWrite(ledAmarelo, HIGH);
  }
  else {
    digitalWrite(ledVermelho, HIGH);
  }

  // Fora da faixa crítica
  if (tensao < 180 || tensao > 240) {
    if (!foraFaixa) {
      tempoFora = millis();
      foraFaixa = true;
    }
    if (millis() - tempoFora >= 2000) {
      digitalWrite(chave, LOW); // desliga sistema
    }
  } else {
    foraFaixa = false;
    digitalWrite(chave, HIGH);
  }
}