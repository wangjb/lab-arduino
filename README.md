# lab-arduino

In the lab, we use SpinCore's  as conductor to lead experiment.
Op code "WAIT" is one of the function of SpinCore's PulseBlaster(PB), which can is a
idle status, waiting for trigger to continue.

"ForSpinCoreHaltFunction.ino" is for realizing following function:

Here we use arduino as a external box to receive trigger from PB, as it execute
"WAIT" op code. With its interrupt fucntion, the arduino then enter into a mode,
waiting for a 60 Hz trigger signal from the other line. After triggered,
the arduino immediately send a low-state pulse to the hardware trigger port of PB.
