/* vb2glade
 * Copyright (C) 2002 Ishan Chattopadhyaya
 * Copyright 2016 Declan Hoare
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

using namespace std;
#include "iostream"
/* #include "conio.h" */
#include "getvalues.h"
#include "fstream"
#include "list.h"


void OutputFrame(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *caption, int& fixed_no)
{

	outfile<<"\t\t\t<child>"<<"\n"<<"\t\t\t\t";
	outfile<<"<widget class=\""<<"GtkFrame"<<"\" id=\""<<name<<"\">"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"width_request\">"<<wd<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"height_request\">"<<ht<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"label_xalign\">0</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"label_yalign\">0.5</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"shadow_type\">GTK_SHADOW_ETCHED_IN</property>"<<"\n\n"<<"\t\t\t\t\t";

		outfile<<"<child>"<<"\n"<<"\t\t\t\t\t\t";
			outfile<<"<widget class=\""<<"GtkFixed"<<"\" id=\"fixed"<<++fixed_no<<"\">"<<"\n"<<"\t\t\t\t\t\t\t";
				outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t";
			
			/* Enter child code here */
}

void OutputFrameContd(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *caption)
{
		outfile<<"</widget>"<<"\n\n"<<"\t\t\t\t\t";	
		outfile<<"</child>"<<"\n\n"<<"\t\t\t\t\t";

		outfile<<"<child>"<<"\n"<<"\t\t\t\t\t\t";
			outfile<<"<widget class=\"GtkLabel\" id=\"label1\">"<<"\n"<<"\t\t\t\t\t\t\t";
			outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t\t\t\t";
			outfile<<"<property name=\"label\" translatable=\"yes\">"<<caption<<"</property>"<<"\n"<<"\t\t\t\t\t\t\t";
		
			outfile<<"<property name=\"use_underline\">False</property>"<<"\n"<<"\t\t\t\t\t\t\t";
			outfile<<"<property name=\"use_markup\">False</property>"<<"\n"<<"\t\t\t\t\t\t\t";
			outfile<<"<property name=\"justify\">GTK_JUSTIFY_LEFT</property>"<<"\n"<<"\t\t\t\t\t\t\t";
			outfile<<"<property name=\"wrap\">False</property>"<<"\n"<<"\t\t\t\t\t\t\t";
			outfile<<"<property name=\"selectable\">False</property>"<<"\n"<<"\t\t\t\t\t\t\t";
			outfile<<"<property name=\"xalign\">0.5</property>"<<"\n"<<"\t\t\t\t\t\t\t";
			outfile<<"<property name=\"yalign\">0.5</property>"<<"\n"<<"\t\t\t\t\t\t\t";
			outfile<<"<property name=\"xpad\">0</property>"<<"\n"<<"\t\t\t\t\t\t\t";
			outfile<<"<property name=\"ypad\">0</property>"<<"\n"<<"\t\t\t\t\t\t";
		
		outfile<<"</widget>"<<"\n"<<"\t\t\t\t\t\t";
		outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t\t\t";
			outfile<<"<property name=\"type\">label_item</property>"<<"\n"<<"\t\t\t\t\t\t";
		outfile<<"</packing>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"</child>"<<"\n\t\t\t\t";
		
		
	outfile<<"</widget>"<<"\n"<<"\t\t\t\t";
	outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"x\">"<<xcoord<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"y\">"<<ycoord<<"</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</packing>"<<"\n"<<"\t\t\t";
	outfile<<"</child>"<<"\n\n"; 

}


