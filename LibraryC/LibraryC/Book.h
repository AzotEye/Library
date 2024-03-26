#pragma once
#define L 50

typedef struct
{
    char author[L];
    char publisher[L];
    char name[L];

    char section[L];

    double review;
    char presense[L];
}Book;