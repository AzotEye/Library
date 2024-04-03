#pragma once
#define L 50

typedef enum
{
    FANTASY = 0,
    HORROR = 1,
    HISTORY = 2,
} SectionType;

typedef enum
{
    TRUE = 1,
    FALSE = 0,
} Presence;

typedef struct
{
    char author[L]; // char*
    char publisher[L]; // char*
    char name[L]; // char*

    SectionType section;

    double review;
    Presence isAvailable;
}Book;
