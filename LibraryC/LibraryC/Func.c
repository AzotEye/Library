#include <stdio.h>
#include <string.h>
#include "Func.h"

void fillLibrary(const char* filename, Book* Library)
{
    FILE* f = fopen(filename, "r");
    if (f == NULL)
    {
        printf("The file was not found");
        abort();
    }
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        fscanf(f, "%s %s %s %s %lf %s ", &Library[i].author, &Library[i].publisher, 
            &Library[i].name, &Library[i].section, &Library[i].review, &Library[i].presense);
    }
    fclose(f);
    return;
}

void printBook(Book book)
{
    printf("Author: %s; Publisher: %s; Name: %s; Section: %s; Star review: %lf/5; Availability: %s;\n", book.author, book.publisher, book.name, book.section, book.review, book.presense);
    return;
}
void printSection(Book* Library, const char* section, int* idx)
{
    int i = 0;
    printf("\n%s:\n", section);
    for (i = 0; i < 10; i++)
    {
        if (strcmp(Library[i].section, section) == 0)
        {
            printf("%s\n", Library[i].name);
            idx[i] ++;
        }
    }
    return;
}

void selectName(int * idx, Book * Library)
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

        for (i = 0; i < 10; i++)
        {
            if ((idx[i] == 1) && (strcmp(Library[i].name, bookName) == 0))
            {
                printBook(Library[i]);
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
    } while ((section > 3) || (section < 1));
    return section;
}
void selectBook(Book* Library)
{
    int section, flag = 0;
    do 
    {
        section = selectSection(); 
        int idx[10] = { 0,0,0,0,0,0,0,0,0,0 };
        switch (section)
        {
        case 1:
            printSection(Library, "Horror", idx);
            selectName(idx, Library);
            break;
        case 2:
            printSection(Library, "Fantasy", idx);
            selectName(idx, Library);
            break;
        case 3:
            printSection(Library, "Historical", idx);
            selectName(idx, Library);
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