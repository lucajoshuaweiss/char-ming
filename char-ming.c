#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./modules/manage.h"
#include "./modules/functions.h"

/*
 *
 * Single-char-text-editor "char-ming" 
 * made by Luca Joshua Weiß
 *
 */

int main(int argc, char** argv)
{
	char *buffer = initialize_buffer(argv[1]);
	int charToEdit = 0;

	char command=' ';
	printf("\nPlease give char-ming a command (confirm with return):\n"
			"q: quit editor\n"
			"p: print file contents\n"
			"i: insert char\n"
			"w: write buffer into file\n\n");

	while(command != 'q')
	{
		switch(command){
			case 'p':
				print_buffer(buffer);
				break;
			case 'i':
				printf("\nWhich char do you want to edit?\n");
				scanf("%d", &charToEdit);
				edit_char(buffer, charToEdit);
				break;
			case 'w':
				write_to_file(argv[1], buffer);
				break;
			default:
				break;	
		}
	

		command = getchar();
	}
	printf("\n");

	free(buffer);
	return 0;
}
