#include "Library.h"
#include "Func.h"
#include <fstream>

Library::Library(const string& Filename)
{
    ifstream in(Filename);
    if (in.is_open())
    {
        string buf;
        in >> this->count;
        this->books = new Book[this->count];
        for (int i = 0; i < this->count; i++)
        {
            getline(in, buf, ';');
            this->books[i].Autor = buf;
            getline(in, buf, ';');
            this->books[i].Publisher = buf;
            getline(in, buf, ';');
            this->books[i].Name = buf;
            getline(in, buf, ';');
            this->books[i].Section = convert(buf);
            getline(in, buf, ';');
            this->books[i].Review = stod(buf);
            getline(in, buf, ';');
            this->books[i].Availability = stoi(buf);
        }
    }
    in.close();
}

Library::~Library()
{
    delete[]this->books;
}

SCTN Library::SelectSection()const
{
    SCTN section;
    int i;
    do
    {
        cout << "1.Fantasy\n2.Horror\n3.Historical\nSelect section:" << endl;
        cin >> i;
    } while ((i < 1) || (i > 3));
    switch (i)
    {
    case 1:
        section = SCTN::Fantasy;
        break;
    case 2:
        section = SCTN::Horror;
        break;
    case 3:
        section = SCTN::Historical;
        break;
    }
    return section;
}

void Library::PrintFullBook(SCTN section)const
{
    int flag = 0;
    do
    {
        cout << "Do you want to learn more about any book?" << endl;
        cin >> flag;
        if (flag != 1)
        {
            return;
        }
        string name;
        cout << "Enter the name of the book:" << endl;
        getchar();
        getline(cin, name);
        for (int i = 0; i < this->getCount(); i++)
        {
            if (((this->getBooks())[i].Section == section) && (name == (this->getBooks())[i].Name))
            {
                cout << (this->getBooks())[i];
            }
        }

    } while (flag == 1);
    return;
}

SCTN convert(string& buf)
{
    int i = stoi(buf);
    SCTN section;
    switch (i)
    {
    case 0:
        section = SCTN::Fantasy;
        break;
    case 1:
        section = SCTN::Horror;
        break;
    case 2:
        section = SCTN::Historical;
        break;
    default:
        break;
    }
    return section;
}