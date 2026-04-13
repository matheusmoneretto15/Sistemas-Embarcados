const int botao1 = 2;
const int botao2 = 3;
const int leds[] = {5,6,7,8};

int etapa = 0;
unsigned long tempoAnterior = 0;

void setup() {
  for(int i=0;i<4;i++) pinMode(leds[i], OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(botao2)==LOW){
    for(int i=0;i<4;i++) digitalWrite(leds[i],LOW);
    etapa=0;
  }

  if(digitalRead(botao1)==LOW && etapa==0){
    etapa=1;
    tempoAnterior=millis();
  }

  if(etapa>0 && etapa<=4 && millis()-tempoAnterior>=1000){
    digitalWrite(leds[etapa-1],HIGH);
    tempoAnterior=millis();
    etapa++;
  }
}