vb2glade	
--------

Website: (http://wingtk.sourceforge.net/vb2glade/vb2glade.html)
Author: Ishan Chattopadhyaya <ishanchattopadhyaya@hclinfinet.com>

Prelease Version (Alpha 1)
^^^^^^^^^^^^^^^^^^^^^^^^^^

The Project should soon be released. Before that, here is a very early binary version for testing. It *contains many bugs*, which I would hopefully be able to clear up before release. Here is the feature list:

1) Detection, parsing and output of the following VB Controls:
	a) Label
	b) Command Button
	c) Text Box (-> GtkEntry)
	d) Check Box
	e) Option Button (Radio button)
	f) Combo Box
	g) Picture Box   (along with conversion of the picture to XPM format. See 2 below.)
	h) Frame (and embedding other controls within it)
	i) Vertical Scroll Bar
	j) Horizontal Scroll Bar
	
2) Conversion of embedded images in forms that are used with pictureboxes to xpm. For this I have used 'djpeg' from libjpeg, 'ppmtoxpm' and 'bmptopnm' from netpbm package. The image file formats supported are:
	a) Windows Bitmap (.BMP)
	b) Joint Picture Expert Group (JPEG)  (.jpg, .jpeg, .jfif)
