#include "interpret.h"   
#include "libs/startswith.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interpret(char filename[], int debugMode) {
	FILE *fptr;
	FILE *fptr2;
	FILE *fptrtemp;
	char line[40];
	char macro[40];
	int FirstMacroPos;
	int i;
	int i2;
	fptr = fopen(filename, "r");
	if (fptr == NULL)
        {
        printf("Error! The file is empty\n");   
        exit(1);
        }
	fptrtemp = fopen("out.py", "w");
        fclose(fptrtemp);
        fptr2 = fopen("out.py", "a");
	while (fgets(line,150, fptr)) {
	if (startswith("#m",line) || startswith("#macro",line)){
	if (debugMode == 1) {
	printf("macro detected\n");
	}
	if (startswith("#m",line)) {
	FirstMacroPos = 3; 
	}
	if (startswith("#macro",line)) {
	FirstMacroPos = 6;
        }
	strncpy(macro, line + FirstMacroPos, strlen(line) - FirstMacroPos);
	printf("macro: %s\n", macro);
	}
	/*for (i = FirstMacroPos; i < strlen(line); i++){
	macro[i2] = line[i]; 
	}*/
	fprintf(fptr2, "%s",line);
	memset(line, 0, sizeof(line));
	memset(macro, 0, sizeof(macro));
	}
}

