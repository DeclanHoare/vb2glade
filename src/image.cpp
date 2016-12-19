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
#include <unistd.h>
#include "stdio.h"
/* #include "conio.h" */
#include "stdlib.h"
#include "string.h"
#include "icstring.h"
#include "fstream"
/* #include "direct.h" */

long filesize(FILE *stream)
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
}

int isBmp (char *filename)
{
	FILE *infile;
	char buffer[10];
	int counter=0;

	infile = fopen(filename, "r");
	if (!infile)
	{
		cout<<"\nError loading file...: "<<filename<<endl;
		return 0;
	}

	for (int x=0; x<2; x++)
	{
		buffer[counter++]=char(fgetc(infile));
	}	buffer[counter]='\0';

	fclose(infile);

	if (!(strcmp("BM", buffer)))
		return 1;
	else
		return 0;
}


void CreateImageFile(char *property, char *pic_file_name, char *destfilename, char *proj_directory)
{
	char *address=(char*)malloc(sizeof(char)*4);
	char *sourcefilename=(char*)malloc(sizeof(char)*256);

//*** Splitting of address and filename from property ***
	for (int x=1; x<int(strlen(property)); x++)
	{
		if (property[x] == '\"')
		{
			sourcefilename=ic_mid(property,0,x);
			address=ic_mid(property, x+2, 4);
			break;
		}
	}
//*** ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ***

	char *destfn=(char*)malloc(1000);
	strcpy(destfn, destfilename);
	strcat(destfn,".vb2g");

	long laddress=address_convert(address);
	FILE *src, *dest;
	
	src=fopen(sourcefilename,"rb");
    long fsize=filesize(src);
	void *buffer=malloc(fsize);
	
	dest=fopen(destfn,"wb");

	fseek(src, laddress+12, SEEK_SET);
	fread(buffer, 1, fsize-laddress, src);

	fwrite(buffer, 1, fsize-laddress, dest);

	fclose(dest);
	fclose(src);

	char convert_command[1000];

	if (isBmp(destfn))
		strcpy(convert_command,"bmptopnm  ");
	else		/*if jpeg*/
		strcpy(convert_command,"djpeg -pnm  ");
	
	strcat(convert_command, destfn);	
	strcat(convert_command, " | ppmtoxpm > ");	
	int len=strlen(destfn);
	destfn[len-4]='x';
	destfn[len-3]='p';
	destfn[len-2]='m';
	destfn[len-1]='\0';
	
	strcpy(property, proj_directory);
		chdir(proj_directory);
		mkdir("pixmaps", 0644);
/* Create .gladep file*/
					char proj_file[20];
					strcpy(proj_file,  proj_directory);
					strcat(proj_file, ".gladep");
					ofstream gladep(proj_file);
						gladep<<"<?xml version=\"1.0\" standalone=\"no\"?> <!--*- mode: xml -*-->"<<endl;
						gladep<<"<!DOCTYPE glade-project SYSTEM \"http://glade.gnome.org/glade-project-2.0.dtd\">"<<endl;

						gladep<<"<glade-project>"<<endl;
							gladep<<"<name>"<<proj_directory<<"</name>"<<endl;
							gladep<<"<program_name>"<<proj_directory<<"</program_name>"<<endl;
							gladep<<"<gnome_support>FALSE</gnome_support>"<<endl;
							gladep<<"<output_build_files>FALSE</output_build_files>"<<endl;
						gladep<<"</glade-project>"<<endl;

					gladep.close();


		chdir("..");
	strcat(property, "\\pixmaps\\");

	strcat(property, destfn);
    strcpy(pic_file_name, destfn);

	strcat(convert_command, property);
	system(convert_command);

	free (convert_command);

}
