const int ntc = A0;
const int ventilador = 5;

// Ajustes
int tempMin = 300;
int tempMax = 800;

// Média móvel sem delay
const int numLeituras = 10;
int leituras[numLeituras];
int indice = 0;
long soma = 0;
int tempFiltrada = 0;

unsigned long tempoAnterior = 0;
const int intervalo = 10; // ms entre leituras

void setup() {
  pinMode(ventilador, OUTPUT);

  // Inicializa vetor
  for (int i = 0; i < numLeituras; i++) {
    leituras[i] = 0;
  }
}

void loop() {
  unsigned long agora = millis();

  // 🔹 Leitura periódica sem travar
  if (agora - tempoAnterior >= intervalo) {
    tempoAnterior = agora;

    // Remove valor antigo da soma
    soma -= leituras[indice];

    // Nova leitura
    leituras[indice] = analogRead(ntc);

    // Soma nova leitura
    soma += leituras[indice];

    // Avança índice circular
    indice++;
    if (indice >= numLeituras) indice = 0;

    // Calcula média
    tempFiltrada = soma / numLeituras;
  }

  // 🔹 Controle proporcional
  int pwm;

  if (tempFiltrada <= tempMin) {
    pwm = 50; // mínimo
  }
  else if (tempFiltrada >= tempMax) {
    pwm = 255; // máximo
  }
  else {
    pwm = map(tempFiltrada, tempMin, tempMax, 50, 255);
  }

  analogWrite(ventilador, pwm);
}