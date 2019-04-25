This project is about turning an old classic pinball machince, into an automatic flipper beast. It's done by ball detecting sensors
above the flippers, and an Arduino (Nano) activating the flippers via relays.


3D print info:

Body depth: 10 mm.
Body height: 7 mm.
Body lenght: is defined by number number of repeats.

divider (the wall between each sensor): 3 mm.

screw hole size: 3 mm.

cut out length (for sensor): 11 mm.
cut out height (for sensor): 5 mm.

Log:

April 25th

diodes: 1N914
Single sensor works April 25
multi sensor board with diodes dosnt work (Symptom: swithes on and off relay when sensor is not active) April 25
Problem: Tobias ruined one of the sensor by placing it uncorrectly in the multi sensor board. This problem needs to be solved April 25
SOLVED the multi sensor board now works. we concluded that a pull down resistor is needed the problem did not occure with just one sensor becuase 
with only one sensor there were no diode in the way. with the diodes, when no power is coming from the sensor output the pin were just floating April 25
Note: the atmega chips only supports pull up resistors April 25 
//To do: Put pull down resistor on multi sensor board April 25
