//
// Created by Stefan on 05/10/2024.
//

#ifndef TELTTUR_ARRAYLIST_H
#define TELTTUR_ARRAYLIST_H

#include "headers/main.h"

#define INITIAL_CAPACITY 8

typedef struct {
    ITEM *itemList;
    int capacity;
    int size;
} ARRAYLIST;

ARRAYLIST* makeArrayList();
void addItem(ARRAYLIST *arraylist, ITEM item);
void appendSecondListToFirst(ARRAYLIST *mainList, ARRAYLIST *secondList);

#endif //TELTTUR_ARRAYLIST_H
