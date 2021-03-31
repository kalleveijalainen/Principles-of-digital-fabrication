int sensePin = A0;  //This is the Arduino Pin that will read the sensor output
int sensorInput;    //The variable we will use to store the sensor input
double temp;        //The variable we will use to store temperature in degrees. 
int motorPin = A1;
int speed = 200;
int stop = 0;

void setup() {
  //default
  Serial.begin(9600);
 }

void loop() {
    // Measure temp and control motor in 1s cycles
    //--------------------------------------------
    // credit to @Chris
    // https://bc-robotics.com/tutorials/using-a-tmp36-temperature-sensor-with-arduino/
    sensorInput = analogRead(sensePin);
    temp = (double)sensorInput / 1024;
    temp = temp * 5;
    temp = temp - 0.5;
    temp = temp * 100;
    //--------------------------------------------
    if (temp > 21) {
  	  runMotor();
    }
    else {
      stopMotor();
    }

    delay(1000);
}

void runMotor() {
	analogWrite(motorPin, speed);
}

void stopMotor() {
	analogWrite(motorPin, stop);
}
