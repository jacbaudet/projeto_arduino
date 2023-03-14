// 3ª versão do código do projeto
// Descrição: Tentativa de fazer o código final do projeto, com todos os componentes e integrado à Ethernet e ao Telegram.
// Obs: os comandos "bot.sendMessage" estão dando erro!
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bibliotecas
#include <Arduino.h>                         // Apenas para o uso no PlataformIO
#include <SPI.h>                             // Protocolo de comunicação da Ethernet com o Arduino
#include <Ethernet.h>            
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Configuração da rede
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);
EthernetClient client;
// EthernetServer server(80); 
// Cria um server? DUVIDA ----------------------- !!!!

// Configuração do Telegram Bot
const char* token = "5979365076:AAGWnYd2gprJYNIIut89gJnzowKzRkjAIXQ";
const int chat_id = 1028002612;
UniversalTelegramBot bot(token, client);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int led = 6;                                 // Porta digital D6 = Led
int buzzer = 5;                              // Porta digital D5 = Buzzer
int trigPin = 12;                            // Porta digital D12 = Trigger (Sensor Ultrassônico)
int echoPin = 13;                            // Porta digital D13 = Echo (Sensor Ultrassônico)

long duration, distance;                     // Variáveis "long" para cálculo da distância e duração (tempo) do som

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  // Server.begin(); // ------------------------- !!!!
  
  pinMode(trigPin, OUTPUT);                  // Trigger = Saída (emissão do som)
  pinMode(echoPin, INPUT);                   // Echo = Entrada (detecção do som)
  pinMode(buzzer, OUTPUT);                   // Buzzer = Saída
  pinMode(led, OUTPUT);                      // Led = Saída
}

void loop() {
  digitalWrite(trigPin, LOW);                // Configura o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
  delayMicroseconds(10);                     // Aguarda 10 microssegundos
  
  digitalWrite(trigPin, HIGH);               // Configura o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  delayMicroseconds(10);                     // Aguarda 10 microssegundos

  digitalWrite(trigPin, LOW);                // Configura o pino 12 com pulso baixo novamente

  duration = pulseIn(echoPin, HIGH);         // PulseIn lê o tempo entre a chamada e o pino entrar em High
  distance = ((duration/2)*0.034029);        // Cálculo da distância considerando que "duration" é o tempo em micro segundos de ida e volta. Resultado em centímetros!

  // Serial.print(distance);
  // Serial.println(" cm");

  delay(50);

  if(distance < 30) {                         // Se o valor for menor que 30cm o Led e o Buzzer são ativados (30 = distância válida do sensor)
    digitalWrite(led, HIGH);                  // Led liga
    digitalWrite(buzzer, HIGH);               // Buzzer liga

    bot.sendMessage(chat_id, "Mensagem de notificação: alguém perto!");
  }
  else {                                      // Se não, ambos são desativados
    digitalWrite(led, LOW);                   // Led desliga
    digitalWrite(buzzer, LOW);                // Buzzer desliga

    bot.sendMessage(chat_id, "Mensagem de notificação: ninguém perto.");
  }
}
