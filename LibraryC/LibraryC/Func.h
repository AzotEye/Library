#pragma once

#include "Book.h"
#define L 255
typedef struct
{
    Book* books;
    int count;
} Library;

void allstr(Book* book);
void wipe(Library* Lib);
void fillLibrary(const char* filename, Library* Lib);
void printBook(Book* book);
int printSection();
void selectSection(Library* Lib);
void printSectionBooks(int section, Library* Lib, int** idx);
void selectBook(int* idx, Library* Lib);
void all_idx(int** idx, int n);
