const int pin_botao_start = 2;
const int pin_botao_stop = 3;

const int motor_AH = 6;
const int motor_H = 7;

const int pin_sensor_3 = 9;
const int pin_sensor_4 = 10;

const int pin_sensor_1 = 11;
const int pin_sensor_2 = 12;

int CA = 0;
int CB = 0;

int estado = 0;

unsigned long tempo_anterior = 0, tempo_atual = 0;



void setup() {
  pinMode(pin_botao_start, INPUT_PULLUP);
  pinMode(pin_botao_stop, INPUT_PULLUP);

  pinMode(pin_sensor_3, INPUT);
  pinMode(pin_sensor_4, INPUT);
  pinMode(pin_sensor_1, INPUT);
  pinMode(pin_sensor_2, INPUT);

  pinMode(Motor_Anti_horario, OUTPUT);
  pinMode(Motor_horari, OUTPUT);
}

void loop() {

  bool S3 = digitalRead(pin_sensor_3);
  bool S4 = digitalRead(pin_sensor_4);
  bool S1 = digitalRead(pin_sensor_1);
  bool S2 = digitalRead(pin_sensor_2);




  bool stop = digitalRead(pin_botao_stop);
  if (stop == 0) {
    estado = 0;
  }

  switch (estado) {
    case 0:
      bool start = digitalRead(pin_botao_start);
      if (start == 0) {
        estado = 1;
        tempo_anterior = millis();
      }
      break;

    case 1:
      tempo_atual = millis();
      if (tempo_atual - tempo_anterior > 2000) {
        estado = 2;
      }
      break;

    case 2:
      if (S3 == 1 && S4 == 1) {
        estado = 3;
      } else if (S3 == 1 && S4 == 0) {
        estado = 4;
      }
      break;

    case 3:
      Motor_Anti_horario = 1;
      if (S1 == 1) {
        estado = 5;
      }
      break;

    case 4:
      Motor_horario = 1;
      if (S2 == 1) {
        estado = 6;
      }
      break;

    case 5:
      Motor_Anti_horario = 0;
      CA++;
      estado = 1;
      tempo_anterior = millis();
      break;

    case 6:
      Motor_horario = 0;
      CB++;
      estado = 1;
      tempo_anterior = millis();
      break;

     default:
      estado = 0; 
  }
}
