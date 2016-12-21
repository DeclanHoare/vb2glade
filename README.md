#vb2glade

vb2glade is a program to convert Visual Basic 6 forms to Glade files, created by
Ishan Chattopadhyaya. This version has been modified by me so that it works on Linux,
and presumably every other platform with a GNU userland available.

##Building

Generate a configure script by running:

`autoreconf -i`

Then run

`./configure; make`

to compile the program. You can also run

`make install`

as root to install it system-wide.

##Todo

This program is still quite buggy. My test input is the Forms directory from YoshiNES.
So far, the results have been inconsistent. Further details will be provided on the
issue tracker.
