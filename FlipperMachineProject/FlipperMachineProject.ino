//delays
//unsigned integer can max be 64000
const unsigned int max_time = 30000;
//Note delay cant be 0 (don't know why)
const unsigned int delay_time = 1;
//time since trig
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
volatile boolean left_trig;
volatile boolean right_trig;




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

  // prints number of sensor activations if changed--------------->
  if (prev_count != count) {
    Serial.println(count);
    prev_count = count;
  }



  
  //right_trig----------------------------------------------------->
  
    if (digitalRead(sensorPin1) == HIGH) {
      digitalWrite(ledPin1, HIGH);
      delay(100);
      digitalWrite(ledPin1, LOW);
      
      delay(1000);
  }
  
  //left flipper-------------------------------------------------->
  //with delay 
  
   if (digitalRead(sensorPin2) == HIGH) {
     digitalWrite(ledPin2, HIGH);
     delay(100);
     digitalWrite(ledPin2, LOW);
    
     delay(1000);
  }

  
} //end of main loop
    
 

//function which is called by sensorPin1 interrupt----------------->
void right_trig_interrupt() {
  count++;
  right_trig = true;  
}

//function which is called by sensorPin2 interrupt----------------->
void left_trig_interrupt() {
  count++;
  left_trig = true;
}
