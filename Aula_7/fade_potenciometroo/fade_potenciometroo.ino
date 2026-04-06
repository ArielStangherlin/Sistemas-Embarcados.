int LED1 = 9;
const int valor_sensor = A0;
void loop() {
    int valor_analogico = analogRead(valor_sensor);
    int valor = (valor_analogico / 4);
    analogWrite(LED1, valor);
}