```cpp id="pot123"
// =====================
// PINOS
// =====================
int potenciometro = A0; // pino analógico
int led = 9;            // pino PWM

// =====================
// VARIÁVEIS
// =====================
int valorADC = 0;  // valor lido (0 a 1023)
int valorPWM = 0;  // valor convertido (0 a 255)

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // =====================
  // 1. LEITURA ANALÓGICA
  // =====================
  valorADC = analogRead(potenciometro);

  // =====================
  // 2. CONVERSÃO (ESCALA)
  // =====================
  // transforma 0–1023 em 0–255 (PWM)
  valorPWM = map(valorADC, 0, 1023, 0, 255);

  // =====================
  // 3. AÇÃO (PWM)
  // =====================
  analogWrite(led, valorPWM);

  // =====================
  // 4. DEBUG (OPCIONAL)
  // =====================
  Serial.print("ADC: ");
  Serial.print(valorADC);
  Serial.print(" | PWM: ");
  Serial.println(valorPWM);
}
```

