int sensePin = A0;
int sensorInput;
double temp; 
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
	//Prevent constant measuring
    delay(1000);
}

void runMotor() {
	//Spin rotor
	analogWrite(motorPin, speed);
}

void stopMotor() {
	//Slow down rotor / keep it stopped
	analogWrite(motorPin, stop);
}
