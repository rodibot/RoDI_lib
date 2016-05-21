RoDI_lib
========
An Arduino Library and set of examples for RoDI (Robot Didáctico Inalámbrico).

Dependencies
------------

RoDI_lib depends on a couple of projects in order to be built and used:

* The [NewPing] (http://playground.arduino.cc/Code/NewPing) library.

* RoDI_lib itself is used by the examples, so it has to be installed before
  building any of them.

* [rodi-code] (https://github.com/garyservin/rodi-code) is needed to flash the
  examples in the robot's MCU.

Build
-----

To build the examples the RoDI_lib library and its dependencies have to be
installed in the Arduino IDE.

This can be done using the "Sketch" -> "Include Library" -> "Add .ZIP Library"
menu option in the Arduino IDE.

1. Download the [NewPing library zip] (https://bitbucket.org/teckel12/arduino-new-ping/downloads) file.

2. Add the NewPing library in the Arduino IDE by following the process mentioned above.

3. Download the RoDI_lib project as a zip file. This can be down by clicking
   on the "Clone or download" button in the project's GitHub page and then
   choosing "Download ZIP".

4. Install the RoDI_lib library in the Arduino IDE using the same process as
   used to install the NewPing library.

5. Choose the correct board and processor in the Arduino IDE. This can be
   done using the "Tools" option and then "Board" or "Processor" options.

   The chosen values should be:

   * Board: "Arduino Pro or Pro Mini"
   * Processor: "ATmega328 (3.3V, 8 MHz)"

6. Open in the Arduino IDE any of the .ino examples programs and click on
   the "Verify" button to compile it.

Install
-------

The compiled examples can be installed using the program_rodi.py Python
script found in the rodi-code repository, with the following command:

./program_rodi.py [FILE]

For example:

./program_rodi.py /tmp/build0886194be6bfadff694833fcc62686df.tmp/leds.ino.hex
