/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Seleção simples

Autor: Marcos Antonio Jeremias Coelho
Data: 06/03/2023
Versão: 1.0

************************************************************************ */
const int pin_botao = 2;	
const int pin_botao = 3;	
const int led_vermelho = 5;  //
const int led_verde = 6;     //
const int led_amarelo = 7;   //
char led;                    //

void setup() {
  pinMode(led_vermelho, OUTPUT);  //
  pinMode(led_verde, OUTPUT);     //
  pinMode(led_amarelo, OUTPUT);   //
  Serial.begin(115200);           // Definição da velocide de transmissão em 115200 bps
}

void loop() {
  if (Serial.available()) {              //
    led = Serial.read();                 //
    if (led == 'R') {                    // Led vermelho - red
      digitalWrite(led_vermelho, HIGH);  // Acende led
    }
    if (led == 'r') {                   // Led vermelho - red
      digitalWrite(led_vermelho, LOW);  // Apaga led
    }
    if (led == 'G') {                 // Led verde - green
      digitalWrite(led_verde, HIGH);  // Acende led
    }
    if (led == 'g') {                // Led verde - green
      digitalWrite(led_verde, LOW);  // Apaga led
    }
    if (led == 'Y') {                   // Led amarelo - yellow
      digitalWrite(led_amarelo, HIGH);  // Acende led
    }
    if (led == 'y') {                  // Led amarelo - yellow
      digitalWrite(led_amarelo, LOW);  // Apaga led
    }
    if (led == 'T') {                   //
      digitalWrite(led_amarelo, HIGH);  // ACENDE leds
      digitalWrite(led_vermelho, HIGH);
      digitalWrite(led_verde, HIGH);
    }
    if (led == 't') {                  //
      digitalWrite(led_amarelo, LOW);  // APAGA leds
      digitalWrite(led_vermelho, LOW);
      digitalWrite(led_verde, LOW);
    }
  }
}
