#include <Arduino.h>

int led = 6;                                 // Porta digital D12 é definido como o Led
int buzzer = 5;                              // Porta digital D10 é definido como o Buzzer
// int sensor = 0;                               // Porta analógica A0 é definida como Sensor
int trigPin = 12;
int echoPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // pinMode(sensor, INPUT);                      // Sensor = Entrada
  pinMode(buzzer, OUTPUT);                     // Buzzer = Saída
  pinMode(led, OUTPUT);                        // Led = Saída
}

void loop() {
  long duration, distance;
  const estado = FALSE
  // Configura o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  
  // Configura o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  // Configura o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Aguarda 10 microssegundos
  // Configura o pino 12 com pulso baixo novamente
  digitalWrite(trigPin, LOW);
  // PulseIn lê o tempo entre a chamada e o pino entrar em High
  duration = pulseIn(echoPin, HIGH);

  distance = ((duration/2) / 29.1);

  Serial.print(distance);
  Serial.println(" cm");

  delay(50);

  // int ir = analogRead(sensor);                // Leitura do sensor
  if(distance < 30) {                         // Se o valor for menor que 150 o Led e o Buzzer são ativados (150 = distância válida do sensor)
    digitalWrite(led, HIGH);                  // Led liga
    digitalWrite(buzzer, HIGH);               // Buzzer liga
  }
  else {                                      // Se o valor não diminuir ou voltar a 150, ambos são desativados
    digitalWrite(led, LOW);                   // Led desliga
    digitalWrite(buzzer, LOW);                // Buzzer desliga
  }
}
