const int start = 2;
const int sensor = 3;
const int led = 5;

int cont = 0;
bool rodando = false;
unsigned long pausa = 0;

void setup(){
  pinMode(start, INPUT_PULLUP);
  pinMode(sensor, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop(){
  if(digitalRead(start)==LOW) rodando=true;

  if(rodando){
    digitalWrite(led,HIGH);

    if(digitalRead(sensor)==LOW){
      cont++;
      delay(200);
    }

    if(cont%5==0 && cont!=0){
      digitalWrite(led,LOW);
      delay(3000);
    }

    if(cont>=20){
      rodando=false;
      digitalWrite(led,LOW);
    }
  }
}