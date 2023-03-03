# Microcontroladores e IoT
> Trabalho final da disciplina de Microprocessadores e Microcontroladores. 

## Projeto: Sistema de segurança de ambiente (Alarme)
### :beginner: Proposta
#### Descrição Geral
Um sistema de segurança por sensor ultrassônico que monitora a passagem de pessoas quando ativado. Ao ser acionado, o sistema entra em estado de alarme com LEDs vermelhos acesos, um dispositivo sonoro que transmite uma determinada frase e uma câmera que fotografa o momento da passagem.

#### Materiais utilizados
1. Arduino UNO [^1] + cabo de programação
2. Sensor Ultrassônico [^2]
3. LED vermelho
3. Resistor para o LED (a definir)
4. Módulo MP3 Arduino DFPlayer Mini [^3] _(sugestão)_
5. Mini Alto-falante [^4] _(sugestão)_
6. Fios para conexão

> O _hardware_ adotado é o Arduino especificado acima, utilizando o Arduino IDE como _software_.

### :beginner: Desenvolvimento
#### :small_blue_diamond: Reunião 1 (28/02)
Foi discutido qual será o tema principal do projeto, dentre as várias ideias dadas em aula. Para evitar os extremos da alta e baixa complexidade, o foco foi direcionado para um projeto com Arduino Uno (um dos alunos possui) com os periféricos disponíveis pelo professor e pelo aluno. O projeto que o grupo mais tendeu a gostar foi de um sistema de segurança de entrada em ambiente, com um sensor ultrassônico monitorando a passagem, LEDs e buzzer para o alarme e uma câmera para capturar o objeto captado. A ideia principal do buzzer foi na verdade um dispositivo que pudesse transmitir uma voz falando algo, não apenas um alarme.

### :link: Referências
[^1]: [Datasheet Arduino](https://docs.arduino.cc/hardware/uno-rev3)
[^2]: [Datasheet Sensor Ultrassônico](https://d229kd5ey79jzj.cloudfront.net/620/HCSR04.pdf)
[^3]: [Informações Módulo MP3](https://www.usinainfo.com.br/mp3-arduino/modulo-mp3-arduino-dfplayer-mini-5187.html)
[^4]: [Informações Mini Alto-falante](https://www.usinainfo.com.br/mini-alto-falante/mini-alto-falante-5w-6-ohms-78mm-para-projetos-yd78-3421.html)
