/**
   Geek Factory - "Dale vuelo a tus proyectos"
   Tienda de electrónica, Arduino, Raspberry Pi, IoT
   www.geekfactory.mx
   GEEK FACTORY INVIERTE TIEMPO Y RECURSOS EN DESARROLLAR ESTOS EJEMPLOS Y TUTORIALES.
   SI ENCUENTRAS ÚTIL ESTE CÓDIGO, CONSIDERA REALIZAR UNA COMPRA CON NOSOTROS.
   EJEMPLO SENSOR ULTRASÓNICO HC-SR04 1
   Descripción:
   Realiza la medición de distancia con un sensor ultrasónico HC-SR04. El resultado
   se muestra en el monitor serial.
   Este ejemplo NO utiliza librerías especiales para el sensor, solamente se utiliza
   la función "pulseIn" incluida en el IDE de Arduino para medir la longitud del
   pulso de eco que devuelve el sensor ultrasónico.
*/
// declaración de variables para pines
// aquí indicamos a donde se conectan las señales del sensor
const int pinecho = 3;
const int pintrigger = 2;
// variables para calculos
unsigned long tiempo, distancia;
/**
   Función setup: se ejecuta una vez cuando encendemos el arduino
*/
void setup() {
  // preparar la comunicación serial
  Serial.begin(115200);
  // configurar los pines utilizados por el sensor
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  // mostrar mensaje inicial
  Serial.println(F("----------------------------------------------------"));
  Serial.println(F("EJEMPLO SENSOR ULTRASONICO CON ARDUINO SIN LIBRERIA "));
  Serial.println(F("            https://www.geekfactory.mx              "));
  Serial.println(F("----------------------------------------------------"));
}
/**
   Función loop: se ejecuta continuamente mientras el arduino permanece encendido
*/
void loop() {
  // asegurarnos que el pin trigger se encuentra en estado bajo
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  // comenzamos pulso alto, debe durar 10 uS
  // luego regresamos a estado bajo
  digitalWrite(pintrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);
  // medimos el tiempo en estado alto del pin "echo"
  // el tiempo en estado alto es proporcional a la distancia medida
  tiempo = pulseIn(pinecho, HIGH);
  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y
  // VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = tiempo / 58;
  // imprimir la distancia medida al monitor serial
  Serial.print(F("Distancia: "));
  Serial.print(distancia);
  Serial.println(F(" cm"));
  // esperar un segundo antes de realizar otra medición
  delay(1000);
}