#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

void print_buffer(char* buffer)
{
	char* pch = strtok(buffer, "\0");
    	printf("\n");
	int lineNumber = 0;

	printf("These are the individual lines:\n");
   	for (int i=0; pch[i] != '\0';i++) {
		if(pch[i] == '\n') printf("\t:%d", ++lineNumber);
		printf("%c", pch[i]);
		if(pch[i] == '\n') printf("\n");
    	}

	printf("These are the individual chars:\n");
	for (int i=0; pch[i] != '\0';i++) {
		if(pch[i] == '\n') printf("%d: \\n\t", i);
		else printf("%d: %c\t", i, pch[i]);
    	}
	printf("\n\n");
}

char* edit_char(char* buffer, int charToEdit)
{
    	printf("\nPlease select your char:\n");
	while((buffer[charToEdit] = getchar()) == '\n');
	printf("\n");

	return buffer;
}

void write_to_file(char* arg, char* buffer)
{
	FILE* file = fopen(arg, "w");
	if (file == NULL) {
		perror("");
		exit(1);
	}
	fprintf(file, buffer);
	fclose(file);
	printf("\n");
}
