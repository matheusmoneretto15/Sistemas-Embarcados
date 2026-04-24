const int botaoInicio = 2;
const int botaoContagem = 3;
const int ledMotor = 9;
const int ledVerificar = 10;

int contador = 0;
bool sistemaAtivo = false;

// Controle de tempo (piscar LED)
unsigned long tempoAnterior = 0;
const int intervalo = 600;
bool estadoLedVerificar = false;

// Controle de clique (anti-repetição simples)
bool ultimoEstadoContagem = HIGH;
bool ultimoEstadoInicio = HIGH;

void setup() {
  pinMode(botaoInicio, INPUT_PULLUP);
  pinMode(botaoContagem, INPUT_PULLUP);
  pinMode(ledMotor, OUTPUT);
  pinMode(ledVerificar, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  bool estadoInicio = digitalRead(botaoInicio);
  bool estadoContagem = digitalRead(botaoContagem);

  // 🔵 BOTÃO INICIO (reset e start)
  if (estadoInicio == LOW && ultimoEstadoInicio == HIGH) {
    contador = 0;
    sistemaAtivo = true;

    digitalWrite(ledMotor, HIGH);
    digitalWrite(ledVerificar, LOW);

    Serial.println("Sistema iniciado - contador = 0");
  }
  ultimoEstadoInicio = estadoInicio;

  // 🟢 BOTÃO CONTAGEM
  if (sistemaAtivo && estadoContagem == LOW && ultimoEstadoContagem == HIGH) {
    contador++;
    Serial.print("Contagem: ");
    Serial.println(contador);

    if (contador >= 60) {
      sistemaAtivo = false;
      digitalWrite(ledMotor, LOW);
    }
  }
  ultimoEstadoContagem = estadoContagem;

  // 🔴 LED VERIFICAR (piscando com millis)
  if (!sistemaAtivo && contador >= 60) {
    unsigned long tempoAtual = millis();

    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;
      estadoLedVerificar = !estadoLedVerificar;
      digitalWrite(ledVerificar, estadoLedVerificar);
    }
  } else {
    digitalWrite(ledVerificar, LOW);
  }
}