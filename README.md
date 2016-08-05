Some arduino sketches for the Noisebridge badge

song\_writer\_attiny85 directory contains an example of code which when uploaded
through the Arduino ide plays row row row your boat. I'm pretty sure it's just
copied from somewhere. Or maybe https://github.com/robz coded it but I don't
think so.


To hook up the ISP pins so you can program it too you have some options:

To use Arduino as ISP make the following connections from Aduino to the badge:
To follow we'll use comm for the ISP header numbering starting at comm1 which is
marked on the board.

How the ISP pins are ordered physically on the Noisbridge badge:
  comm1 comm2
  comm3 comm4
  comm5 comm6


And their connections to the Arduino:
    - 5V to comm1
    - 12 to comm2
    - 10 to comm3
    - 13 to comm4
    - gnd to comm5
    - 10 to comm6


Or you can use a dedicated avr programmer. And there's lots of options for that.
    - basic attiny programming how to
      https://learn.sparkfun.com/tutorials/tiny-avr-programmer-hookup-guide


When trying to program the board the pin reference is:
     pin #  component
     0      RGB blue
     1      RGB green
     2      RGB red
     3      red LED
     4      speaker

So while using the Arduino IDE open the simple blink example and change the 13
to 0. And the RGB led wiill blink blue.
