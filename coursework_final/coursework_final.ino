/*  
 *  Based on:
 *  https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/ 
 *  
 */

#define trigPin 2
#define echoPin 3
const int buzzer = 7;
#define RL 10  //The value of resistor RL is 47K
#define m -0.263 //Enter calculated Slope 
#define b 0.42 //Enter calculated intercept
#define Ro 9.16 //Enter found Ro value
#define MQ_sensor A0 //Sensor is connected to A0

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH); 
  float distance = 34400*duration/2000000;
  
  Serial.print("Distance in cm: ");
  Serial.println(distance);
 
  float VRL; //Voltage drop across the MQ sensor
  float Rs; //Sensor resistance at gas concentration 
  float ratio; //Define variable for ratio

   

  VRL = analogRead(MQ_sensor)*(5.0/1023.0); //Measure the voltage drop and convert to 0-5V
  Rs = ((5.0*RL)/VRL)-RL; //Use formula to get Rs value
  ratio = Rs/Ro;  // find ratio Rs/Ro

 
  float ppm = pow(10, ((log10(ratio)-b)/m)); //use formula to calculate ppm

   if (distance > 24.3 && ppm > 15) {
    tone(buzzer, 5000);
    delay(1000);
    noTone(buzzer);
  } else if (distance > 24.3) {
    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
  } else if (ppm > 15 && distance < 24.3) {
    tone(buzzer, 2000);
    delay(1000);
    noTone(buzzer);
  }

  Serial.print("ppm =");
  Serial.println(ppm);
  Serial.print("Voltage =");
  Serial.println(VRL);


  

  delay(2000);
}
