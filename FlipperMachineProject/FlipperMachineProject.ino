//delays
//unsigned integer can max be 64000
const unsigned int max_time = 60000;
const unsigned int delay_time = 30000;

//sensor pins
const int sensorPin1 = 2;
const int sensorPin2 = 3;

//counting every time the sensors are activated
int count = 0;
int prev_count;

//led pins
const int ledPin1 = 5;
const int ledPin2 = 4;

//right and left trigger time left counting from max_time
volatile unsigned int left_flipper_time_left;
volatile unsigned int right_flipper_time_left;




void setup() {
  
  //declare pin modes
  pinMode(sensorPin1, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(ledPin2, OUTPUT);
  
  //attaches sensorPin as an interrupt, and calls the function sensorHigh, when sensorPin becomes HIGH
  attachInterrupt(digitalPinToInterrupt(sensorPin1), right_trig_interrupt, RISING);
  attachInterrupt(digitalPinToInterrupt(sensorPin2), left_trig_interrupt, RISING);
  
  //starts the serial communication
  Serial.begin(9600);

}

void loop() {

  // prints number of sensor activations if changed
  if (prev_count != count) {
    Serial.println(count);
    prev_count = count;
  }

  //right flipper
  //with delay
  //if -flipper_time_left = higher than 0 countdown from max_time
  //if -flipper_time_left = equal to max_time - delay_time: turn on
  //if -flipper_time_left = equall to 0 turn off

  if (right_flipper_time_left == max_time - delay_time) {
    digitalWrite(ledPin1, HIGH);
  }
  
  if (right_flipper_time_left == 0) {
    digitalWrite(ledPin1, LOW);
  }

  if (right_flipper_time_left > 0){
    right_flipper_time_left--;
  }


  //left flipper
  //with delay 
  
   if (left_flipper_time_left == max_time - delay_time) {
    digitalWrite(ledPin2, HIGH);
  }
  
  if (left_flipper_time_left == 0) {
    digitalWrite(ledPin2, LOW);
  }

  if (left_flipper_time_left > 0){
    left_flipper_time_left--;
  }


// without delay  
//  if (right_flipper_time_left > 0){
//    digitalWrite(ledPin1, HIGH);
//    right_flipper_time_left--;
//  } else {
//    digitalWrite(ledPin1, LOW);
//  }

//  //left flipper
//  if (left_flipper_time_left > 0){
//    digitalWrite(ledPin2, HIGH);
//    left_flipper_time_left--;
//  } else {
//    digitalWrite(ledPin2, LOW);
//  }
//
} //end of main loop
    
 

//function which is called by sensorPin1 interrupt
void right_trig_interrupt() {
  count++;
  right_flipper_time_left = max_time;
  
}
//function which is called by sensorPin2 interrupt
void left_trig_interrupt() {
  count++;
  left_flipper_time_left = max_time;
}
