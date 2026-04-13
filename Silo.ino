const int pot = A0;
const int valvula = 5;
const int alarme = 6;

bool travado = false;
unsigned long tempoAnterior = 0;
bool pisca = false;

void setup() {
  pinMode(valvula, OUTPUT);
  pinMode(alarme, OUTPUT);
}

void loop() {
  int nivel = analogRead(pot);

  if(nivel >= 972){ //95%
    travado = true;
  }

  if(travado){
    digitalWrite(valvula, LOW);

    if(millis()-tempoAnterior>=300){
      tempoAnterior=millis();
      pisca=!pisca;
      digitalWrite(alarme,pisca);
    }

    if(nivel <= 307){ //30%
      travado=false;
    }
  } else {
    digitalWrite(alarme, LOW);
    if(nivel < 819) digitalWrite(valvula, HIGH); //80%
    else digitalWrite(valvula, LOW);
  }
}