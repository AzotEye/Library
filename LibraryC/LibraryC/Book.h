#pragma once

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
    char* author; 
    char* publisher; 
    char* name; 
    SectionType section;
    double review;
    Presence isAvailable;
}Book;
