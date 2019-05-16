# Pinball automation


This project is about turning an old classic pinball machince, into an automatic pinball beast. It's done by ball detecting sensors
above the flippers, and an Arduino (Nano) activating the flippers via relays.



## Usefull information

### 3D print info:

**Sensor holder**


- Body depth: 10 mm.
- Body height: 7 mm.
- Body lenght: is defined by number number of repeats.

- Divider (the wall between each sensor): 3 mm.

- Screw hole size: 3 mm.

- Cut out length (for sensor): 11 mm.
- Cut out height (for sensor): 5 mm.

### Notes

- The atmega chips only supports internal pull up resistors not pull down

- Diodes used: 1N914

- Arduino used: Arduino nano

## To do

- ~~Put pull down resistor on multi sensor board~~
- Find a solution so that you dont accidentally place sensor incorrectly
into multi sensor board
- Find a solution to the sensors activating each other


## Log:


### May 16th

- Printed 2 sensor holders

- Cut out a new piece of tree to hold the multi sensor board on the
pinball machine and drilled holds for the multi sensor board.

- Added Line sensor (Model number: TCRT5000) datasheet to repo
- [TCRT5000 Datasheet](https://www.vishay.com/docs/83760/tcrt5000.pdf) 

**PROBLEM:**
- We found the sensor activating each while testing it on pinball
we are working on a 3D printed object that blocks the light from one sensor
reaching another sensor on the multi sensor board.
- Tobias found the datasheet for the line sensors.
  - The sensors are rated for a distance between 0.2 mm - 15 mm.
  - Their peak distance is 2.5 mm.
  - Our sensors are 33 mm from the playfield of the pinball machine



### May 9th

- Finished multi sensor board
- Put pull down resistor on multi sensor board
- multi sensor board is now fully functional
- We had a problem with the multi sensor board but it was due to a loose connection
- Openscad files for sensor holder and breadboard holder were added to the repository

### May 2nd

- Almost done with multi sensor board
- No problems

### April 25th

- Single sensor works.


**PROBLEMS:**

- Tobias ruined one of the sensors by placing it incorrectly in the multi sensor board. This problem needs to be solved.
- Multi sensor board with diodes dosnt work (Symptom: swithes on and off relay when sensor is not active).

**SOLVED:**

- The multi sensor board now works. We concluded that a pull down resistor is needed, the problem did not occure with just one sensor because,
with only one sensor there were no diode in the way. with the diodes, when no power was coming from the sensor output, the pin was just floating
- We still need to find a solution so that you dont accidentally place the sensor into the multi sensor board incorrectly



