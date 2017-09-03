# ShiftRe
Code for interfacing and configuring any number of daisy-chained 74HC595 shift registers so they can be effectively used as additional ports for microcontrollers.

The 595 is a serial-in parallel-out shift register, more information can be found here https://www.arduino.cc/en/Tutorial/ShiftOut

Multiple 595s can be chained together, and by shifting out the bits and keeping track of the states of each bit, these 595s can be used as additional output ports which can be set to HIGH or LOW. For better use as an output, each of the output bits will be the base for a transistor with more useable collector current. The current from the shift registers are quite low, but enough to be used as the base current. 

This code uses bitwise operators to keep track of which outputs are HIGH and LOW for an indefinite number of daisy-chained shift registers.

As it is written to run on an Arduino, there are the compulsory loop and setup functions. Loop runs the main program, setup is used to set the latch, data and clock pins. The ShiftOut function is taken from the link above, and the TurnPort function is the one used to turn outputs on and off and keep track of the changes.

For example, three daisy-chained 595s would have N=3 and 24 additional ports. To turn on port 1, use TurnPort(1), and to turn it back off, use TurnPort(-1). The ports are indexed from 1 instead of zero so that the sign can be used to indicate the action.
