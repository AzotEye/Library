#pragma once

#include "Book.h"

void fillLibrary(const char* filename, Book * Library);

void printBook(Book book);
void printSection(Book* Library, const char * section, int* idx);

void selectName(int * idx, Book * Library);
int selectSection();
void selectBook(Book* Library);