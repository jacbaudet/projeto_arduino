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

### :link: Referências
[^A]: [Datasheet Arduino](https://docs.arduino.cc/hardware/uno-rev3)
[^U]: [Datasheet Sensor Ultrassônico](https://d229kd5ey79jzj.cloudfront.net/620/HCSR04.pdf)
[^M]: [Datasheet Módulo Ethernet](https://www.mouser.com/catalog/specsheets/a000056_datasheet.pdf)
[^3]: [Informações Módulo MP3](https://www.usinainfo.com.br/mp3-arduino/modulo-mp3-arduino-dfplayer-mini-5187.html)
[^F]: [Informações Mini Alto-falante](https://www.usinainfo.com.br/mini-alto-falante/mini-alto-falante-5w-6-ohms-78mm-para-projetos-yd78-3421.html)
[^P]: [PlatformIO](https://docs.platformio.org/en/latest/)
