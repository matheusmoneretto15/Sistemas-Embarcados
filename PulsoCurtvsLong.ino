const int botao = 2;
const int led1 = 5;
const int led2 = 6;

unsigned long tempoPressionado = 0;
bool pressionado = false;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (digitalRead(botao) == LOW && !pressionado) {
    pressionado = true;
    tempoPressionado = millis();
  }

  if (digitalRead(botao) == HIGH && pressionado) {
    pressionado = false;
    unsigned long duracao = millis() - tempoPressionado;

    if (duracao < 1000) digitalWrite(led1, HIGH);
    else if (duracao > 2000) digitalWrite(led2, HIGH);
  }
}