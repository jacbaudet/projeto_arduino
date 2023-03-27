// 5ª versão do código do projeto
// Descrição: Implementação da comunicação serial para interrupção momentânea do alarme.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#include <Arduino.h>                          // Apenas para o uso no PlataformIO
#include <SPI.h>

int led = 6;                                  // Porta digital D6 é definido como o Led
int buzzer = 5;                               // Porta digital D5 é definido como o Buzzer
int trigPin = 12;                             // Porta digital D12 = Trigger (Sensor Ultrassônico)
int echoPin = 13;                             // Porta digital D13 = Echo (Sensor Ultrassônico)
long duration, distance;                      // Variáveis "long" para cálculo da distância e duração (tempo) do som
String resposta = "";                         // Variável string para resposta do monitor
bool status = false;                          // Variável para interrupção do alarme


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);                   // Trigger = Saída (emissão do som)
  pinMode(echoPin, INPUT);                    // Echo = Entrada (detecção do som)
  pinMode(buzzer, OUTPUT);                    // Buzzer = Saída
  pinMode(led, OUTPUT);                       // Led = Saída
}

void loop() {
  digitalWrite(trigPin, LOW);                // Configura o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
  delayMicroseconds(10);                     // Aguarda 10 microssegundos 

  digitalWrite(trigPin, HIGH);               // Configura o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  delayMicroseconds(10);                     // Aguarda 10 microssegundos

  digitalWrite(trigPin, LOW);                // Configura o pino 12 com pulso baixo novamente

  duration = pulseIn(echoPin, HIGH);         // PulseIn lê o tempo entre a chamada e o pino entrar em High

  distance = ((duration/2) / 29.1);          // Cálculo da distância considerando que "duration" é o tempo em micro segundos de ida e volta.
  // Resultado em centímetros!

  resposta = Serial.readString();            // Lê a entrada serial
  if(resposta.indexOf("ok")!=-1){            // Configura o status se a string é ok
    status = true;
  } else {                                  
    status = false;
  }

  if(distance < 30){
    if(status == false){
      digitalWrite(led, HIGH);               // Led liga
      digitalWrite(buzzer, HIGH);            // Buzzer liga
      
      Serial.print("Alguém próximo a ");
      Serial.print(distance);
      Serial.println(" cm!");
    } else {
      digitalWrite(led, LOW);                // Led desliga
      digitalWrite(buzzer, LOW);             // Buzzer desliga
      
      Serial.println("Alarme desligado.");
    }
  } else {
    digitalWrite(led, LOW);                   // Led desliga
    digitalWrite(buzzer, LOW);                // Buzzer desliga
    
    Serial.println("Ninguém perto.");
  }

  delay(1000);
}
