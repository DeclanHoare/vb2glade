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


void OutputRadio(ofstream& outfile, const char* name, const char* wd, const char* ht, char* caption,
				 const char* xcoord, const char* ycoord);
void OutputButton(ofstream& outfile,const char* name, const char* wd, const char* ht, char* caption,
				 const char* xcoord, const char* ycoord);
void OutputEntry(ofstream& outfile,const char* name, const char* wd, const char* ht, const char* text,
				 const char* xcoord, const char* ycoord);
void OutputImage(ofstream& outfile,const char* name, const char* wd, const char* ht, const char* xcoord,
				 const char* ycoord, const char* filename);
/*void OutputLabel(ofstream& outfile,const char* name, const char* wd, const char* ht, const char* xcoord,
				 const char* ycoord, const char* caption);*/

void OutputLabel(ofstream& outfile,const char* name, const char* wd, const char* ht, const char* xcoord,
				 const char* ycoord, const char* caption);
void OutputCheck(ofstream& outfile,const char* name, const char* wd, const char* ht, const char* xcoord,
				 const char* ycoord, const char* caption);
void OutputFrame(ofstream& outfile,const char* name, const char* wd, const char* ht,
				 int& fixed_no);
void OutputFrameContd(ofstream& outfile, const char* xcoord,
				 const char* ycoord, const char* caption);
void OutputHscroll(ofstream& outfile,const char* name, const char* wd, const char* ht, const char* xcoord,
				 const char* ycoord);
void OutputVscroll(ofstream& outfile,const char* name, const char* wd, const char* ht, const char* xcoord,
				 const char* ycoord);
void OutputCombo(ofstream& outfile, const char* name, const char* wd, const char* ht, const char* text);
void OutputComboContd(ofstream& outfile, const char* xcoord, const char* ycoord);
