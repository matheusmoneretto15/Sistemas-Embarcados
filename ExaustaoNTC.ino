const int ntc = A0;
const int ledPWM = 5;
const int ledMax = 6;

void setup() {
  pinMode(ledPWM, OUTPUT);
  pinMode(ledMax, OUTPUT);
}

void loop() {
  int val = analogRead(ntc);

  if(val < 300){
    analogWrite(ledPWM, 51);
    digitalWrite(ledMax, LOW);
  }
  else if(val < 700){
    int pwm = map(val,300,700,51,255);
    analogWrite(ledPWM, pwm);
    digitalWrite(ledMax, LOW);
  }
  else{
    analogWrite(ledPWM,255);
    digitalWrite(ledMax,HIGH);
  }
}