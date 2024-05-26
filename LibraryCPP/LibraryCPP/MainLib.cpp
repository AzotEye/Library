#include <iostream>
#include "Book.h"
#include "Library.h"
#include "Func.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cout << "Wrong arguments";
        return 1;
    }
    string file = argv[1];
    Library Lib = Library(file);
    cout << Lib;
    return 0;
}