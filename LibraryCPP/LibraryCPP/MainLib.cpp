#include <iostream>
#include "Book.h"
#include "Func.h"
#include "Library.h"

int main()
{
    int i;
    Library Lib = Library("filling.txt");
    PrintSection(Lib);
    return 0;
}