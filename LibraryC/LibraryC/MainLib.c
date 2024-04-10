#include <stdio.h>
#include <stdlib.h>
#include "Func.h"

int main(int argc ,char ** argv)
{
    if (argc < 2)
    {
        printf("Incorrect arguments!");
        return 0;
    }
    char* infilename = argv[1];
    
    Library *Lib = malloc(1);
    fillLibrary(infilename, Lib);  
    selectSection(Lib);
    wipe(Lib);
    return 1;
}