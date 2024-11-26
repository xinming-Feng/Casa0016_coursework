/*
 * Program to measure the value of R0 for a know RL at fresh air condition
 * Program by: B.Aswinth Raj
 * Website: www.circuitdigest.com                                       
 * Dated: 28-12-2017
 */
//This program works best at a fresh air room with temperaure Temp: 20℃, Humidity: 65%, O2 concentration 21% and when the value of Rl is 47K

#define RL 10  //The value of resistor RL is 47K

float VRL;
float Rs;
float Ro;

void setup() //Runs only once
{
  Serial.begin(9600); //Initialise serial COM for displaying the value
}

void loop() {
  
 
  VRL = 5.0*analogRead(A0)/1023.0; //Convert analog value to voltage


  //RS = ((Vc/VRL)-1)*RL is the formulae we obtained from datasheet
  Rs = ((5.0/VRL)-1) * RL;
  Serial.print("Rs = ");
  Serial.println(Rs); 
  
  //RS/RO is 3.6 as we obtained from graph of datasheet
  Ro = Rs/3.6;
  
  Serial.print("Ro at fresh air = ");
  Serial.println(Ro); //Display calculated Ro
  delay(1000); //delay of 1sec
}
