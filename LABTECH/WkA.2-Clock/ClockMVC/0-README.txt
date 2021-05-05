VIRTUAL DIGITAL CLOCK

We're building a digital clock with an LED display.  Our company has
ordered a million LED clock faces delivered to the factory.

The display manufacturer has sent us a file called "LED-layout.txt",
which explains which bits go where to turn on the LEDs.  They've also sent
us a file "LEDisplay.h", which has prototypes and declarations needed
for our compiler, and "LEDisplay.o", which has all the object code.
(They did not send us the C source files, because they consider that to
be a trade secret.)

What we have to do is modify the View portion of our clock to use this
display instead of just using printf().  (We have to keep the old code
around for debugging purposes.)  The Controller handles flags about
which display to use, but it doesn't have offset ability, which needs
to be added.

This program uses a system called "make", which reads the file called
"Makefile".  In order to compile and test your code, all you have to do
is run the command "make".

Things To Notice:

1) "clock.h" includes "LEDisplay.h".

2) The Makefile includes LIBRARY and INCLUDE macros, for some of the
   special features needed to do full-screen display.

3) A stub "ledshow()" is in "view.c", but it's just sample code.

4) "clock.c" has variables which go with the option flags, and they are
   global, not local, because they can't be passed.


What You Should Do Before You Start:

1) Figure out how to handle offsets.

2) Figure out am/pm.  Midnight is "12:00:00 am"; do not set the hour
   to "00".  At noon, it should go from "11:59:59 am" to "12:00:00 pm".


3) Read "LED-layout.txt" and figure out on paper which bits make
   which numbers.  (Making sketches really does help.)


What Remains To Be Done To The Code:

4) Put the offset code in your program and make sure it's right by
   running it in text mode (that is, no -l flag) to ensure that if
   you put in 3600, it goes one hour ahead, and if you put in -3600,
   it goes one hour back.

   The "stm.py" program computes the seconds to midnight (or noon),
   so you can use it by doing something like this:

       ./clock -o $( ./stm.py -o -3 )

   and it should go to 23:59:57, and you can watch it count over to
   00:00:00.  Similarly, you can do:

       ./clock -o $( ./stm.py -no -3 )

   which should make it to 11:59:57, and you can watch it count over
   to 12:00:00.

   (You need this to test step 5).


5) Code your AM/PM logic and make sure it's right with the same
   tests mentioned above.

   ***  Be sure both of the above steps are done and work before
   ***  you put a lot of work into the LED display.  You don't want
   ***  to spend hours debugging the LEDs because it's showing the
   ***  the wrong AM/PM information only to find out the LEDs were
   ***  fine but the logic was broken.


6) The View needs to put the correct bits into the location pointed
   at by "where", with the appropriate offsets, so that digits show
   up displaying the time.  (You'll need the sketches you made in
   Step 3.)

   Right now, it puts in some bits, but they're all wrong.


7) You should do something with the colons, whether they blink or
   just stay on all the time or whatever.  ALSO, set the AM/PM/24H
   indicator correctly.

   ***  NOTE ABOUT COLONS: sometimes, the dots that make the colons
   ***  appear to "smear" across the display.  This is usually because
   ***  your shell's TERM variable is set to "xterm" instead of "putty".
   ***  The command to fix that is:  "export TERM=putty".

