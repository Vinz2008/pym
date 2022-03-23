#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libs/startswith.h"
#include "interpret.h"

int main(int argc,char* argv[]) {
int i;
     if(argc==1)
    {
    printf("No Extra Command Line Argument Passed Other Than Program Name\n");
    exit(0);
    }
    else
    {
    char inputFilename[10];
    int isDebug = 0;
    for (i=1;i<argc;i++) 
    {
    if (startswith("-d", argv[i])) {
    isDebug = 1;
    }
    else {
    memset(inputFilename,0,sizeof(inputFilename));
    strcpy(inputFilename,argv[i]);
    printf("%s\n", inputFilename);
    }
    }
    interpret(inputFilename, isDebug);
    }

}
