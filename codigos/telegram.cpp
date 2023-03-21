#include <TelegramClient.h>
#include <SoftwareSerial.h>

// Dados de acesso ao bot do Telegram
const char* token = "INSIRA_AQUI_SEU_TOKEN";
const char* chat_id = "INSIRA_AQUI_SEU_CHAT_ID";

// Configuração do sensor ultrassônico
int trigPin = 2;
int echoPin = 3;

// Variáveis para medir a distância
long duration;
int distance;

// Inicializa o cliente Telegram
SoftwareSerial mySerial(10, 11); // RX, TX
TelegramClient telegram(mySerial, token);

void setup() {
  // Inicializa a porta serial para debug
  Serial.begin(9600);

  // Configura os pinos do sensor ultrassônico como entrada e saída
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Inicializa a comunicação com o Telegram
  mySerial.begin(9600);
  telegram.begin();
}

void loop() {
  // Envia um pulso no pino de trigger do sensor ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lê o tempo necessário para o som ir e voltar do objeto
  duration = pulseIn(echoPin, HIGH);

  // Calcula a distância em centímetros
  distance = duration * 0.034 / 2;

  // Verifica se a distância é menor que um certo valor
  if (distance < 10) {
    String message = "Objeto detectado a " + String(distance) + "cm!";
    if (telegram.sendMessage(chat_id, message)) {
      Serial.println("Mensagem enviada com sucesso!");
    } else {
      Serial.println("Erro ao enviar mensagem");
    }
  }

  // Aguarda um curto período antes de verificar novamente a distância
  delay(100);
}