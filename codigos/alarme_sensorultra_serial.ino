// Código do funcionamento básico do sensor ultrassônico com resposta serial da distância.

int trigPin = 12;
int echoPin = 13;


void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() {
long duration, distance;
// Configura o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
digitalWrite(trigPin, LOW);
delayMicroseconds(2); // Aguarda 2 microssegundos

// Configura o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
digitalWrite(trigPin, HIGH);
delayMicroseconds(10); // Aguarda 10 microssegundos
// Configura o pino 12 com pulso baixo novamente
digitalWrite(trigPin, LOW);
// PulseIn lê o tempo entre a chamada e o pino entrar em High
duration = pulseIn(echoPin, HIGH);

/*Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado
porque é o tempo de ida e volta do ultrassom */

distance = ((duration/2) / 29.1);

Serial.print(distance);
Serial.println(" Cm");

delay(500);
}
