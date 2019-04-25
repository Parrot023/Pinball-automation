//A wonderfull program by Andreas J.
//the goal is to read the output from a sensor and activate a releay

//delays
const int flipperUpTime = 100;
const int flipperWaitTime = 500;

//sensor pins
const int rightsensor = 2;
const int leftsensor = 3;

//counting every time the sensors are activated
int count = 0;
int prev_count;

//flipper pins
const int rightflipper = 4;
const int leftflipper = 5;




void setup() { //------------------------------------------------------------------------------------------------------------>

  //declare pin modes
  pinMode(rightsensor, INPUT);
  pinMode(rightflipper, OUTPUT);

  pinMode(leftsensor, INPUT);
  pinMode(leftflipper, OUTPUT);

  digitalWrite(rightsensor, LOW);
  digitalWrite(leftsensor, LOW);

  //starts the serial communication
  Serial.begin(9600);

}

void loop() { //--------------------------------------------------------------------------------------------------------------->

  if (prev_count != count) {
    Serial.println(count);
    prev_count = count;
  }


  //right flipper ------------------------------------------------------------------------------->
    Serial.println(digitalRead(rightsensor));
    if (digitalRead(rightsensor) == HIGH) {
        
      Serial.println(digitalRead("ACTIVE"));
      //activate flipper
      digitalWrite(rightflipper, HIGH);

      //this delay is needed by the flipper, if this delay wasnt here the flipper would not flip
      delay(flipperUpTime);

      //deactivate flipper
      digitalWrite(rightflipper, LOW);

      //delay to prevent the flipper from activating itself,
      //this might have to be redone in the future for support for multiple sensors per flipper
      //maybe using interrupts again
      delay(flipperWaitTime);

      //counts number of sensor activations
      count ++;
  }

  //left flipper --------------------------------------------------------------------------------->


} //end of main loop ----------------------------------------------------------------------------------------------------------->
