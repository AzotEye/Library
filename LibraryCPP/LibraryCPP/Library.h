#pragma once
#include "Book.h"

class Library
{
private:
    int count;
    Book* books;
public:
    int getCount() const { return count; };
    Book* getBooks() const { return books; };
    
    Library(const string Filename);
    ~Library();
};