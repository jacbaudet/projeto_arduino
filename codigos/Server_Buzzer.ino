#include <SPI.h> 
#include <Ethernet.h> 

byte mac[] = {0xCA, 0xFE, 0xBA, 0xBE, 0xFE, 0xED};
byte ip[]      = {192,  168,  1, 177}; 
byte gateway[] = {192,  168,  1, 170}; 
byte subnet[]  = {255, 255, 255, 0}; 
EthernetServer server(80); 

const int greenLedPin = 6; 
const int   redLedPin = 7; 
String readString = String(30); 
int status = 0; 

int led = 6;                                 // Porta digital D12 é definido como o Led
int buzzer = 5;                              // Porta digital D10 é definido como o Buzzer
int trigPin = 12;
int echoPin = 13;

void setup(){
  Ethernet.begin(mac, ip, gateway, subnet); 
  server.begin(); 

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);                     // Buzzer = Saída
  pinMode(led, OUTPUT);                        // Led = Saída
}

void loop(){
  EthernetClient client = server.available(); 
  long duration, distance;

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
  delay(50);

  if (client) { 
     while (client.connected()) {
       if (client.available()) { 
       char c = client.read(); 
       if (readString.length() < 100) {
         readString += c; 
       }  
       if (c == '\n') { 
         if (readString.indexOf("?") < 0) { 
         }
         else 
           if(readString.indexOf("ledParam=1") > 0) {
             digitalWrite(greenLedPin, HIGH); 
             digitalWrite(redLedPin, LOW); 
             status = 1; 
           } 
           else { 
             digitalWrite(greenLedPin, LOW); 
             digitalWrite(redLedPin, HIGH); 
             status = 0; 
           }
           client.println("HTTP/1.1 200 OK"); 
           client.println("Content-Type: text/html"); 
           client.println(""); 
           client.println("<!DOCTYPE HTML>"); 
           client.println("<html>"); 
           client.println("<head>");
           client.println("<title>Alarmezinho</title>"); 
           client.println("</head>"); 
           client.println("<body style=background-color:#E0E0E0; color:#2b3856>"); 
           client.println("<center>");
           client.println("<h1>Status Alarmezinho</h1>");
           client.println("<hr/>"); 
           client.println("<h2>OI:</h2>"); 
           if (status == 1) { 
             client.println("<form method=get name=LED><input type=hidden name=ledParam value=0 /><input type=submit value=VERMELHO /></form>");
           }
           else { 
             client.println("<form method=get name=LED><input type=hidden name=ledParam value=1 /><input type=submit value=VERDE /></form>");
           }
           client.println("<hr/>"); 
           client.println("<h2>Status do LED:</h2>"); 
           if (status == 1){ 
             client.println("<font color='green' size='5'>VERDE</font>"); 
           } 
           else { 
             client.println("<font color='red' size='5'>VERMELHO</font>"); 
           }     
           client.println("<hr/>"); 
           client.println("</center>");
           client.println("</body>"); 
           client.println("</html>"); 
           readString=""; 
           client.stop(); 
         }
       }
     }
   }
 }
