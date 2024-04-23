#pragma once
#include <string>
#include <iostream>
using namespace std;


class Book
{
private:
    string Name;
    string Autor;
    string Publisher;
    double Review;
    int Section;
    int Availability;
public:
    string getName() const { return Name; };
    string getAutor() const { return Autor; };
    string getPublisher() const { return Publisher; };
    double getReview() const { return Review; };
    int getSection() const { return Section; };
    int getAvailability() const { return Availability; };

    void setName(string name) { Name = name; }
    void setAutor(string autor) { Autor = autor; }
    void setPublisher(string publisher) { Publisher = publisher; }
    void setReview(double review) { Review = review; }
    void setSection(int section) { Section = section; }
    void setAvailability(int availability) { Availability = availability; }

    friend ostream& operator << (ostream& os, const Book& book)
    {
        string sect, avail;
        switch (book.getSection())
        {
        case 0:
            sect = "Fantasy";
            break;
        case 1:
            sect = "Horror";
            break;
        case 2:
            sect = "Historical";
            break;
        }
        switch (book.getAvailability())
        {
        case 0:
            avail = "Available";
            break;
        case 1:
            avail = "Not available";
            break;
        }
        os << "'" << book.getName() << "' by " << book.getAutor() << ". Section: "<< sect << ". Star rating: " << book.getReview() << "/5. Availability: " << avail << endl;
        return os;
    }
};

