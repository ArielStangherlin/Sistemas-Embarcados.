int sensor = A0;
int valor_sensor = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(sensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor_sensor = analogRead(sensor);

  Serial.print("Valor analógico: ");
  Serial.println(valor_sensor);
  delay(200);
}
