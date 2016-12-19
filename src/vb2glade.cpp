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

#include <sys/stat.h>
#include <stdlib.h>
/* #include <process.h> */
#include <iostream>
/* #include <conio.h> */
#include <stdio.h>
#include <string.h>
#include <fstream>
/* #include <direct.h> */

#include "icstring.h"
#include "getvalues.h"
#include "image.h"
#include "list.h"
#include "output.h"


#define BUFFER_SIZE 81960


int Determine_whether_there_is_a_menu(char *string, int length_of_file);

int main(int argc, char* argv[])
{
	FILE *test_file;
	char buffer[10000];
	char *string= (char*)malloc(sizeof(int)*100000);
	char *temp= (char*)malloc(sizeof(int)*100000);
	int x,y;
	
	
	if (argc==1)
	{
		cout<<"Syntax:\n\tvb2glade <input file>.frm\n";
		exit(0);
	}


	test_file = fopen(argv[1],"r");
    if (test_file == NULL)
    {
      cout<<"Couldn't open file.";
      exit(0);
    }

	int length_of_file=0;
	
	for (;;)
	{
		if ( feof (test_file) || ferror (test_file)  )
			break;
		fgets(buffer, 2 , test_file);		
		string[length_of_file++]=buffer[0];
		
	}
	string[length_of_file-1]='\0';

	length_of_file=filesize(test_file);
	
	fclose(test_file);

	

	/* Find out Form name */
	char *FormCaption=(char *)malloc(sizeof(char)*255);
	FormCaption = getCaption (string, 0, length_of_file);
	
	/* Find out Form width */
	char *width=(char *)malloc(sizeof(char)*5);
	width = getClientWidth (string, 0, length_of_file);
	
	/* Find out Form height */
	char *height=(char *)malloc(sizeof(char)*5);
	height = getClientHeight (string, 0, length_of_file);
		
	
/* Output FILE */

	char *outfn=(char*)malloc(1000);
	strcpy(outfn,argv[1]);
	outfn[strlen(outfn)-4]='\0';

	char proj_directory[100];
	strcpy(proj_directory,outfn);
	mkdir(outfn, 0644);
	

	strcat(outfn, "\\");	
	strcat(outfn,argv[1]);
	outfn[strlen(outfn)-4]='\0';
	strcat(outfn,".glade");
	
	ofstream outfile(outfn);
	

	outfile<<"<?xml version=\"1.0\" standalone=\"no\"?> <!--*- mode: xml -*-->"<<"\n";
	outfile<<"<!DOCTYPE glade-interface SYSTEM \"http://glade.gnome.org/glade-2.0.dtd\">"<<"\n\n";
	outfile<<"<glade-interface>"<<"\n"<<"\n";

	outfile<<"<widget class=\"GtkWindow\" id=\""<<FormCaption<<"\">"<<"\n"<<"\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t";

		outfile<<"<property name=\"title\" translatable=\"yes\">"<<FormCaption<<"</property>"<<"\n"<<"\t";
		outfile<<"<property name=\"type\">GTK_WINDOW_TOPLEVEL</property>"<<"\n"<<"\t";
		outfile<<"<property name=\"window_position\">GTK_WIN_POS_NONE</property>"<<"\n"<<"\t";
		outfile<<"<property name=\"modal\">False</property>"<<"\n"<<"\t";
		outfile<<"<property name=\"resizable\">False</property>"<<"\n"<<"\t";
		outfile<<"<property name=\"destroy_with_parent\">False</property>"<<"\n"<<"\n"<<"\t";

if(Determine_whether_there_is_a_menu(string,length_of_file))
{
	
	cout<<endl<<"The menu widget (OPEN) comes now..."<<endl<<endl;

}


		outfile<<"<child>"<<"\n"<<"\t\t";
		outfile<<"<widget class=\"GtkFixed\" id=\"fixed1\">"<<"\n"<<"\t\t\t";
		outfile<<"<property name=\"width_request\">"<<width<<"</property>"<<"\n"<<"\t\t\t";
		outfile<<"<property name=\"height_request\">"<<height<<"</property>"<<"\n"<<"\t\t\t";
		outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\n";


	int starting[20];
	int end[20];
	getBeginEndPos (string, starting, end, length_of_file);

	char **type = (char **)malloc(sizeof(char)*20*20);
	char **caption = (char **)malloc(sizeof(char)*20*20);
	char **name = (char **)malloc(sizeof(char)*20*20);
	char **ht = (char **)malloc(sizeof(char)*20*20);
	char **wd = (char **)malloc(sizeof(char)*20*20);
	char **xcoord = (char **)malloc(sizeof(char)*20*20);
	char **ycoord = (char **)malloc(sizeof(char)*20*20);
	char **text = (char **)malloc(sizeof(char)*20*20);

	// for frame
	int fixed_no=1;

	// for image
	char *picture=(char*)malloc(1000);
    char *pic_file_name=(char*)malloc(1000);

	// for list
	char *sourcefilename=(char*)malloc(1000);
	char *address=(char*)malloc(1000);
	char *f_sourcefilename=(char*)malloc(1000);
	char *f_address=(char*)malloc(1000);
	char *list_property=(char*)malloc(1000);
	char *f_list_property=(char*)malloc(1000);
	int list_item_no=0;
	int no_of_list_items=0;
	int list_loop_f=0;
	int z=0;

	/* ---------------------------------------------------------------------------------------- */
	/* G E T T I N G  &  P R I N T I N G  T H E  P R O P E R T I E S  O F  T H E  W I D G E T S */
	/* ---------------------------------------------------------------------------------------- */

	for (x=1; starting[x]; x++)
	{
		z=GetAllProperties (x, starting[x], end[x], string, type, name, wd, ht, caption, text,
					  xcoord, ycoord);
		if (!(strcmp("CommandButton", type[x])))
			OutputButton(outfile, name[x], wd[x], ht[x], caption[x], xcoord[x], ycoord[x]);
		else if (!(strcmp("OptionButton", type[x])))
			OutputRadio(outfile, name[x], wd[x], ht[x], caption[x], xcoord[x], ycoord[x]);
		
		else if (!(strcmp("Menu", type[x])))
 		{
			cout<<"Menu Widget needs to be fixed!"<<endl;
		}

		else if (!(strcmp("TextBox", type[x])))
			OutputEntry(outfile, name[x], wd[x], ht[x], caption[x], text[x], xcoord[x], ycoord[x]);
		else if (!(strcmp("Label", type[x])))
			OutputLabel(outfile, name[x], wd[x], ht[x], xcoord[x], ycoord[x], caption[x]);
		else if (!(strcmp("CheckBox", type[x])))
			OutputCheck(outfile, name[x], wd[x], ht[x], xcoord[x], ycoord[x], caption[x]);
		else if (!(strcmp("HScrollBar", type[x])))
			OutputHscroll(outfile, name[x], wd[x], ht[x], xcoord[x], ycoord[x]);
		else if (!(strcmp("VScrollBar", type[x])))
			OutputVscroll(outfile, name[x], wd[x], ht[x], xcoord[x], ycoord[x]);

		else if (!(strcmp("ComboBox", type[x])))
		{
				list_property=GetListProperties (string, z, length_of_file);

				if (list_property != NULL)
					for (list_loop_f=1; list_loop_f<int(strlen(list_property)); list_loop_f++)
						{
							if (list_property[list_loop_f] == '\"')
							{
								sourcefilename=ic_mid(list_property,0,list_loop_f);
								address=ic_mid(list_property, list_loop_f+2, 4);
								break;
							}
						}
								
					if (list_property != NULL)
							no_of_list_items=Create_and_store_List(sourcefilename,address,name[x],type[x]);
					if (list_property == NULL)
							no_of_list_items=0;
 								
					//cout<<endl<<"Width is: "<<wd[x]<<endl;
					OutputCombo(outfile, name[x], wd[x], ht[x], 
									xcoord[x], ycoord[x], text[x], no_of_list_items);
					Process_and_Output_List_from_file (outfile, name[x], 
													no_of_list_items, list_item_no);

					OutputComboContd(outfile, xcoord[x], ycoord[x]);
		}


		else if (!(strcmp("PictureBox", type[x])))
		{
			picture=GetPictureProperties (string, z, end[x]);

			if (picture)
			{
				CreateImageFile (picture, pic_file_name, name[x], proj_directory);
				OutputImage(outfile, name[x], wd[x], ht[x], xcoord[x], ycoord[x], pic_file_name);
			}
			else		// If no picture is present in the picturebox
			{
				char nopic_path[100];
				strcpy(nopic_path,proj_directory);
				strcat(nopic_path,"\\pixmaps\\nopicture.xpm");
				ofstream nopic(nopic_path);
				nopic.close();
				OutputImage(outfile, name[x], wd[x], ht[x], xcoord[x], ycoord[x], "nopicture.xpm");
			}
						
		}

 		else if (!(strcmp("Frame", type[x])))
 		{
 			OutputFrame(outfile, name[x], wd[x], ht[x], xcoord[x], 
 										ycoord[x], caption[x], fixed_no);
 			
 			int no_of_childs = 0;  
 			for (int p=starting[x]; p<length_of_file; p++)
 			{
 				if (no_of_childs==1  && !(strcmp("End\n   Beg",ic_mid(string,p,10))))
				{
					no_of_childs=1;
					break;
				}

				if (!(strcmp("End\n   End",ic_mid(string,p,10))))
 					break;
 				if (!(strcmp("Begin",ic_mid(string,p,5))))
 					no_of_childs++;
 			}
 
 			no_of_childs--;

			

			for (y=1; y<=no_of_childs; y++)
 			{
 				
 							z=GetAllProperties (x+y, starting[x+y], end[x+y], string, type, name, wd, ht, caption, text,
 										  xcoord, ycoord);
 							if (!(strcmp("CommandButton", type[x+y])))
 								OutputButton(outfile, name[x+y], wd[x+y], ht[x+y], caption[x+y], xcoord[x+y], ycoord[x+y]);
 							else if (!(strcmp("OptionButton", type[x+y])))
 								OutputRadio(outfile, name[x+y], wd[x+y], ht[x+y], caption[x+y], xcoord[x+y], ycoord[x+y]);
 							else if (!(strcmp("TextBox", type[x+y])))
 								OutputEntry(outfile, name[x+y], wd[x+y], ht[x+y], caption[x+y], text[x+y], xcoord[x+y], ycoord[x+y]);
 							else if (!(strcmp("Label", type[x+y])))
 								OutputLabel(outfile, name[x+y], wd[x+y], ht[x+y], xcoord[x+y], ycoord[x+y], caption[x+y]);
 							else if (!(strcmp("CheckBox", type[x+y])))
 								OutputCheck(outfile, name[x+y], wd[x+y], ht[x+y], xcoord[x+y], ycoord[x+y], caption[x+y]);
 							else if (!(strcmp("HScrollBar", type[x+y])))
 								OutputHscroll(outfile, name[x+y], wd[x+y], ht[x+y], xcoord[x+y], ycoord[x+y]);
 							else if (!(strcmp("VScrollBar", type[x+y])))
 								OutputVscroll(outfile, name[x+y], wd[x+y], ht[x+y], xcoord[x+y], ycoord[x+y]);
 							else if (!(strcmp("Frame", type[x+y])))
 								cout<<"Nested frames not supported ... (Parent frame: "
								<<name[x]<<")"<<endl;
 
 							else if (!(strcmp("ComboBox", type[x+y])))
 							{
 								list_property=GetListProperties (string, z, length_of_file);

								if (list_property != NULL)
 									for (list_loop_f=1; list_loop_f<int(strlen(list_property)); list_loop_f++)
 									{
 										if (list_property[list_loop_f] == '\"')
 										{
 											sourcefilename=ic_mid(list_property,0,list_loop_f);
 											address=ic_mid(list_property, list_loop_f+2, 4);
 											break;
 										}
 									}
								
								if (list_property != NULL)
									no_of_list_items=Create_and_store_List(sourcefilename,address,name[x+y],type[x+y]);
								if (list_property == NULL)
									no_of_list_items=0;
 								
								OutputCombo(outfile, name[x+y], wd[x+y], ht[x+y], 
 												xcoord[x+y], ycoord[x+y], text[x+y], no_of_list_items);
 								Process_and_Output_List_from_file (outfile, name[x+y], 
 														no_of_list_items, list_item_no);

								OutputComboContd(outfile, xcoord[x+y], ycoord[x+y]);
 							}
 
	 						else if (!(strcmp("PictureBox", type[x+y])))
 							{
 								picture=GetPictureProperties (string, z, length_of_file);
 								CreateImageFile (picture, "", name[x+y],proj_directory);
 								OutputImage(outfile, name[x+y], wd[x+y], ht[x+y], xcoord[x+y], ycoord[x+y], picture);
							}
 							else
 								cout<<"Widget undetectable ....: " <<type[x+y]<<"\n";
 
 			}
 			OutputFrameContd(outfile, name[x], wd[x], ht[x], xcoord[x], ycoord[x], caption[x]);
 			x=x+y;

		
		}

		else
			cout<<"Widget undetectable ....: " <<type[x]<<"\n";
	}



	/* Ending formalities */
				outfile<<"\n"<<"\n"<<"\t\t";
				outfile<<"</widget>"<<"\n"<<"\t";

if(Determine_whether_there_is_a_menu(string,length_of_file))
{
	cout<<endl<<"The menu widget (CLOSE) comes now..."<<endl<<endl;
}


			outfile<<"</child>"<<"\n"<<"\n";
		outfile<<"</widget>"<<"\n"<<"\n";
	outfile<<"</glade-interface>";
	outfile<<"\n"<<"\n";
	

	cout<<"\nFile created: "<<outfn<<""<<endl;
	
	outfile.close();

	free(outfn);
	return 0;
}
