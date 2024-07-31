
#include <SoftwareSerial.h>
char comando;
int objetivo=0;
int in1 =4;
int in2 =5;
int in3 =6;
int in4 =7;
  SoftwareSerial BT(10,11); //RX,TX

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}
void adelante(){
  digitalWrite(in1, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(in2, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(in3, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(in4, HIGH);   // turn the LED off by making the voltage LOW
}

void retroceder(){
  digitalWrite(in1, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(in2, HIGH);   // turn the LED off by making the voltage LOW
  digitalWrite(in3, HIGH);   // turn the LED off by making the voltage LOW
  digitalWrite(in4, LOW);   // turn the LED off by making the voltage LOW
}

void paro(){
  digitalWrite(in1, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(in2, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(in3, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(in4, LOW);   // turn the LED off by making the voltage LOW
}

void derecha(){
  digitalWrite(in1, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(in2, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(in3, HIGH);   // turn the LED off by making the voltage LOW
  digitalWrite(in4, LOW);   // turn the LED off by making the voltage LOW
}

void izquierda(){
  digitalWrite(in1, LOW);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(in2, HIGH);   // turn the LED off by making the voltage LOW
  digitalWrite(in3, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(in4, HIGH);   // turn the LED off by making the voltage LOW
} 

// the loop function runs over and over again forever
void loop() {
if (BT.available()) {
    
   comando=BT.read();   //INTERPRETA LOS DATOS QUE INGRESAN
 
    //AVANZAR
    if (comando == 'A') {
    adelante(); 
    }
    if (comando == 'P') {
    paro(); 
    }
     if (comando == 'D') {
    derecha(); 
    }
    if (comando == 'I') {
    izquierda(); 
    }
    if (comando == 'R') {
    retroceder();
    }
}
}


