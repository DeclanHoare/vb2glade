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

/* Function Definitions ...*/
unsigned int ic_strlen(char *string)
{
	unsigned int result=0;

	do {
		result++;
		} while (string[result] != '\0');

	return result;
}

char *ic_mid(char *string, unsigned int where, unsigned int noofchars)
{
	char result[MAX_LENGTH];
	unsigned int counter=0;

	if(noofchars>strlen(string))
		return string;

	/*if(where)
		where--; // since arrays begin with 0th elements
*/

	for (unsigned int x=where; x<(where)+noofchars; x++)
	{
		result[counter]=string[x];
		counter++;
	}
	result[counter] = '\0';

	return strdup(result);
}

char *ic_left(char *string, unsigned int noofchars)
{
	char result[MAX_LENGTH];
	unsigned int counter=0;

	if(noofchars>strlen(string))
		return string;

	for(unsigned int x=0; x<noofchars;x++)
	{
		result[counter]=string[x];
		counter++;
	}
	result[counter]='\0';
	return strdup(result);
}

char *ic_right(char *string, unsigned int noofchars)
{
	char result[MAX_LENGTH];
	unsigned int counter=0;

	if(noofchars>strlen(string))
		return string;

	for(unsigned int x=strlen(string)-noofchars; x<strlen(string);x++)
	{
		result[counter]=string[x];
		counter++;
	}
	result[counter]='\0';
	return strdup(result);
}


unsigned int ic_islower(unsigned int character)
{
	if (character <= 122 && character >= 97)
		return 1;
	else
		return 0;
}

unsigned int ic_isupper(unsigned int character)
{
	if (character <= 90 && character >= 65)
		return 1;
	else
		return 0;
}

freq_of_chars     get_frequencies(char *string)
{
	freq_of_chars result;
	result.vowels=0;        result.consonants=0;
	result.spaces=0;        result.capitals=0;
	result.smalls=0;        result.others=0;
	result.digits=0;
    unsigned int x=0;

	for (x=0; x<strlen(string); x++)
	{
		 if (ic_isupper(string[x]))
			result.capitals++;
		 if (ic_islower(string[x]))
			result.smalls++;
		 if (!ic_isupper(string[x]) && !ic_islower(string[x]))
			result.others++;
	}

	for(x=0; x<strlen(string); x++)
	{
		string[x]=tolower(string[x]);

		if(string[x]=='a' || string[x]=='e' || string[x]=='i' ||
				string[x]=='o' || string[x]=='u')
		{
			result.vowels++;
		}
		else if (string[x]>=97 && string[x]<=122)
				result.consonants++;
		else if (string[x] == ' ')
			result.spaces++;
		if (string[x]>=48 && string[x]<=59)
			result.digits++;
	}
	return result;
}

void ic_strcpy (char *dest, char *src)
{
	  unsigned int x;
	  for (x=0; x<strlen(src); x++)
	  {
			dest[x]=src[x];
	  }

	  dest[x] = '\0';
}

unsigned int ic_strcmp (char *string1, char *string2)
{
	  for (unsigned int x=0; x<strlen(string1); x++)
	  {
			if(string1[x] != string2[x])
				return 0;
	  }
	return 1;
}

