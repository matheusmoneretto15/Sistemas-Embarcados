```cpp
/*
=====================================================
🧠 GUIA DE PROVA ARDUINO (COLA RÁPIDA)
=====================================================

🔘 BOTÃO (entrada digital)
→ usar quando tiver botão / liga-desliga
-----------------------------------------------------
pinMode(botao, INPUT_PULLUP);
bool leitura = digitalRead(botao);

if (leitura == LOW && ultimo == HIGH) {
  // clique detectado
}
ultimo = leitura;

-----------------------------------------------------

🔢 CONTADOR
→ usar quando tiver “contar”, “incrementar”
-----------------------------------------------------
contador++;

-----------------------------------------------------

🎯 CONDIÇÃO / LIMITE
→ usar quando tiver “até atingir X”
-----------------------------------------------------
if (contador >= X) {
  // ação
}

-----------------------------------------------------

🔁 ESTADO DO SISTEMA
→ usar quando tiver “iniciar / parar”
-----------------------------------------------------
bool ativo = false;

if (botaoInicio) {
  ativo = true;
}

if (ativo) {
  // executa sistema
}

-----------------------------------------------------

⏱️ TEMPO (millis)
→ usar quando tiver “piscar”, “tempo”, “sem delay”
-----------------------------------------------------
unsigned long tempoAnt = 0;
int intervalo = 1000;

if (millis() - tempoAnt >= intervalo) {
  tempoAnt = millis();
  // ação (ex: piscar LED)
}

-----------------------------------------------------

🎚️ POTENCIÔMETRO (entrada analógica)
→ usar quando tiver “valor variável”
-----------------------------------------------------
int valor = analogRead(A0); // 0–1023

-----------------------------------------------------

🔄 MAP (converter escala)
→ usar quando precisar transformar valores
-----------------------------------------------------
int novo = map(valor, 0, 1023, 0, 255);

-----------------------------------------------------

⚙️ PWM (controle de intensidade)
→ usar para brilho/velocidade
-----------------------------------------------------
analogWrite(pino, valorPWM);

-----------------------------------------------------

🔥 DECISÃO RÁPIDA (LEITURA DO ENUNCIADO)

tem botão? → digitalRead
tem contagem? → contador++
tem limite? → if (contador >= X)
tem tempo? → millis
tem potenciômetro? → analogRead + map
tem sistema (iniciar/parar)? → bool ativo

-----------------------------------------------------

⚠️ ERROS QUE NÃO PODE COMETER

- esquecer INPUT_PULLUP
- esquecer que botão pressionado = LOW
- usar delay() quando pedir millis
- não detectar clique (borda)
- esquecer map() no potenciômetro

-----------------------------------------------------

🏁 REGRA FINAL

ENTRADA → PROCESSO → SAÍDA

=====================================================
*/
```
