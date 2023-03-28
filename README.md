# Microcontroladores e IoT
> Trabalho final da disciplina de Microprocessadores e Microcontroladores. 

Integrante | RA
----------- | ---------
Jacqueline Louise Baudet | 758704
Daniel Ferezin Ferrari | 744638 
João Pedro Pinto Dias | 758725

## Projeto: Sistema de segurança de ambiente (Alarme)
### :beginner: Proposta
#### Descrição Geral
Um sistema de segurança por sensor ultrassônico que monitora a passagem de pessoas quando ativado. Ao ser acionado, o sistema entra em estado de alarme com LEDs vermelhos acesos, um dispositivo sonoro que transmite uma determinada frase e uma câmera que fotografa o momento da passagem.

#### Materiais utilizados
1. Arduino UNO [^A] + cabo de programação
2. Sensor Ultrassônico [^U]
3. LED vermelho
3. Resistor para o LED (a definir)
4. Módulo Ethernet [^M]
5. Fios para conexão

> O _hardware_ adotado é o Arduino especificado acima, utilizando o PlatformIO como plataforma de _software_.

### :beginner: Desenvolvimento
#### :small_blue_diamond: Reunião 1 (28/02)
Foi discutido qual será o tema principal do projeto, dentre as várias ideias dadas em aula. Para evitar os extremos da alta e baixa complexidade, o foco foi direcionado para um projeto com Arduino Uno (um dos alunos possui) com os periféricos disponíveis pelo professor e pelo aluno. O projeto que o grupo mais tendeu a gostar foi de um sistema de segurança de entrada em ambiente, com um sensor ultrassônico monitorando a passagem, LEDs e buzzer para o alarme e uma câmera para capturar o objeto captado. A ideia principal do buzzer foi na verdade um dispositivo que pudesse transmitir uma voz falando algo, não apenas um alarme.

#### :small_blue_diamond: Reunião 2 (07/03)
Na aula nos foi apresentado uma plataforma de desenvolvimento colaborativo (PlatformIO [^P]) e decidimos alterar o _software_ de desenvolvimento do Arduino IDE para este, já que acaba sendo uma forma mais prática caso seja necessário alterar o microcontrolador no meio do projeto. 

Considerando os materiais propostos anteriormente para o desenvolvimento do projeto, foi decidido o que de fato seria utilizado. A ideia de emitir o som de uma voz foi deixada de lado porque seria necessário comprar dispositivos externos (Módulo MP3 [^3] e Mini Alto-falante [^F]). Dito isso, será utilizado apenas um buzzer comum, já disponível para o uso em sala. A ideia da câmera também foi abandonada por ser muito difícil a aplicação em Arduino, sendo necessário mudar de microcontrolador.

No entanto, foi considerado desenvolver uma parte de comunicação no projeto em que, ao acionar o sistema de segurança, fosse possível enviar uma mensagem de alerta para o cliente. Há dispositivos em sala de aula que permita fazer isso, com o Módulo Ethernet, sendo necessário apenas estudar a programação necessária para implementação.

#### :small_blue_diamond: Reunião 3 (14/03)
Durante a aula foi um sucesso colocar em prática os códigos que foram montados durante a semana, sem considerar a parte de comunicação do Módulo Ethernet. Anteriormente o projeto foi montado pensando em um sensor infravermelho ([Código 1](codigos/alarme_ver_1.ino)) mas depois entendemos o funcionamento de sensor ultrassônico [^2] ([aqui](codigos/sensor_ultra.ino)), e o código foi atualizado para uma segunda versão ([Código 2](codigos/alarme_ver_2.ino)). Durante o teste, ao medir uma certa distância definida em código, o LED e o buzzer eram ativados apenas durante o momento em que a distância fosse menor.

