# Pinball automation


This project is about turning an old classic pinball machince, into an automatic pinball beast. It's done by ball detecting sensors
above the flippers, and an Arduino (Nano) activating the flippers via relays.


## 3D print info:

Body depth: 10 mm.
Body height: 7 mm.
Body lenght: is defined by number number of repeats.

Divider (the wall between each sensor): 3 mm.

Screw hole size: 3 mm.

Cut out length (for sensor): 11 mm.
Cut out height (for sensor): 5 mm.

## Log:

### April 25th:

Diodes: 1N914\
Single sensor works.\
Multi sensor board with diodes dosnt work (Symptom: swithes on and off relay when sensor is not active).\
**PROBLEM:**\
Tobias ruined one of the sensor by placing it uncorrectly in the multi sensor board. This problem needs to be solved.\
**SOLVED:**\ 
The multi sensor board now works. We concluded that a pull down resistor is needed, the problem did not occure with just one sensor because,
with only one sensor there were no diode in the way. with the diodes, when no power was coming from the sensor output, the pin was just floating\
**Note:**\
The atmega chips only supports internal pull up resistors not pull down\
**To do:**\ 
Put pull down resistor on multi sensor board April 25\

### May 2nd:
Almost done with multi sensor board\
No problems\
To do: Put pull down resistor on multi sensor board\
