//This circuit powers a 12V RGB LED Strip. 
//It has a power switch to turn the lights on and off.
//It also has 3 potentiometers to control the intensity of each color, giving a wide range of color outputs.

// setting up the pins:
// Potentiometer Inputs:
const int GreenAnalogIn = A0;
const int RedAnalogIn = A1;
const int BlueAnalogIn = A2;

// LED Outputs:
const int GreenLED = 6;
const int RedLED = 5;
const int BlueLED = 3;

// Power switch input:
const int PowerSwitch = 7;

// Set up values:
int GreenIn = 0;
int RedIn = 0;
int BlueIn = 0;

int GreenOut = 0;
int RedOut = 0;
int BlueOut = 0;

void setup() {
  // Start serial:
  Serial.begin(9600);
  
  // Configure pin modes:
  pinMode(PowerSwitch, INPUT_PULLUP);
  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
}

void loop() {  
  
  // Read analog inputs only when power switch is on (digital logic low):
  while (digitalRead(PowerSwitch) == LOW) {
    
    // Read analog inputs:
    GreenIn = analogRead(GreenAnalogIn);
    delay(5);
    RedIn = analogRead(RedAnalogIn);
    delay(5);
    BlueIn = analogRead(BlueAnalogIn);
    delay(5);

    // Map analog inputs to corresponding output values:
    GreenOut = map(GreenIn, 0 1023, 0, 255);
    RedOut = map(RedIn, 0, 1023, 0, 255);
    BlueOut = map(BlueIn, 0, 1023, 0, 255);

    delay(10);

    // Write Pulse Width Modulation values to corresponding LEDs:
    analogWrite(GreenLED, GreenOut);
    analogWrite(RedLED, RedOut);
    analogWrite(BlueLED, BlueOut);

    // Allow for processing to catch up:
    delay(25);
  }
  
  // Turn off LEDs when power switch is off:
  analogWrite(GreenLED, 0);
  analogWrite(RedLED, 0);
  analogWrite(BlueLED, 0);

  delay(100);

}
