Some arduino sketches for the Noisebridge badge

song\_writer\_attiny85 directory contains an example of code which when uploaded
through the Arduino ide plays row row row your boat. It's really great considering @robz made it from scratch.


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

If you want to try to make use of the speaker but not be confined to the simple api in song_writer_attiny85 you have a few other options.

You could follow along with the examples on [https://www.arduino.cc/en/Tutorial/PlayMelody](https://www.arduino.cc/en/Tutorial/PlayMelody) and try and hack those up if you find them more clear.

Or there's this simple tones example [http://www.technoblogy.com/show?KVO](http://www.technoblogy.com/show?KVO)

Or try and get some attiny cores installed with include the tone() function from the arduino library so you can just copy from all the examples which use that. [http://lizastark.com/thesis/2011/12/attiny85-initial-tests-tone-function-support/](http://lizastark.com/thesis/2011/12/attiny85-initial-tests-tone-function-support/)
