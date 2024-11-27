/*  
 *  Based on:
 *  https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/ 
 *  https://circuitdigest.com/microcontroller-projects/arduino-mq137-ammonia-sensor
 *  
 */

#define trigPin 2
#define echoPin 3
#define RL 10  //The value of resistor RL is 47K
#define m -0.263 //Enter calculated Slope 
#define b 0.42 //Enter calculated intercept
#define Ro 9.16 //Enter found Ro value
#define MQ_sensor A0 //Sensor is connected to A0

const int buzzer = 7;
unsigned long startTime = 0; // Tracks when distance > 30 condition starts
const unsigned long requiredDuration = 30000; // 30 seconds in milliseconds


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

  // Handle distance > 24.3 cm for more than 30 seconds
  if (distance > 24.3) {
    if (startTime == 0) {
      // Start the timer
      startTime = millis(); 
    } else if (millis() - startTime >= requiredDuration) {
      // If distance > 24.3 for over 30 seconds, handle based on ppm
      if (ppm > 15) {
        tone(buzzer, 5000); // High frequency for distance > 24.3 and ppm > 15
        delay(1000);
        noTone(buzzer);
      } else {
        tone(buzzer, 1000); // Low frequency for distance > 24.3 alone
        delay(1000);
        noTone(buzzer);
      }
    }
  } else {
    startTime = 0; // Reset the timer if distance <= 24.3
    if (ppm > 15) {
      tone(buzzer, 2000); // Medium frequency for ppm > 15 alone
      delay(1000);
      noTone(buzzer);
    }
  }

  //  if (distance > 24.3 && ppm > 15) {
  //   tone(buzzer, 5000);
  //   delay(1000);
  //   noTone(buzzer);
  // } else if (distance > 24.3) {
  //   tone(buzzer, 1000);
  //   delay(1000);
  //   noTone(buzzer);
  // } else if (ppm > 15 && distance < 24.3) {
  //   tone(buzzer, 2000);
  //   delay(1000);
  //   noTone(buzzer);
  // }

  Serial.print("ppm =");
  Serial.println(ppm);
  Serial.print("Voltage =");
  Serial.println(VRL);


  

  delay(2000);
}
