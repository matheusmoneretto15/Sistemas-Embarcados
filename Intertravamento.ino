const int botaoA = 2;
const int botaoB = 3;
const int led1 = 5;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
}

void loop() {
  if (digitalRead(botaoA) == LOW && digitalRead(botaoB) == LOW) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
}
