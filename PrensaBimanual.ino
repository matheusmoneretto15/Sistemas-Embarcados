const int botaoA = 2;
const int botaoB = 3;
const int ledOK = 5;
const int ledErro = 6;

unsigned long tA=0, tB=0;

void setup() {
  pinMode(botaoA, INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
  pinMode(ledOK, OUTPUT);
  pinMode(ledErro, OUTPUT);
}

void loop() {
  if(digitalRead(botaoA)==LOW) tA=millis();
  if(digitalRead(botaoB)==LOW) tB=millis();

  if(abs((long)(tA - tB)) <= 500){
    digitalWrite(ledOK, HIGH);
    digitalWrite(ledErro, LOW);
  } else {
    digitalWrite(ledOK, LOW);
    digitalWrite(ledErro, HIGH);
  }
}