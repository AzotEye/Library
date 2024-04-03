#include <stdio.h>
#include <string.h>
#include "Func.h"

void fillLibrary(const char* filename, Library* Lib)
{
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("The file was not found");
        abort();
    }
    fscanf(f, "%d", &Lib->count);
    Lib->books = (Book*)malloc(Lib->count * sizeof(Book));
    int i = 0;
    for (i = 0; i < Lib->count; i++)
    {
        fscanf(f, "%s %s %s %d %lf %d ", &Lib->books[i].author, &Lib->books[i].publisher,
            &Lib->books[i].name, &Lib->books[i].section, &Lib->books[i].review, &Lib->books[i].isAvailable);
    }
    fclose(f);
    return;
}

void printBook(Book* book)
{
    switch (book->section)
    {
    case 0:
        printf("Section: Fantasy; ");
        break;
    case 1:
        printf("Section: Horror; ");
        break;
    case 2:
        printf("Section: History; ");
        break;
    }
    printf("Author: %s; Publisher: %s; Name: %s; Star review: %lf/5; Availability: %d;\n", book->author, book->publisher, book->name, book->review, book->isAvailable);
    return;
}

void getSectionBooks(Library* Lib, int section, int** idx)
{    
    int i = 0;
    idx = (int**)malloc(Lib->count * sizeof(int*));
    for (i = 0; i < Lib->count; i++)
    {
        idx[i] = 0;
    }
    switch (section)
    {
    case 0:
        printf("Fantasy");
        break;
    case 1:
        printf("Horror");
        break;
    case 2:
        printf("History");
        break;
    }
    for (i = 0; i < Lib->count; i++)
    {
        if (Lib->books[i].section == section)
        {
            printf("%s\n", Lib->books[i].name);
            idx[i] ++;
        }
    }
    return;
}

void selectByName(int* idx, Library* Lib)
{
    int flag = 1;
    while (flag == 1)
    {
        printf("\nDo you want to view more data about any book? ");
        scanf("%d", &flag);

        if (flag != 1)
        {
            return;
        }
        
        char bookName[50];
        int i = 0;

        printf("\nInput the name of the book: ");
        scanf("%s", &bookName);

        for (i = 0; i < Lib->count; i++)
        {
            if ((idx[i] == 1) && (strcmp(Lib->books[i].name, bookName) == 0))
            {
                printBook(&Lib->books[i]);
            }
        }
    };
    return;
}

int selectSection()
{
    int section = 0;
    do
    {
        printf("Sections:\n1.Horror\n2.Fantasy\n3.Historical\nChoose any section: ");
        scanf("%d", &section);
        section--;
    } while ((section > 3) || (section < 1));
    return section;
}

void selectBook(Library* Lib)
{
    int section, flag = 0;
    int** idx;
    do 
    {
        section = selectSection(); 
        int* idx = NULL;
        switch (section)
        {
        case 0:
            getSectionBooks(Lib, section, *idx);
            selectByName(*idx, Lib);
            break;
        case 1:
            getSectionBooks(Lib, section, *idx);
            selectByName(*idx, Lib);
            break;
        case 2:
            getSectionBooks(Lib, section, *idx);
            selectByName(*idx, Lib);
            break;
        default:
            break;
        }
        
        printf("\nChoose another section? ");
        scanf("%d", &flag);
        printf("\n");

    } while (flag == 1);
    
    return;
}