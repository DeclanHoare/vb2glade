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


#include "stdlib.h"
/* #include "process.h" */
#include "iostream"
/* #include "conio.h" */
#include "stdio.h"
#include "string.h"
#include "icstring.h"

char * ltoa ( long value, char * str, int base );

char * ltoa ( long value, char * str, int base )
{
	sprintf(str,"%d",(int) value);
}

char *getCaption (char *string, int start_of_search, int length_of_file)
{
	char *final;
	for (int x=start_of_search; x<length_of_file; x++)
		if (string[x]=='C')
			if (!(strcmp("Caption", ic_mid(string,x,7))))
				for (int y=x+7+14; y<length_of_file; y++)
					if (string[y]=='\"')
					{
						final = (char*) malloc (sizeof(char)*y-(x+7+14)+sizeof(char));
						strcpy(final,ic_mid (string, x+7+14, y-(x+7+14)));
						return final;
					}
	return NULL;
}

char *getText (char *string, int start_of_search, int length_of_file)
{
	char *final;
	for (int x=start_of_search; x<length_of_file; x++)
		if (string[x]=='T')
			if (!(strcmp("Text  ", ic_mid(string,x,6))))
				for (int y=x+7+14; y<length_of_file; y++)
					if (string[y]=='\"')
					{
						final = (char*) malloc (sizeof(char)*y-(x+7+14)+sizeof(char));
						strcpy(final,ic_mid (string, x+7+14, y-(x+7+14)));
						return final;
					}
	return NULL;
}


char *GetPictureProperties (char *string, int start_of_search, int length_of_file)
{
	char *final;
	
	for (int x=start_of_search; x<length_of_file; x++)
		if (string[x]=='P')
			if (!(strcmp("Picture  ", ic_mid(string,x,9))))
			{
				
				for (int y=x+7+14; y<length_of_file; y++)
					if (string[y]=='\n')
					{
						final = (char*) malloc (sizeof(char)*y-(x+7+14)+sizeof(char));
						strcpy(final,ic_mid (string, x+7+14, y-(x+7+14)));
						return final;
					}
			}
	
	return NULL;
}


char *GetListProperties (char *string, int start_of_search, int length_of_file)
{
	char *final;
	for (int x=start_of_search; x<length_of_file; x++)
	{
		if (string[x]=='E')
			if (!(strcmp("End", ic_mid(string,x,3))))
			{
				return NULL;
			}

		if (string[x]=='L')
			if (!(strcmp("List  ", ic_mid(string,x,6))))
				for (int y=x+7+14; y<length_of_file; y++)
					if (string[y]=='\n')
					{
						final = (char*) malloc (sizeof(char)*y-(x+7+14)+sizeof(char));
						strcpy(final,ic_mid (string, x+7+14, y-(x+7+14)));
						return final;
					}
	}
	return NULL;
}



char *getClientWidth (char *string, int start_of_search, int length_of_file)
{
	char *final, *temp;
	for (int x=start_of_search; x<length_of_file; x++)
		if (string[x]=='C')
			if (!(strcmp("ClientWidth", ic_mid(string,x,11))))
				for (int y=x+11+9; y<length_of_file; y++)
					if (string[y]=='\n')
					{
						final = (char*) malloc (sizeof(char)*y-(x+11+9)+sizeof(char));
						strcpy(final,ic_mid (string, x+11+9, y-(x+11+9)));

						long width1;
						width1=long(strtod(final,&temp));
						width1/=15;

						ltoa(width1, final, 10);

						return final;
					}
	return NULL;
}

char *getClientHeight (char *string, int start_of_search, int length_of_file)
{
	char *final, *temp;
	for (int x=start_of_search; x<length_of_file; x++)
		if (string[x]=='C')
			if (!(strcmp("ClientHeight", ic_mid(string,x,12))))
				for (int y=x+12+8; y<length_of_file; y++)
					if (string[y]=='\n')
					{
						final = (char*) malloc (sizeof(char)*y-(x+12+8)+sizeof(char));
						strcpy(final,ic_mid (string, x+12+8, y-(x+12+8)));

						long height;
						height=long(strtod(final,&temp));
						height/=15;

						ltoa(height, final, 10);

						return final;
					}
	return NULL;
}


