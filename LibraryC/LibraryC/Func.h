#pragma once

#include "Book.h"

typedef struct
{
    Book* books;
    int count;
} Library;


void fillLibrary(const char* filename, Library* lib);

void printBook(Book* book);

void getSectionBooks(Library* Lib, int section, int** idx);

void selectByName(int* idx, Library* Lib);

int selectSection();

void selectBook(Library* lib);