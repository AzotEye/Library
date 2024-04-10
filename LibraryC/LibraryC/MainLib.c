#include <stdio.h>
#include <stdlib.h>
#include "Func.h"

int main(int argc ,char ** argv)
{
    Library Lib;
    char* infilename;
    if (argc < 2)
    {
        printf("Incorrect arguments!");
        return 0;
    }
    infilename = argv[1];   
    fillLibrary(infilename, &Lib);
    selectSection(&Lib);
    wipe(&Lib);
    return 0;
}