void OutputCombo(ofstream& outfile, char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *text, int no_of_array_items)
{
	outfile<<"\t\t\t<child>"<<"\n"<<"\t\t\t\t";
	outfile<<"<widget class=\""<<"GtkCombo"<<"\" id=\""<<name<<"\">"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"width_request\">"<<wd<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"height_request\">"<<ht<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"value_in_list\">False</property>"<<"\n"<<"\t\t\t\t\t";

		outfile<<"<property name=\"allow_empty\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"case_sensitive\">False</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"enable_arrow_keys\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"enable_arrows_always\">False</property>"<<"\n\n"<<"\t\t\t\t\t";

		outfile<<"<child internal-child=\"entry\">"<<"\n"<<"\t\t\t\t\t\t";
			outfile<<"<widget class=\"GtkEntry\" id=\"combo-entry1\">"<<"\n"<<"\t\t\t\t\t\t\t";
				outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t\t\t";	
				outfile<<"<property name=\"can_focus\">True</property>"<<"\n"<<"\t\t\t\t\t\t\t";
				outfile<<"<property name=\"editable\">True</property>"<<"\n"<<"\t\t\t\t\t\t\t";
				outfile<<"<property name=\"visibility\">True</property>"<<"\n"<<"\t\t\t\t\t\t\t";
				outfile<<"<property name=\"max_length\">0</property>"<<"\n"<<"\t\t\t\t\t\t\t";
				outfile<<"<property name=\"text\" translatable=\"yes\">"<<text<<"</property>"<<"\n"<<"\t\t\t\t\t\t\t";
				outfile<<"<property name=\"has_frame\">True</property>"<<"\n"<<"\t\t\t\t\t\t\t";
				outfile<<"<property name=\"invisible_char\" translatable=\"yes\">*</property>"<<"\n"<<"\t\t\t\t\t\t\t";
				outfile<<"<property name=\"activates_default\">False</property>"<<"\n"<<"\t\t\t\t\t\t";
			outfile<<"</widget>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"</child>"<<"\n"<<"\t\t\t\t\t";

		outfile<<"<child internal-child=\"list\">"<<"\n"<<"\t\t\t\t\t\t";
			outfile<<"<widget class=\"GtkList\" id=\"combo-list1\">"<<"\n"<<"\t\t\t\t\t\t\t";
				outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t\t\t";	
				outfile<<"<property name=\"selection_mode\">GTK_SELECTION_BROWSE</property>"<<"\n"<<"\t\t\t\t\t\t\t";

}


void OutputComboContd(ofstream& outfile, char *xcoord, char *ycoord)
{
			outfile<<"\n\t\t\t\t\t";
			outfile<<"</widget>"<<"\n"<<"\t\t\t\t\t\t";
		outfile<<"</child>"<<"\n\n"<<"\t\t\t\t\t";
	
	outfile<<"</widget>"<<"\n\n"<<"\t\t\t";	

	outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"x\">"<<xcoord<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"y\">"<<ycoord<<"</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</packing>"<<"\n"<<"\t\t\t";
	outfile<<"</child>"<<"\n\n"; 
}


void OutputHscroll(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord)
{
	outfile<<"\t\t\t<child>"<<"\n"<<"\t\t\t\t";
	outfile<<"<widget class=\""<<"GtkHScrollbar"<<"\" id=\""<<name<<"\">"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"width_request\">"<<wd<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"height_request\">"<<ht<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"update_policy\">GTK_UPDATE_CONTINUOUS</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"inverted\">False</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"adjustment\">50 0 100 0 0 0</property>"<<"\n"<<"\t\t\t\t\t";
		
	outfile<<"</widget>"<<"\n"<<"\t\t\t\t";

	outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"x\">"<<xcoord<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"y\">"<<ycoord<<"</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</packing>"<<"\n"<<"\t\t\t";
	outfile<<"</child>"<<"\n\n"; 

}

void OutputVscroll(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord)
{
	outfile<<"\t\t\t<child>"<<"\n"<<"\t\t\t\t";
	outfile<<"<widget class=\""<<"GtkVScrollbar"<<"\" id=\""<<name<<"\">"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"width_request\">"<<wd<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"height_request\">"<<ht<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"update_policy\">GTK_UPDATE_CONTINUOUS</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"inverted\">False</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"adjustment\">50 0 100 0 0 0</property>"<<"\n"<<"\t\t\t\t\t";
		
	outfile<<"</widget>"<<"\n"<<"\t\t\t\t";

	outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"x\">"<<xcoord<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"y\">"<<ycoord<<"</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</packing>"<<"\n"<<"\t\t\t";
	outfile<<"</child>"<<"\n\n"; 

}




void OutputCheck(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *caption)
{
	outfile<<"\t\t\t<child>"<<"\n"<<"\t\t\t\t";
	outfile<<"<widget class=\""<<"GtkCheckButton"<<"\" id=\""<<name<<"\">"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"width_request\">"<<wd<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"height_request\">"<<ht<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"label\" translatable=\"yes\">"<<caption<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"use_underline\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"relief\">GTK_RELIEF_NORMAL</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"active\">False</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"inconsistent\">False</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"draw_indicator\">True</property>"<<"\n"<<"\t\t\t\t\t";
		
	outfile<<"</widget>"<<"\n"<<"\t\t\t\t";

	outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"x\">"<<xcoord<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"y\">"<<ycoord<<"</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</packing>"<<"\n"<<"\t\t\t";
	outfile<<"</child>"<<"\n\n"; 


}


