int x = 0;
int LastTime = 0;
bool BPMTiming = false;
bool BeatComplete = false;
int BPM = 0;    
#define UpperThreshold 518
#define LowerThreshold 490    
int LED13 = 44; // The on-board Arduino LED
int Signal; // holds the incoming raw data. Signal value can range from 0-1024

void setup() {
  pinMode(LED13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(0);
  if (value > UpperThreshold) {
    if (BeatComplete) {
      BPM = millis() - LastTime;
      BPM = int(60 / (float(BPM) / 1000));
      BPMTiming = false;
      BeatComplete = false;
    }
    if (BPMTiming == false) {
      LastTime = millis();
      BPMTiming = true;
    }
  }
  if ((value < LowerThreshold) & (BPMTiming))
    BeatComplete = true;
    // display bpm
  Serial.print(BPM);
  Serial.println(" BPM");
  x++;
  Signal = analogRead(0); // Read the PulseSensor's value.
  // Assign this value to the "Signal" variable.
  if (Signal > UpperThreshold) {
    // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
    digitalWrite(LED13, HIGH);
  } else {
    digitalWrite(LED13, LOW); //  Else, the signal must be below "550", so "turn-off" this LED.
  }
}
//  Variables
int PulseSensorPurplePin = 0; // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED13 = 13; // The on-board Arduino LED
int Signal; // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 550; // Determine which Signal to "count as a beat", and which to ingore.

void setup() {
  pinMode(LED13, OUTPUT); // pin that will blink to your heartbeat
  Serial.begin(9600); // Sets up Serial Communication at certain speed.
}

void loop() {
  Signal = analogRead(PulseSensorPurplePin); // Read the PulseSensor's value.
  // Assign this value to the "Signal" variable.
  Serial.println(Signal); // Send the Signal value to Serial Plotter.
  if(Signal > Threshold) {
    // If the signal is above "550", then "turn-on" Arduino's on-Board LED.
    digitalWrite(LED13, HIGH);
  } else {
    digitalWrite(LED13, LOW); //  Else, the signal must be below "550", so "turn-off" this LED.
  }
  delay(10);
}
