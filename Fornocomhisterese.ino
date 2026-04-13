const int botao = 2;
const int ntc = A0;
const int aquec = 5;
const int faixa = 6;

bool ligado=false;

void setup(){
  pinMode(botao, INPUT_PULLUP);
  pinMode(aquec, OUTPUT);
  pinMode(faixa, OUTPUT);
}

void loop(){
  if(digitalRead(botao)==LOW) ligado=true;

  int temp = analogRead(ntc);

  if(ligado){
    if(temp < 500) digitalWrite(aquec,HIGH);
    if(temp > 600) digitalWrite(aquec,LOW);

    if(temp >=500 && temp <=600) digitalWrite(faixa,HIGH);
    else digitalWrite(faixa,LOW);
  }
}