void OutputLabel(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord,
				 char *ycoord, char *caption)
{
	outfile<<"\t\t\t<child>"<<"\n"<<"\t\t\t\t";
	outfile<<"<widget class=\""<<"GtkLabel"<<"\" id=\""<<name<<"\">"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"width_request\">"<<wd<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"height_request\">"<<ht<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"label\" translatable=\"yes\">"<<caption<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"use_underline\">False</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"use_markup\">False</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"can_focus\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"justify\">GTK_JUSTIFY_LEFT</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"wrap\">False</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"selectable\">False</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"xalign\">0.5</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"yalign\">0.5</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"xpad\">0</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"ypad\">0</property>"<<"\n"<<"\t\t\t\t\t";
		
	outfile<<"</widget>"<<"\n"<<"\t\t\t\t";

	outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"x\">"<<xcoord<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"y\">"<<ycoord<<"</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</packing>"<<"\n"<<"\t\t\t";
	outfile<<"</child>"<<"\n\n"; 


}


void OutputRadio(ofstream& outfile, char *name, char *wd, char *ht, char* caption,
				 char *xcoord, char *ycoord)
{
	outfile<<"\t\t\t<child>"<<"\n"<<"\t\t\t\t";
	outfile<<"<widget class=\""<<"GtkRadioButton"<<"\" id=\""<<name<<"\">"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"width_request\">"<<wd<<"</property>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"height_request\">"<<ht<<"</property>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"can_focus\">True</property>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"label\" translatable=\"yes\">"<<caption<<"</property>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"use_underline\">True</property>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"relief\">GTK_RELIEF_NORMAL</property>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"active\">False</property>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"inconsistent\">False</property>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"draw_indicator\">True</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</widget>"<<"\n"<<"\t\t\t\t";

	outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"x\">"<<xcoord<<"</property>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"<property name=\"y\">"<<ycoord<<"</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</packing>"<<"\n"<<"\t\t\t";
	outfile<<"</child>"<<"\n\n"; 
}


void OutputButton(ofstream& outfile,char *name, char *wd, char *ht, char* caption,
				 char *xcoord, char *ycoord)
{
	outfile<<"\t\t\t<child>"<<"\n"<<"\t\t\t\t";
	outfile<<"<widget class=\""<<"GtkButton"<<"\" id=\""<<name<<"\">"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"width_request\">"<<wd<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"height_request\">"<<ht<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"can_focus\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"label\" translatable=\"yes\">"<<caption<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"use_underline\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"relief\">GTK_RELIEF_NORMAL</property>"<<"\n"<<"\t\t\t\t\t";
	outfile<<"</widget>"<<"\n"<<"\t\t\t\t";

	outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"x\">"<<xcoord<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"y\">"<<ycoord<<"</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</packing>"<<"\n"<<"\t\t\t";
	outfile<<"</child>"<<"\n\n"; 
}


void OutputEntry(ofstream& outfile,char *name, char *wd, char *ht, char* caption, char *text,
				 char *xcoord, char *ycoord)
{
	outfile<<"\t\t\t<child>"<<"\n"<<"\t\t\t\t";
	outfile<<"<widget class=\""<<"GtkEntry"<<"\" id=\""<<name<<"\">"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"width_request\">"<<wd<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"height_request\">"<<ht<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"can_focus\">True</property>"<<"\n"<<"\t\t\t\t\t";

		outfile<<"<property name=\"editable\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"visibility\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"mex_length\">0</property>"<<"\n"<<"\t\t\t\t\t";
	
		outfile<<"<property name=\"text\" translatable=\"yes\">"<<text<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"has_frame\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"invisible_char\" translatable=\"yes\">*</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"activates_default\">False</property>"<<"\n"<<"\t\t\t\t\t";
				
	outfile<<"</widget>"<<"\n"<<"\t\t\t\t";

	outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"x\">"<<xcoord<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"y\">"<<ycoord<<"</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</packing>"<<"\n"<<"\t\t\t";
	outfile<<"</child>"<<"\n\n"; 
}
      
void OutputImage(ofstream& outfile,char *name, char *wd, char *ht, char *xcoord, char *ycoord, char *filename)
{
	outfile<<"\t\t\t<child>"<<"\n"<<"\t\t\t\t";
	outfile<<"<widget class=\""<<"GtkImage"<<"\" id=\""<<name<<"\">"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"width_request\">"<<wd<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"height_request\">"<<ht<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"pixbuf\">"<<filename<<"</property>"<<"\n"<<"\t\t\t\t\t";

		outfile<<"<property name=\"xalign\">0.5</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"yalign\">0.5</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"xpad\">0</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"ypad\">0</property>"<<"\n"<<"\t\t\t\t\t";
	
				
	outfile<<"</widget>"<<"\n"<<"\t\t\t\t";

	outfile<<"<packing>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"x\">"<<xcoord<<"</property>"<<"\n"<<"\t\t\t\t\t";
		outfile<<"<property name=\"y\">"<<ycoord<<"</property>"<<"\n"<<"\t\t\t\t";
	outfile<<"</packing>"<<"\n"<<"\t\t\t";
	outfile<<"</child>"<<"\n\n"; 
}


