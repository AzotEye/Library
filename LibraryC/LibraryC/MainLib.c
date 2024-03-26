#include <stdio.h>
#include "Func.h"

int main(int argc ,char ** argv)
{
    if (argc < 2)
    {
        printf("Incorrect arguments!");
        return 0;
    }

    char* infilename = argv[1];
    Book Library[10];

    fillLibrary(infilename, Library);
    selectBook(Library);

    return 1;
}