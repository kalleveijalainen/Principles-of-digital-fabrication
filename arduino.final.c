// credits to: 
// https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor


// define constants
int motorPin = A1;
int sensorPin = 0;
int thresh = 22;

void setup() {
  // initialize
   Serial.begin(9600);
   pinMode(motorPin, OUTPUT);
   delay(500);
   Serial.println("program started");
}

void loop() {
    // read value from TMP36 sensor
    int output = analogRead(sensorPin);
    // convert output voltage to celsius
    float V = output * 5.0;
    V /= 1024.0; 
    // print out the voltage
    Serial.print(V); Serial.println(" volts\n");
    // now print out the temperature
    float temp = (V - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
    Serial.print(temp); Serial.println(" degrees C\n");

    // spin motor if it is too hot
    if (temp >= thresh) {
        analogWrite(motorPin, 255);
        Serial.println("rotate motor");
    }
    
    else {
        analogWrite(motorPin, 0);
        Serial.println("stop motor");
    }
  // wait 10 seconds
  delay(10000);
 }