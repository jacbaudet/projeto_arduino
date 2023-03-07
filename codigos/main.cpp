#include <Arduino.h>

int led = 12;                                 // Porta digital D12 é definido como o Led
int buzzer = 10;                              // Porta digital D10 é definido como o Buzzer
int sensor = 0;                               // Porta analógica A0 é definida como Sensor

void setup() {
  pinMode(sensor, INPUT);                      // Sensor = Entrada
  pinMode(buzzer, OUTPUT);                     // Buzzer = Saída
  pinMode(led, OUTPUT);                        // Led = Saída
}

void loop() {
  int ir = analogRead(sensor);                // Leitura do sensor
  if(ir < 150) {                              // Se o valor for menor que 150 o Led e o Buzzer são ativados (150 = distância válida do sensor)
    digitalWrite(led, HIGH);                  // Led liga
    digitalWrite(buzzer, HIGH);               // Buzzer liga
  }
  else {                                      // Se o valor não diminuir ou voltar a 150, ambos são desativados
    digitalWrite(led, LOW);                   // Led desliga
    digitalWrite(buzzer, LOW);                // Buzzer desliga
  }
}
