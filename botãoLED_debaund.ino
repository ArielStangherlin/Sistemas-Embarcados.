const int botao = 2;
const int led = 12;

bool estadoLed = HIGH; // começa desligado
bool estadoBotao = HIGH;
bool ultimoEstadoBotao = HIGH;

unsigned long ultimoTempoDebounce = 0;
unsigned long delayDebounce = 50;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  pinMode(led, OUTPUT);

  digitalWrite(led, estadoLed); // garante que começa desligado
}

void loop() {
  int leitura = digitalRead(botao);

  if (leitura != ultimoEstadoBotao) {
    ultimoTempoDebounce = millis();
  }

  if ((millis() - ultimoTempoDebounce) > delayDebounce) {
    if (leitura != estadoBotao) {
      estadoBotao = leitura;

      if (estadoBotao == LOW) { // botão pressionado
        estadoLed = !estadoLed; // alterna estado
      }
    }
  }

  digitalWrite(led, estadoLed);

  ultimoEstadoBotao = leitura;
}