char *getHeight (char *string, int start_of_search, int length_of_file)
{
	char *final, *temp;
	for (int x=start_of_search; x<length_of_file; x++)
		if (string[x]=='H')
			if (!(strcmp("Height", ic_mid(string,x,6))))
				for (int y=x+6+14; y<length_of_file; y++)
					if (string[y]=='\n')
					{
						final = (char*) malloc (sizeof(char)*y-(x+12+8)+sizeof(char));
						strcpy(final,ic_mid (string, x+6+14, y-(x+12+8)));

						long height;
						height=long(strtod(final,&temp));
						height/=15;

						ltoa(height, final, 10);

						return final;
					}
	return NULL;
}


char *getWidth (char *string, int start_of_search, int length_of_file)
{
	char *final, *temp;
	for (int x=start_of_search; x<length_of_file; x++)
		if (string[x]=='W')
			if (!(strcmp("Width", ic_mid(string,x,5))))
				for (int y=x+11+9; y<length_of_file; y++)
					if (string[y]=='\n')
					{
						final = (char*) malloc (sizeof(char)*y-(x+11+9)+sizeof(char));
						strcpy(final,ic_mid (string, x+11+9, y-(x+11+9)));

						long width1;
						width1=long(strtod(final,&temp));
						width1/=15;

						ltoa(width1, final, 10);

						return final;
					}
	return NULL;
}

char *getTop (char *string, int start_of_search, int length_of_file)
{
	char *final, *temp;
	for (int x=start_of_search; x<length_of_file; x++)
		if (string[x]=='T')
			if (!(strcmp("Top", ic_mid(string,x,3))))
				for (int y=x+11+9; y<length_of_file; y++)
					if (string[y]=='\n')
					{
						final = (char*) malloc (sizeof(char)*y-(x+11+9)+sizeof(char));
						strcpy(final,ic_mid (string, x+11+9, y-(x+11+9)));

						long width1;
						width1=long(strtod(final,&temp));
						width1/=15;

						ltoa(width1, final, 10);

						return final;
					}
	return NULL;
}

char *getLeft (char *string, int start_of_search, int length_of_file)
{
	char *final, *temp;
	for (int x=start_of_search; x<length_of_file; x++)
		if (string[x]=='L')
			if (!(strcmp("Left", ic_mid(string,x,4))))
				for (int y=x+11+9; y<length_of_file; y++)
					if (string[y]=='\n')
					{
						final = (char*) malloc (sizeof(char)*y-(x+11+9)+sizeof(char));
						strcpy(final,ic_mid (string, x+11+9, y-(x+11+9)));

						long width1;
						width1=long(strtod(final,&temp));
						width1/=15;

						ltoa(width1, final, 10);

						return final;
					}
	return NULL;
}


void getBeginEndPos (char *string, int *starting, int *end, int length_of_file)
{
	//int starting[20];
	//int end[20];
	int widget_counter=0;
	for (int x=0; x<length_of_file; x++)
	{
		if (!(strcmp("Begin", ic_mid(string,x,5))))
		{
			starting[widget_counter]=x;
			for (int y=x+5; y<length_of_file; y++)
			{
				if ( !(strcmp("End", ic_mid(string,y,3))) )
				{
					end[++widget_counter]=x+y;
					break;
				}
			}
		}
	}
	
}


int
GetAllProperties (int widgetno, int starting, int end, char *string, char **type, 
				  char **name, char **wd, char **ht, char** caption, char **text, 
				  char **xcoord, char **ycoord)
{
	int type_done=0;
	int name_done=0;
	int caption_done=0;
	int this_pos;
	int x,y;

	// For type
	for (x=starting+9; x<end; x++)
		for (y=x; y<end; y++)
			if(string[y]==' ' && type_done!=1)
			{
				type[widgetno]=ic_mid(string,starting+9,y-(starting+9) );
				type_done=1;
				this_pos=y+1;
			}

	// For name
	for (y=this_pos+1; y<end; y++)
		if(string[y]=='\n' && name_done!=1)
		{
			name[widgetno]=ic_mid(string,this_pos,y-this_pos-1 );
			name_done=1;
			this_pos=y+1; break;
		}

	//Other Properties
	caption[widgetno]=getCaption(string,y,end);
	text[widgetno]=getText(string,y,end);
	ht[widgetno]=getHeight(string,y,end);
	wd[widgetno]=getWidth(string,y,end);
	ycoord[widgetno]=getTop(string,y,end);
	xcoord[widgetno]=getLeft(string,y,end);

	return y;

}
