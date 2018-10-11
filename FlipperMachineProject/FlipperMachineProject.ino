const int sensorPin = 3;
int count = 0;
int prev_count;
const int ledPin = 4;
int led_on_time = 1000;
int led_delay = 1000;
boolean right_trig;

void setup() {
  // Sets the sensorPin, as an Input
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  // Attaches sensorPin as an interrupt, and calls the function sensorHigh, when sensorPin becomes HIGH
  attachInterrupt(digitalPinToInterrupt(sensorPin), sensorHigh, RISING);
  
  // Starts the serial communication
  Serial.begin(9600);

}

void loop() {

  // Prints message, if sensorState is high
  if (prev_count != count) {
    Serial.println(count);
    prev_count = count;
  }

  //right flip
  if (right_trig) {
    delay(led_delay);
    digitalWrite(ledPin, HIGH);
    delay(led_on_time); 
    digitalWrite(ledPin, LOW);
    right_trig = false;
  }
}

// Function which is called by sensorPin interrupt
void sensorHigh() {
  count++;
  right_trig = true;
}
