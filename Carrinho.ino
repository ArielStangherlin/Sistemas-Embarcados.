/*
  SEGUIDOR DE LINHA

  Esse projeto tem como base produzir um carrinho seguidor de linha com 5 sensores funcionais, utilzando-se de Ponte H (L298N), Arduino UNO, 2 Motores DC e um Módulo IR TCRT5000,
  para fins educativos à favor de dois modos: Concluir 1 volta no menor tempo possível e reproduzir 20 voltas completas em teste de resistência. Tal avaliação e materiais foi dis-
  ponibilizada mediante a SATC( Cricíuma/SC ), para os alunos mecatrônicos.

  Data: 22/06/2026
  Curso: Mecatrônica 
  Disciplina: Sistemas Embarcados
  Professor: Marcos Coelho
  Autores: Ariel Tasca Stangherlin, João Coral.

  Versão: 2.1

*/

// Sensores
const int PIN_S0 = 8;  // Extremo Esquerdo
const int PIN_S1 = 9;  // Interno Esquerdo
const int PIN_S2 = 10; // Central
const int PIN_S3 = 11; // Interno Direito
const int PIN_S4 = 12; // Extremo Direito

int s[5] = {0, 0, 0, 0, 0};

// Ponte H
const int ENA = 3; // Motor Direito
const int IN1 = 2; // Direito Trás
const int IN2 = 4; // Direito Frente

const int IN3 = 6; // Esquerdo Frente
const int IN4 = 7; // Esquerdo Trás
const int ENB = 5; // Motor Esquerdo

void setup() {
  Serial.begin(9600);

  pinMode(PIN_S0, INPUT);
  pinMode(PIN_S1, INPUT);
  pinMode(PIN_S2, INPUT);
  pinMode(PIN_S3, INPUT);
  pinMode(PIN_S4, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  s[0] = digitalRead(PIN_S0);
  s[1] = digitalRead(PIN_S1);
  s[2] = digitalRead(PIN_S2);
  s[3] = digitalRead(PIN_S3);
  s[4] = digitalRead(PIN_S4);

  if (s[1] == 1 && s[2] == 1 && s[3] == 1) {
    // Sentido Frente
    analogWrite(ENA, 120);
    analogWrite(ENB, 200);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

  } else if (s[0] == 0 && s[1] == 0 && s[2] == 1 && s[3] == 1 && s[4] == 0) {
    // Corrige Oscilação Esquerda
    analogWrite(ENA, 100);
    analogWrite(ENB, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

  } else if (s[0] == 0 && s[1] == 1 && s[2] == 1 && s[3] == 0 && s[4] == 0) {
    // Corrige Oscilação Direita
    analogWrite(ENA, 200);
    analogWrite(ENB, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

  } else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 0) {
    // Leve Inclinação Esquerda
    Serial.println("LEVE ESQUERDA");
    analogWrite(ENA, 80);
    analogWrite(ENB, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

  } else if (s[0] == 0 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0) {
    // Leve Inclinação Direita
    Serial.println("LEVE DIREITA");
    analogWrite(ENA, 195);
    analogWrite(ENB, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

  } else if (s[0] == 1 && s[1] == 1 && s[2] == 0 && s[3] == 0 && s[4] == 0) {
    // Mudança Mediana Esquerda
    Serial.println("MEDIANA ESQUERDA");
    analogWrite(ENA, 255);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

  } else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 1 && s[4] == 1) {
    // Mudança Mediana Direita
    Serial.println("MEDIANA DIREITA");
    analogWrite(ENA, 0);
    analogWrite(ENB, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

  } else if (s[0] == 0 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 1) {
    // Mudança Abrupta Direita: Direito ré, esquerdo frente
    Serial.println("ABRUPTA DIREITA");
    analogWrite(ENA, 110);
    analogWrite(ENB, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

  } else if (s[0] == 1 && s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0) {
    // Mudança Abrupta Esquerda: Esquerdo ré, direito frente
    Serial.println("ABRUPTA ESQUERDA");
    analogWrite(ENA, 255);
    analogWrite(ENB, 200);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

  } else {
    // Sem pista 
    Serial.println("STAND-BY");
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

    

}