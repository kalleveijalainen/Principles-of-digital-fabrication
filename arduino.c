#include <dht.h>
#define dht_apin A0

dht DHT;

int sensorInput;
float temp; 
int motorPin = 3;
const int threshold = 21;

void setup() {
	Serial.begin(9600);//default
	delay(500);//Delay to let system boot
	Serial.println("DHT11 Humidity & temperature Sensor\n\n");
	delay(1000);//Wait before accessing Sensor
 }

void loop() {
  	// Measure and run motor if it is too hot!
    DHT.read11(dht_apin);

    temp = DHT.temperature;

    Serial.print(temp);
    Serial.print("\n");

    if (temp >= threshold) {
		analogWrite(motorPin, 255);
		Serial.print("rotate");
		Serial.print("\n");
    }
	
    else {
		analogWrite(motorPin, 0);
		Serial.print("stop");
		Serial.print("\n");
    }
	
    //Prevent constant measuring
    delay(3000);
}
