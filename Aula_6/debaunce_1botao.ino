const int pin_botao = 2; 
const int pin_botao2 = 3;

const int pin_led = 8;
const int pin_led2 = 9;

int estado_led = LOW;
int estado_led2 = LOW;

int estado_botao2;
int estado_botao;

int ultimo_estado_botao = HIGH;
int ultimo_estado_botao2 = HIGH;

unsigned long tempo_debounce = 0; 
unsigned long tempo_debounce2 = 0;

unsigned long atraso = 50;

void setup() {
pinMode(pin_botao, INPUT_PULLUP);
pinMode(pin_botao2, INPUT_PULLUP);


pinMode(pin_led, OUTPUT);
pinMode(pin_led2, OUTPUT);

digitalWrite(pin_led, estado_led);
digitalWrite(pin_led2, estado_led);

}

void loop() {
int leitura = digitalRead(pin_botao);
if (leitura != ultimo_estado_botao) {
  tempo_debounce = millis(); 
}
if ((millis() - tempo_debounce) > atraso);
{ 
  if (leitura != estado_botao) {
    estado_botao = leitura;
    if (estado_botao == LOW) {
      estado_led = !estado_led;
    }
  }

}
digitalWrite(pin_led, estado_led); 
ultimo_estado_botao = leitura;

//

int leitura2 = digitalRead(pin_botao2);
if (leitura2 != ultimo_estado_botao2) {
  tempo_debounce = millis(); 
}
if ((millis() - tempo_debounce) > atraso);
{ 
  if (leitura2 != estado_botao2) {
    estado_botao2 = leitura2;
    if (estado_botao2 == LOW) {
      estado_led2 = !estado_led2;
    }
  }

}
digitalWrite(pin_led2, estado_led2); 
ultimo_estado_botao2 = leitura2;

}
