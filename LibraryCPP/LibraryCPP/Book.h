#pragma once
#include <string>
#include <iostream>
using namespace std;

enum SCTN { Fantasy, Horror, Historical };

class Book
{
public:
    string Name;
    string Autor;
    string Publisher;
    double Review;
    SCTN Section;
    bool Availability;

    friend ostream& operator << (ostream& os, const Book& book)
    {
        string sect, avail;
        switch (book.Section)
        {
        case SCTN::Fantasy:
            sect = "Fantasy";
            break;
        case SCTN::Horror:
            sect = "Horror";
            break;
        case SCTN::Historical:
            sect = "Historical";
            break;
        }
        switch (book.Availability)
        {
        case 0:
            avail = "Available";
            break;
        case 1:
            avail = "Not available";
            break;
        }
        os << "'" << book.Name << "' by " << book.Autor << ". Section: "<< sect << ". Star rating: " << book.Review << "/5. Availability: " << avail << endl;
        return os;
    }
};