Houve uma discussão sobre a função do projeto e foi alterada de um "alarme de passagem", que apenas detectasse a passagem e ativasse um alarme, pra um "alarme de aproximação" que detecta continuamente se uma pessoa está se aproximandoa partir de uma distância especificada. A aplicação será em proteger um notebook, ativando o sistema caso alguém se aproxime dele.

Anteriormente foi discutido sobre o uso do Módulo Ethernet, mas sem um direcionamento de onde seria enviada a notificação de alerta. Na aula foi decidido criar um bot no Telegram para que o Arduino conseguisse se comunicar diretamente com ele e enviar continuamente mensagens de notificação sobre a proximidade de uma pessoa ou não. As referências utilizadas para o estudo desses 2 assuntos foram as documentações das bibliotecas Ethernet [^4] e Universal Telegram Bot [^5], além de projetos  prontos de aplicação como um exemplo do Laboratório Remoto da UFSCar de um Módulo Ethernet com Arduino [^3], com criação de um Server [^6] e de um ESP8266 com envio de notificação para o Telegram [^7]. Também foi encontrado um vídeo muito útil sobre o código do Módulo Ethernet [^1].

Por fim, começamos a desenvolver o código que integrasse tanto o sensoriamento como a comunicação com o Telegram ([Código 3](codigos/alarme_ver_3.ino)), com sua conclusão esperada para a próxima aula.

#### :small_blue_diamond: Reunião 4 (21/03) - Final
No decorrer da Aula tivermos que abandonar a ideia de integrar com o Telegram e o bot, por problemas técnicos.
Com a ajuda do professor foi tentado utilizar o modulo ethernet para conectar com a internet e com um server online tentar controlar o buzzer e o alerta de aproximação, mas por questão de tempo não foi possível explorar essa ideia durante a aula, preferindo então manter o mais básico e fazer um sensor de alerta que desliga ao digitar "OK"

#### :small blue_diamond: Vídeo do resultado
https://drive.google.com/file/d/1lMZVoae3Keq8AVI52L1lQFjfNHW5AP4c/view?usp=share_link

### :link: Referências
[^A]: [Datasheet Arduino](https://docs.arduino.cc/hardware/uno-rev3)
[^U]: [Datasheet Sensor Ultrassônico](https://d229kd5ey79jzj.cloudfront.net/620/HCSR04.pdf)
[^M]: [Datasheet Módulo Ethernet](https://www.mouser.com/catalog/specsheets/a000056_datasheet.pdf)
[^3]: [Informações Módulo MP3](https://www.usinainfo.com.br/mp3-arduino/modulo-mp3-arduino-dfplayer-mini-5187.html)
[^F]: [Informações Mini Alto-falante](https://www.usinainfo.com.br/mini-alto-falante/mini-alto-falante-5w-6-ohms-78mm-para-projetos-yd78-3421.html)
[^P]: [PlatformIO](https://docs.platformio.org/en/latest/)
[^1]: [Vídeo: "Adding Wired Ethernet to Arduino"](https://www.youtube.com/watch?v=bzEVvzppvvo&ab_channel=misperry)
[^2]: [Projeto básico de um Sensor Ultrassônico](https://www.eletruscomp.com.br/post/projeto-15-sensor-ultrasonico-basico/)
[^3]: [Exemplo de uso do Módulo Ethernet com Arduino (Lab. Remoto UFSCar)](https://vlab.dc.ufscar.br/examples/arduino_uno/web.txt)
[^4]: [Documentação da biblioteca Ethernet](https://reference.arduino.cc/reference/en/libraries/ethernet/)
[^5]: [Documentação da biblioteca Universal Telegram Bot](https://www.arduino.cc/reference/en/libraries/universaltelegrambot/)
[^6]: [Projeto de Arduino com Módulo Ethernet (Server)](https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-modulo-ethernet-enc28j60-web-server)
[^7]: [Projeto de ESP8266 com envio de notificação para o Telegram](https://randomnerdtutorials.com/telegram-esp8266-nodemcu-motion-detection-arduino/)
