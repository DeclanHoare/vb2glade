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

#ifndef _icstring_h

#define _icstring_h

#include <iostream>
/* #include <conio.h> */
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/* #include <dos.h> */
#include <stdio.h>

#define MAX_LENGTH 100

/* Structures used ... */
struct freq_of_chars
{
	unsigned int capitals; 	unsigned int smalls;
	unsigned int others;		unsigned int digits;
	unsigned int vowels;    unsigned int consonants;
	unsigned int spaces;
};

/* Function Prototypes ... */
unsigned int ic_strlen(char *string);
char *ic_mid(char *string, unsigned int where, unsigned int noofchars);
char *ic_left(char *string, unsigned int noofchars);
char *ic_right(char *string, unsigned int noofchars);
unsigned int ic_islower(unsigned int character);
unsigned int ic_isupper(unsigned int character);
freq_of_chars     get_frequencies(char *string);
void ic_strcpy (char *dest, char *src);
unsigned int ic_strcmp (char *string1, char *string2);

#endif
