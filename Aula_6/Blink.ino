 const int led1 = 8;
 const int led2 = 9;

const long intervalo = 1000;
unsigned long tempoAn = 0;

bool estado = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(115200);
  
  
  }

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long tempo_atual = millis();
  if (tempo_atual - tempoAn >= intervalo) {
    estado = !estado;
    digitalWrite(led1, estado);
    tempoAn = tempo_atual;
    Serial.print("1 segundo");
  }

  if (tempo_atual - tempoAn >= intervalo) {
    estado = !estado;
    digitalWrite(led2, estado);
    tempoAn = tempo_atual;
    Serial.print("1 segundo");
  }
}
