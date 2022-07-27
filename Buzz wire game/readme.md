# Buzz Wire Game
<p align="center">
<img src="https://github.com/zLeonardoIshida/projetos-de-eletronica/blob/main/Buzz%20wire%20game/readmeImagens/buzzwire.png?raw=true" width="100%"/>
</p>


## Descrição
Utilizando arduino, trata-se de um jogo tipo “buzz-wire”, onde o objetivo é passar pelo cabo do circuito sem encostar o aro.

> Projeto orientado pelo professor [Eduardo do Valle Simões](https://gitlab.com/simoesusp), da disciplina de Eletrônica para Computação (SSC0180)

## Vídeo Explicativo
<h3 align="right">
<a href="https://drive.google.com/file/d/1Mgwv2865F-z5Zhn0NR2PEK3a6nh91COc/view" target="_blank">Vídeo em alta qualidade</a>
</h3>

https://user-images.githubusercontent.com/61145881/181147885-f7c14fca-9485-4f05-ac1f-be45bcfc5217.mp4

## Componentes e Código

<p>
<h3>Peças utilizadas</h3>

<table align="right">
	<tbody>
		<tr>
			<td><strong>VALORES (R$)</strong></td>
		</tr>
		<tr>
			<td>(2 unidades)</td>
		</tr>
		<tr>
			<td>(2 unidades)</td>
		</tr>
		<tr>
			<td>(3 unidades)</td>
		</tr>
		<tr>
			<td>(1 unidade)</td>
		</tr>
		<tr>
			<td>(2 metros)</td>
		</tr>
		<tr>
			<td>(1 unidade)</td>
		</tr>
		<tr>
			<td>(1 unidade)</td>
		</tr>
		<tr>
			<td>(1 unidade)</td>
		</tr>
    <tr>
			<td>(1 unidade)</td>
		</tr>
		<tr>
			<td>TOTAL:   -
</td>
		</tr>
	</tbody>
</table>

</br>

- Leds
- Resistores 2.2k
- Resistores 1k
- Piezo
- Arame
- Botão
- Arduino Uno
- Protoboard
- Jumper
</br>
</br>
</br>
</br>
</br>
</p>

## Código

````ino

int led = 13; 
int ledtimer = 8;
int piezo = 10;
int inputPin = 2; 
int inputStatus = 0; 
int botaoInicio = 7;
int statusInicio = 0;
 
void setup() {
  pinMode(led, OUTPUT); 
  pinMode(ledtimer, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP); 
  pinMode(botaoInicio, INPUT_PULLUP);
}

void loop() {
  
  digitalWrite(led, LOW);
  digitalWrite(piezo, LOW);
  
  statusInicio = digitalRead(botaoInicio);
  
  while(statusInicio == 1){
    if(statusInicio == 0){
      break;
    }
     statusInicio = digitalRead(botaoInicio);
  }
  
  inputStatus = digitalRead(inputPin); 
  
  int contador = 0;
  
  while((inputStatus == 1) && (contador<60000)){
    digitalWrite(ledtimer, HIGH);
    inputStatus = digitalRead(inputPin);
    if(inputStatus == 0){
      break;
    }
    delay(1);
    inputStatus = digitalRead(inputPin);
    if(inputStatus == 0){
      break;
    }
    contador++;
    inputStatus = digitalRead(inputPin);
  }

  digitalWrite(ledtimer, LOW);
  digitalWrite(led, HIGH);
  tone(piezo, 262, 3000);
  delay(3000);
}
````
## Circuito no [TinkerCad](https://www.tinkercad.com/)

> Representação simulativa/ilustrativa do nosso trabalho
<p align="center">
	<img src="https://github.com/zLeonardoIshida/projetos-de-eletronica/blob/main/Buzz%20wire%20game/readmeImagens/tinkercard.png?raw=true" width="600">
</p>
