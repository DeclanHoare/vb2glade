#include "icstring.h"

int
Determine_whether_there_is_a_menu(char *string, int length_of_file)
{

	for (int x=0; x<length_of_file; x++)
	{
		if (   !strcmp(   ic_mid(string,x,4)  ,"Menu")  )
		{
			return 1;
		}
	}

	
	return 0;
}
