#vb2glade

vb2glade is a program to convert Visual Basic 6 forms to Glade files, created by
Ishan Chattopadhyaya. This version has been modified by me so that it works on Linux,
and presumably every other platform with a GNU userland available.

##Building

I will set up an Autotools build system soon, but for now, enter the "src" directory
and run:

`g++ *.cpp -o vb2glade`

##Todo

This program is still quite buggy. My test input is the Forms directory from YoshiNES.
So far, the results have been inconsistent. Further details will be provided on the
issue tracker.
