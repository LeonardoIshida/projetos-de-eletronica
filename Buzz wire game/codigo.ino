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
