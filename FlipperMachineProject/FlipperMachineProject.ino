//info 
//diodes: 1N914
//




//delays
const int flipperUpTime = 100;
const int flipperWaitTime = 1000;

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

  //starts the serial communication
  Serial.begin(9600);

}

void loop() { //--------------------------------------------------------------------------------------------------------------->

  if (prev_count != count) {
    Serial.println(count);
    prev_count = count;
  }




  //right flipper ------------------------------------------------------------------------------->

    if (digitalRead(rightsensor) == HIGH) {

      //activate flipper
      digitalWrite(rightflipper, HIGH);
      Serial.println("sjifhiojhfjih");

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

   if (digitalRead(leftsensor) == HIGH) {

     //activates flipper
     digitalWrite(leftflipper, HIGH);
     Serial.println("ksjdhgksjdhgkjh");

     //this delay is needed by the flipper, if this delay wasnt here the flipper would not flip
     delay(flipperUpTime);

     //deactivate flipper
     digitalWrite(leftflipper, LOW);

     //delay to prevent the flipper from activating itself,
     //this might have to be redone in the future for support for multiple sensors per flipper
     //maybe using interrupts again
     delay(flipperWaitTime);

     //counts number of sensor activations
     count++;
  }


} //end of main loop ----------------------------------------------------------------------------------------------------------->
