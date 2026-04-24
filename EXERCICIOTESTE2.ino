const int potPin = A0;
const int fanPin = 9;   // LED 1 (PWM)
const int ledMax = 10;  // LED 2

void setup() {
  pinMode(fanPin, OUTPUT);
  pinMode(ledMax, OUTPUT);
}

void loop() {
  int leitura = analogRead(potPin);

  // Converte de 0–1023 para 0–100 °C
  float temperatura = (leitura / 1023.0) * 100.0;

  int pwm = 0;

  if (temperatura < 30) {
    // 20% de potência
    pwm = 0.2 * 255;
    digitalWrite(ledMax, LOW);
  } 
  else if (temperatura >= 30 && temperatura <= 60) {
    // Crescimento linear de 20% até 100%
    float proporcao = (temperatura - 30.0) / 30.0; // 0 a 1
    float potencia = 0.2 + (0.8 * proporcao);     // 20% a 100%
    pwm = potencia * 255;
    digitalWrite(ledMax, LOW);
  } 
  else {
    // Acima de 60°C → 100%
    pwm = 255;
    digitalWrite(ledMax, HIGH);
  }

  analogWrite(fanPin, pwm);
}