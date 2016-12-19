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
#include "stdlib.h"
/* #include "process.h" */
#include "iostream"
/* #include "conio.h" */
#include "stdio.h"
#include "string.h"
#include "fstream"
#include "list.h"


/*long filesize(FILE *stream)
{
   long curpos, length;

   curpos = ftell(stream);
   fseek(stream, 0L, SEEK_END);
   length = ftell(stream);
   fseek(stream, curpos, SEEK_SET);
   return length;
}

long address_convert(char *string)
{
	 char *endptr;
	 long lnumber;

	 lnumber = strtol(string, &endptr, 16);
	 return lnumber;
}*/


void OutputList(ofstream& outfile, char list_array[20][20], int no_of_items, int &list_item_no)
{

for (int x=0; x<no_of_items; x++)
{
	outfile<<"\n"<<"\t\t\t\t\t\t\t";

	/*char *list_item_no;
	itoa(x,list_item_no,10);*/

	outfile<<"<child>"<<"\n"<<"\t\t\t\t\t\t\t\t";
		outfile<<"<widget class=\"GtkListItem\" id=\"ListItem"<<++list_item_no<<"\">"<<"\n"<<"\t\t\t\t\t\t\t\t\t";
			outfile<<"<property name=\"visible\">True</property>"<<"\n"<<"\t\t\t\t\t\t\t\t\t";
			outfile<<"<property name=\"can_focus\">True</property>"<<"\n"<<"\t\t\t\t\t\t\t\t\t";
			outfile<<"<property name=\"label\" translatable=\"yes\">"<<list_array[x]<<"</property>"<<"\n"<<"\t\t\t\t\t\t\t\t";
		outfile<<"</widget>"<<"\n"<<"\t\t\t\t\t\t\t";
	outfile<<"</child>"<<"\n\n"<<"\t\t\t\t\t\t\t";
}
}

/*
	  <child internal-child="list">
	    <widget class="GtkList" id="combo-list1">
	      <property name="visible">True</property>
	      <property name="selection_mode">GTK_SELECTION_BROWSE</property>

	      <child>
			<widget class="GtkListItem" id="listitem19">
			  <property name="visible">True</property>
			  <property name="can_focus">True</property>
			  <property name="label" translatable="yes">Ishan</property>
			</widget>
	      </child>

	      <child>
			<widget class="GtkListItem" id="listitem20">
				<property name="visible">True</property>
				<property name="can_focus">True</property>
				<property name="label" translatable="yes">Sushant</property>
			</widget>
	      </child>

	      <child>
			<widget class="GtkListItem" id="listitem21">
				<property name="visible">True</property>
				<property name="can_focus">True</property>
				<property name="label" translatable="yes">Rajeev</property>
			</widget>
	      </child>
	    </widget>
	  </child>
*/


void Process_and_Output_List_from_file (ofstream& outfile, char *filename,
										int no_of_items, int& list_item_no)
{

	FILE *file; int x=0;
	
	file=fopen(filename,"r");
		if(!file)
		{
//			cout<<"This list is empty: "<<filename<<endl;
			return;
		}

	int words=0,chars=0;
	char list_array[20][20]; //=(char**)malloc(1000);

	

	for (x=0; x<filesize(file); x++)
	{
		char ch=fgetc(file);
		if(!file)
			break;

		if(ch>46 && ch<=120)
			list_array[words][chars++]=ch;			
		else
		{
			list_array[words++][chars]='\0';
			chars=0;					
		}
		
	}
	
	fclose(file);

	/*for (x=0; x<no_of_items; x++)
		cout<<list_array[x]<<endl;*/

	OutputList(outfile, list_array, no_of_items, list_item_no);

}


int Create_and_store_List(char *sourcefilename, char *listaddr, char *listname, char *type)
{
	long llistaddr=address_convert(listaddr);
	FILE *src;
	char **list=(char**)malloc(100000);
	
	src=fopen(sourcefilename,"rb");
		long fsize=filesize(src);
		char buffer;
		void *ptrbuf=&buffer;

		fseek(src, llistaddr, SEEK_SET);

		ofstream outfile(listname);
		
		int started=0,char_no=0;
		int nulls_in_a_row=0;
		int no_of_items=0;				//BUG

		
		for (int x=0; x<fsize-llistaddr; x++)
		{
			fread(ptrbuf, 1, 1, src);

			if(!buffer && started)
			{
				nulls_in_a_row++;
				if(nulls_in_a_row>1)
				{
					//no_of_items++;
					break;
				}
			}


			if (started && !buffer && char_no)
			{
				outfile<<endl;
				no_of_items++;
				char_no=0;
				
			}

			

			if ((buffer>32 && buffer<=126) )
			{
				nulls_in_a_row=0;
				outfile<<buffer;
				char_no++;
				started++;
			}
		}
		 
	outfile.close();

	fclose(src);

	if(!(strcmp(type,"ComboBox")))
	{
		outfile<<endl;
					no_of_items++;
	}


	return no_of_items;			// BUG: this variable sometimes returns incorrect values. (Check
								//		code above to rectify the problem.
	
}
