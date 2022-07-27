int ledfim = 13; //led do fim do circuito (vermelho)
int ledtimer = 8; //led de tempo, indica que o jogo esta ativo (verde)
int piezo = 10;
int inputPin = 2; //circuito do jogo, funciona como um botao
int inputStatus = 0; 
int botaoInicio = 7; //botao de inicio do jogo
int statusInicio = 0;
 
void setup() {
  /*configurando como entrada ou saida*/
  pinMode(ledfim, OUTPUT); 
  pinMode(ledtimer, OUTPUT);
  pinMode(piezo, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP); 
  pinMode(botaoInicio, INPUT_PULLUP);
}

void loop() {

  /*inicializando o led de fim e o piezo buzzer como low (desligados)*/
  digitalWrite(ledfim, LOW);
  digitalWrite(piezo, LOW);
  
  /*loop ate que o botao de inicio seja ativado*/
  statusInicio = digitalRead(botaoInicio);
  while(statusInicio == 1){
    if(statusInicio == 0){
      break;
    }
     statusInicio = digitalRead(botaoInicio);
  }

  digitalWrite(ledtimer, HIGH); //led de timer ligado

  int contador = 0; 

  inputStatus = digitalRead(inputPin); //status do jogo

  /*loop ate que o circuito do jogo seja fechado (derrota) ou ate que o tempo termine (1 minuto)*/
  while((inputStatus == 1) && (contador<60000)){
    delay(1);
    inputStatus = digitalRead(inputPin);
    if(inputStatus == 0){
      break;
    }
    contador++;
    inputStatus = digitalRead(inputPin);
  }

  /*fim do jogo, led verde apaga, led vermelho acende, piezo apita*/
  digitalWrite(ledtimer, LOW);
  digitalWrite(ledfim, HIGH);
  tone(piezo, 262, 3000);
  delay(3000);
}
