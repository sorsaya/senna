/**
   Geek Factory - "Dale vuelo a tus proyectos"
   Tienda de electrónica, Arduino, Raspberry Pi, IoT
   www.geekfactory.mx
 
   GEEK FACTORY INVIERTE TIEMPO Y RECURSOS EN DESARROLLAR ESTOS EJEMPLOS Y TUTORIALES.
   SI ENCUENTRAS ÚTIL ESTE CÓDIGO, CONSIDERA REALIZAR UNA COMPRA CON NOSOTROS.
 
   EJEMPLO PUENTE H L298N BÁSICO
 
   Descripción:
 
   Este programa hace girar los motores en un sentido y luego en el otro. El programa
   está pensado para NO usar los pines de control de PWM por lo que los jumpers
   correspondientes deben estar en su posición en el módulo L298N.
 
   Las conexiones a realizar son las siguientes:
 
   * IN1 - pin 9
   * IN2 - pin 8
   * IN3 - pin 7
   * IN4 - pin 6
*/
 
// pines de señales PWM
const int ena = 10;
const int enb = 5;
 
// pines de control de dirección
const int in1 = 9;
const int in2 = 8;
const int in3 = 7;
const int in4 = 6;
 
/**
   Función setup: se ejecuta una vez cuando encendemos el arduino
*/
void setup() {
  // iniciar puerto y mostrar mensaje
  Serial.begin(9600);
  Serial.println(F("----------------------------------------------------"));
  Serial.println(F("              L298N - CONTROL DE MOTORES            "));
  Serial.println(F("              https://www.geekfactory.mx            "));
  Serial.println(F("----------------------------------------------------"));
 
  // configurar los pines de control de motores como salidas
 
  // pines de control del motor A
  // pin de control de velocidad motor A
  pinMode(ena, OUTPUT);
  // control de dirección motor A
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 
  // pines de control del motor B
  // pin de control de velocidad motor B
  pinMode(enb, OUTPUT);
  // control de dirección motor B
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
 
  // configurar el estado de las salidas del puente H para detener los
  // motores y en caso de que tengamos conectados los pines ENA Y ENB,
  // habilitar los puentes H colocando las señales correspondientes en
  // nivel alto. En este ejemplo las señales ENA y ENB no se usarán
  // para el control de velocidad.
  digitalWrite(ena, HIGH);
  digitalWrite(enb, HIGH);
 
  // motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 
  delay(1000);
}
 
/**
   Función loop: se ejecuta continuamente mientras el arduino permanece encendido
*/
void loop() {
  // motor A adelante
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // motor B atrás
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
 
  // los motores permanecen encendidos en la dirección actual por 5 segundos
  delay(5000);
  // luego invertimos el sentido de giro
 
  // motor A atras
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // motor B adelante
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
 
  // esperamos antes de volver a cambiar el sentido de giro
  delay(5000);
} 
