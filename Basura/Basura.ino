#include <Servo.h>

// Definición de los pines del sensor de ultrasonido
const int trigPin = 8;
const int echoPin = 10;

// Definición del pin del servo motor
const int servoPin = 9;
const int Vcc = 5;
const int Gnd = 4;

// Definición del objeto Servo
Servo myServo;

// Variables para almacenar la distancia medida por el sensor
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Configura el pin trigPin como salida
  pinMode(echoPin, INPUT);  // Configura el pin echoPin como entrada
  myServo.attach(servoPin); // Asocia el objeto myServo al pin del servo
  myServo.write(0);        // Coloca el servo en posición inicial
  
  Serial.begin(115200);       // Inicia la comunicación serial a 115200 bps
  pinMode(Vcc, OUTPUT); // Configura el pin trigPin como salida
  pinMode(Gnd, OUTPUT); // Configura el pin trigPin como salida
  digitalWrite(Gnd, LOW);
  digitalWrite(Vcc, HIGH);
}

void loop() {
  // Genera un pulso de 10 microsegundos en el pin trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Lee la duración del pulso en el pin echoPin
  duration = pulseIn(echoPin, HIGH);
  
  // Calcula la distancia en centímetros
  distance= duration*0.034/2;
  
  // Imprime la distancia medida en el monitor serial
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // Verifica si la distancia es menor a 10 cm
  if (distance < 10) {
    // Mueve el servo a 180 grados
    myServo.write(180);
    delay(1000); 
 
  } else {
    // Mueve el servo a 0 grados (posición inicial)
    myServo.write(0);
  }
  
  delay(100); // Espera 100 milisegundos antes de la siguiente lectura
}
