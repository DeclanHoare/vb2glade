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

Also, the directory delimiter is hardcoded. As a result, the program will happily produce
a completely empty directory and write a file with a backslash in the name next to it. I
tried changing the hardcoded directory delimiter to /, but this gave me absolutely no
output file at all, so I changed it back for now.
