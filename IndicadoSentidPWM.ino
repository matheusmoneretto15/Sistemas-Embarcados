const int pot = A0;
const int led1 = 5;
const int led2 = 6;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  int valor = analogRead(pot);

  if (valor < 512) {
    int brilho = map(valor, 0, 511, 255, 0);
    analogWrite(led1, brilho);
    analogWrite(led2, 0);
  } else {
    int brilho = map(valor, 512, 1023, 0, 255);
    analogWrite(led2, brilho);
    analogWrite(led1, 0);
  }
}