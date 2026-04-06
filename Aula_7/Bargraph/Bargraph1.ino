int pin_sensor = A0;
int valor_sensor = 0;

const byte LED1 = 9;
const byte LED2 = 10;
const byte LED3 = 11;

unsigned long intervalo = 200;
unsigned long tempoA = 0;


int estado = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(pin_sensor, INPUT);
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor_sensor = analogRead(pin_sensor);
  float valor_tensao = (valor_sensor * 5.0)/1023;

  if (valor_tensao >= 4) {
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 1);
  } else if (valor_tensao >= 3) {
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 1);
  } else if (valor_tensao >= 2) {
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 1);
    digitalWrite(LED3, 0);
  } else if (valor_tensao >= 1) {
    digitalWrite(LED1, 1);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
  } else if (valor_tensao < 1) {
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
  } 
}

 