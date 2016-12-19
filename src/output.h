/* vb2glade
 * Copyright (C) 2002 Ishan Chattopadhyaya
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "icstring.h"
#include "getvalues.h"
#include "image.h"
#include "list.h"


void OutputRadio(ofstream& outfile, char *name, char *wd, char *ht, char* caption,
				 char *xcoord, char *ycoord);
void OutputButton(ofstream& outfile,char *name, char *wd, char *ht, char* caption,
				 char *xcoord, char *ycoord);
void OutputEntry(ofstream& outfile,char *name, char *wd, char *ht, char* caption, char *text,
				 char *xcoord, char *ycoord);
void OutputImage(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *filename);
/*void OutputLabel(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *caption);*/

void OutputLabel(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *caption);
void OutputCheck(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *caption);
void OutputFrame(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *caption,int&);
void OutputFrameContd(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *caption);
void OutputHscroll(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord);
void OutputVscroll(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord);

void OutputCombo(ofstream& outfile, char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *text, int no_of_array_items);
void OutputComboContd(ofstream& outfile, char *xcoord, char *ycoord);
