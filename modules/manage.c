#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "manage.h"

int get_file_size(char* arg)
{
	FILE* file = fopen(arg, "r");
	if (file == NULL) {
		perror("");
		exit(1);
	}	

	fseek(file, 0, SEEK_END);
	int fileSize = ftell(file);
	rewind(file);
	fclose(file);
	
	return fileSize;
}

char* initialize_buffer(char* arg)
{
	FILE* file = fopen(arg, "r");
	if (file == NULL) {
		perror("");
		exit(1);
	}

	int fileSize = get_file_size(arg);

	char* buffer = malloc((fileSize+1) * sizeof(char));

	fread(buffer,fileSize, 1,file);
	buffer[fileSize] = '\0';

	fclose(file);

	return buffer;
}
