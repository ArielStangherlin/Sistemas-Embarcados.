const byte pinoSomar = 2;
const byte pinoSubtrair = 3;
int contador = 0;


unsigned long ultimoDebounceSomar = 0;
unsigned long ultimoDebounceSubtrair = 0;
const int tempoDebounce = 50; 


static bool ultimoEstadoSomar = HIGH;
static bool ultimoEstadoSubtrair = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(pinoSomar, INPUT_PULLUP);
  pinMode(pinoSubtrair, INPUT_PULLUP);
  Serial.println("Sistema de Contagem (+/-) Pronto!");
}

void loop() {
  unsigned long tempoAtual = millis();

  
  bool leituraSomar = digitalRead(pinoSomar);
  if (leituraSomar != ultimoEstadoSomar) {
    ultimoDebounceSomar = tempoAtual;
  }
  if ((tempoAtual - ultimoDebounceSomar) > tempoDebounce) {
    static bool estadoEstavelSomar = HIGH;
    if (leituraSomar == LOW && estadoEstavelSomar == HIGH) {
      contador++;
      exibirContador();
    }
    estadoEstavelSomar = leituraSomar;
  }
  ultimoEstadoSomar = leituraSomar;


  
  bool leituraSubtrair = digitalRead(pinoSubtrair);
  if (leituraSubtrair != ultimoEstadoSubtrair) {
    ultimoDebounceSubtrair = tempoAtual;
  }
  if ((tempoAtual - ultimoDebounceSubtrair) > tempoDebounce) {
    static bool estadoEstavelSubtrair = HIGH;
    if (leituraSubtrair == LOW && estadoEstavelSubtrair == HIGH) {
      contador--;
      exibirContador();
    }
    estadoEstavelSubtrair = leituraSubtrair;
  }
  ultimoEstadoSubtrair = leituraSubtrair;
}


void exibirContador() {
  Serial.print("Valor Atual: ");
  Serial.println(contador);
}