#include "Library.h"
#include <fstream>
#include "Func.h"

Library::Library(const string Filename)
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
            this->books[i].setAutor(buf);
            getline(in, buf, ';');
            this->books[i].setPublisher(buf);
            getline(in, buf, ';');
            this->books[i].setName(buf);
            getline(in, buf, ';');
            this->books[i].setSection(stoi(buf));
            getline(in, buf, ';');
            this->books[i].setReview(stod(buf));
            getline(in, buf, ';');
            this->books[i].setAvailability(stoi(buf));
        }
    }
    in.close();

}

Library::~Library()
{
    delete[]this->books;
}

int SelectSection(Library& Lib)
{
    int section;
    do
    {
        cout << "1.Fantasy\n2.Horror\n3.Historical\nSelect section:" << endl;
        cin >> section;
    } while ((section < 1) || (section > 3));
    return section - 1;
}

void PrintSection(Library& Lib)
{
    int flag = 0, *idx = new int[Lib.getCount()];
    do
    {
        for (int i = 0; i < Lib.getCount(); i++)
        {
            idx[i] = 0;
        }
        int section = SelectSection(Lib);
        switch (section)
        {
        case 0:
            cout << "Fantasy:" << endl;
            for (int i = 0; i < Lib.getCount(); i++)
            {
                if ((Lib.getBooks())[i].getSection() == 0)
                {
                    cout << (Lib.getBooks())[i].getName() << endl;
                    idx[i] = 1;
                }
            }
            PrintFullBook(Lib, idx);
            break;
        case 1:
            cout << "Horror:" << endl;
            for (int i = 0; i < Lib.getCount(); i++)
            {
                if ((Lib.getBooks())[i].getSection() == 1)
                {
                    cout << (Lib.getBooks())[i].getName() << endl;
                    idx[i] = 1;
                }
            }
            PrintFullBook(Lib, idx);
            break;
        case 2:
            cout << "Historical:" << endl;
            for (int i = 0; i < Lib.getCount(); i++)
            {
                if ((Lib.getBooks())[i].getSection() == 2)
                {
                    cout << (Lib.getBooks())[i].getName() << endl;
                    idx[i] = 1;
                }
            }
            PrintFullBook(Lib, idx);
            break;
        }
        cout << "Chose another section?" << endl;
        cin >> flag;
    } while (flag == 1);
    delete[]idx;
    return;
}

void PrintFullBook(Library& Lib, int* idx)
{
    int flag = 0;
    do
    {
        cout << "Do you want to learn more about any book?" << endl;
        cin >> flag;
        if (flag == 0)
        {
            return;
        }
        string name;
        cout << "Enter the name of the book:" << endl;
        getchar();
        getline(cin, name);
        for (int i = 0; i < Lib.getCount(); i++)
        {
            if ((idx[i] == 1) && (name == (Lib.getBooks())[i].getName()))
            {
                cout << (Lib.getBooks())[i];
            }
        }

    } while (flag == 1);
    return;
}