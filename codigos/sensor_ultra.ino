// Código paralelo do projeto
// Descrição: Código do funcionamento básico do sensor ultrassônico com resposta serial da distância.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int trigPin = 12;                         // Pino digital 12 = Trigger (Sensor Ultrassônico)
int echoPin = 13;                         // Pino digital 13 = Echo (Sensor Ultrassônico)


void setup() {
Serial.begin (9600); 
pinMode(trigPin, OUTPUT);                 // Trigger = Saída do ultrassom (emissão)
pinMode(echoPin, INPUT);                  // Echo = Entrada do ultrassom (detecção)
}

void loop() {
long duration, distance;                  // Define as variáveis "long" de distância e duração (tempo)
  
digitalWrite(trigPin, LOW);               // Configura o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
delayMicroseconds(2);                     // Aguarda 2 microssegundos

digitalWrite(trigPin, HIGH);              // Configura o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
delayMicroseconds(10);                    // Aguarda 10 microssegundos
  
digitalWrite(trigPin, LOW);               // Configura o pino 12 com pulso baixo novamente
duration = pulseIn(echoPin, HIGH);        // PulseIn lê o tempo entre a chamada e o pino entrar em HIGH

// O calculo é baseado em S = V * t, lembrando que o tempo vem dobrado porque é de ida e volta do ultrassom
distance = ((duration/2) / 29.1);

Serial.print(distance);                  // Escreve a distância percorrida em centímetros
Serial.println(" Cm");

delay(500);                              // Aguarda 500ms para o próximo loop
}
