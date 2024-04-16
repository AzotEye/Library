#include <stdio.h>
#include <stdlib.h>                                               
#include <string.h>
#include "Func.h"


void allstr(Book* book)
{
    book->author = (char*)malloc(L * sizeof(char));
    book->publisher = (char*)malloc(L * sizeof(char));
    book->name = (char*)malloc(L * sizeof(char));
    return;
} 

void wipe(Library* Lib)
{
    int i;
    for (i = 0; i < Lib->count; i++)
    {
        free(Lib->books[i].author);
        free(Lib->books[i].name);
        free(Lib->books[i].publisher);
    }
    free(Lib->books);
    return;
}

void printBook(Book* book)
{
    char* section = NULL, * avail = NULL;
    switch (book->section)
    {
    case 0:
        section = "Fantasy";
        break;
    case 1:
        section = "Horror";
        break;
    case 2:
        section = "Historical";
        break;
    }
    switch (book->isAvailable)
    {
    case 0:
        avail = "Not_Available";
        break;
    case 1:
        avail = "Available";
        break;
    }
    printf("%s by %s. Section: %s. Publisher: %s. Star rating: %lf. Availability: %s\n", book->name, book->author, section, book->publisher, book->review, avail);
    return;
}

void fillLibrary(const char* filename, Library* Lib)
{
    int i;
    char *buf, *fub;
    FILE* f = fopen(filename, "r");
    if (f == NULL)      
    {
        printf("The file was not found");
        abort();
    }    
    fscanf(f, "%d ", &(Lib->count));
    Lib->books = (Book*)malloc(Lib->count * sizeof(Book));
    for (i = 0; i < Lib->count; i++)
    {
        allstr(&(Lib->books[i]));
        buf = (char*)malloc(sizeof(char) * L);
        fgets(buf, 255, f);
        fub = strtok(buf, ";");
        Lib->books[i].author = fub;
        fub = strtok(NULL, ";");
        Lib->books[i].publisher = fub;
        fub = strtok(NULL, ";");
        Lib->books[i].name = fub;
        fub = strtok(NULL, ";");
        Lib->books[i].section = atoi(fub);
        fub = strtok(NULL, ";");
        Lib->books[i].review = atoi(fub);
        fub = strtok(NULL, ";");
        Lib->books[i].isAvailable = atoi(fub);
        fub = strtok(NULL, ";");
        
    }
    fclose(f);
    return;
}

int printSection()
{
    int section = 0;
    do
    {
        printf("Select section:\n1.Fantasy\n2.Horror\n3.Historycal\n");
        scanf("%d", &section);
    } while ((section > 3) || (section < 1));
    return section - 1;
}

void printSectionBooks(int section, Library* Lib, int ** idx)
{
    int i, k = 1;
    
    all_idx(idx, Lib->count);
    for (i = 0; i < Lib->count; i++)
    {
        if (Lib->books[i].section == section)
        {
            printf("%d. %s\n", k, Lib->books[i].name);
            k++;
            (*idx)[i] = 1;
        }
    }
}

void all_idx(int ** idx, int n)
{
    int i;
    (*idx) = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        (*idx)[i] = 0;
    }
    return;
}

void selectSection(Library* Lib)                         
{
    int flag = 0;
    int* idx = NULL;
    do
    {
        int section = printSection();
        
        switch (section)
        {
        case 0:
            printf("Fantasy:\n");
            printSectionBooks(section, Lib, &idx);
            selectBook(idx, Lib);
            break;
        case 1:
            printf("Horror:\n");
            printSectionBooks(section, Lib, &idx);
            selectBook(idx, Lib);
            break;
        case 2:
            printf("Historical:\n");
            printSectionBooks(section, Lib, &idx);
            selectBook(idx, Lib);
            break;
        }
        printf("Choose another seciton?\n");
        scanf("%d", &flag);
        
    } while (flag == 1);
    free(idx);
    return;
}

void selectBook(int* idx, Library* Lib)
{
    int flag = 0, i;
    char trs[1], *bknm;
    do 
    {
        bknm = (char*)malloc(L * sizeof(char));
        printf("Do you want to learn more about any book?\n");
        scanf("%d", &flag);
        if (flag != 1)
        {
            break;
        }        
        printf("Enter name of the book:\n");
        scanf("%c", &trs);
        gets_s(bknm, L);
        for (i = 0; i < Lib->count; i++)
        {
            if ((strcmp(Lib->books[i].name, bknm) == 0) && (idx[i] == 1))
            {
                printBook(&(Lib->books[i]));
            }
        }
        free(bknm);
    } while (flag == 1);
    return;
}