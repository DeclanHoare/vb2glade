#vb2glade

vb2glade is a program to convert Visual Basic 6 forms to Glade files, created by
Ishan Chattopadhyaya. This version has been modified by me so that it works on Linux,
and presumably every other platform with a GNU userland available.

##Building

I will set up an Autotools build system soon, but for now, enter the "src" directory
and run:

`g++ *.cpp -o vb2glade`

##Todo

I was initially quite happy to see that the Linux binary did not crash like the Windows
version did when I ran it on the test file... until I looked in the output file and
realised that it still created an incomplete file. So, this program is still buggy and
needs to be fixed so that it will create a complete XML file.
