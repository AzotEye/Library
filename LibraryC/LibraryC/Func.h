#pragma once

#include "Book.h"

typedef struct
{
    Book* books;
    int count;
} Library;


void fillLibrary(const char* filename, Book * Library);
// void fillLibrary(const char* filename, Library* lib);

void printBook(Book book);
// void printBook(const Book* book);
void printSection(Book* Library, const char * section, int* idx);
// void getSectionBooks(Library* lib, SectionType section, int** idx, int *n);

void selectName(int * idx, Book * Library);
// void selectByName(int* idx, int n, Library* lib);
int selectSection();
void selectBook(Book* Library);
// void selectBook(Library* lib);