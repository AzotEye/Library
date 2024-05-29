#pragma once
#include "Book.h"

class Library
{
private:
    int count;
    Book* books;
    SCTN convert(const string& buf);
public:
    int getCount() const { return count; };
    Book* getBooks() const { return books; };
    
    SCTN SelectSection()const;
    void PrintFullBook(SCTN section)const;

    Library(const string& Filename);
    ~Library();

    friend ostream& operator << (ostream& os, const Library& Lib)
    {
        int flag = 0;
        do
        {
            SCTN section = Lib.SelectSection();
            switch (section)
            {
            case SCTN::Fantasy:
                cout << "Fantasy:" << endl;
                for (int i = 0; i < Lib.getCount(); i++)
                {
                    if ((Lib.getBooks())[i].Section == SCTN::Fantasy)
                    {
                        cout << (Lib.getBooks())[i].Name << endl;

                    }
                }
                Lib.PrintFullBook(section);
                break;
            case SCTN::Horror:
                cout << "Horror:" << endl;
                for (int i = 0; i < Lib.getCount(); i++)
                {
                    if ((Lib.getBooks())[i].Section == SCTN::Horror)
                    {
                        cout << (Lib.getBooks())[i].Name << endl;
                    }
                }
                Lib.PrintFullBook(section);
                break;
            case SCTN::Historical:
                cout << "Historical:" << endl;
                for (int i = 0; i < Lib.getCount(); i++)
                {
                    if ((Lib.getBooks())[i].Section == SCTN::Historical)
                    {
                        cout << (Lib.getBooks())[i].Name << endl;
                    }
                }
                Lib.PrintFullBook(section);
                break;
            }
            cout << "Chose another section?" << endl;
            cin >> flag;
        } while (flag == 1);
        return os;
    }
};