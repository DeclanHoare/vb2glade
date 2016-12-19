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

char *getCaption (char *string, int start_of_search, int length_of_file);
char *getClientWidth (char *string, int start_of_search, int length_of_file);
char *getClientHeight (char *string, int start_of_search, int length_of_file);
char *getHeight (char *string, int start_of_search, int length_of_file);
char *getWidth (char *string, int start_of_search, int length_of_file);
char *getTop (char *string, int start_of_search, int length_of_file);
char *getLeft (char *string, int start_of_search, int length_of_file);
void getBeginEndPos (char *string, int *starting, int *end, int length_of_file);
char *getText (char *string, int start_of_search, int length_of_file);
char *GetPictureProperties (char *string, int start_of_search, int length_of_file);
char *GetListProperties (char *string, int start_of_search, int length_of_file);

int GetAllProperties (int widgetno, int starting, int end, char *string, char **type, 
				  char **name, char **wd, char **ht, char** caption, char **text,
				  char **xcoord, char **ycoord);