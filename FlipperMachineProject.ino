const int sensorPin = 3;
int count = 0;
int prev_count;
const int ledPin = 4;

void setup() {
  // Sets the sesnorPin, as an Input
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // Attaches sensorPin as an interrupt, and calls the function sensorHigh, when sensorPin becomes HIGH
  attachInterrupt(digitalPinToInterrupt(sensorPin), sensorHigh, RISING);
  
  // Starts the serial communication
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(ledPin, LOW);
  // Prints message, if sensorState is high
  if (prev_count != count) {
    Serial.println(count);
    prev_count = count;
  }

}

// Function which is called by sensorPin interrupt
void sensorHigh() {
  pinMode(ledPin, HIGH);
  count++;
}
