#include <malloc.h>
#include <stdio.h>
#include <memory.h>
#include "Arraylist.h"
#include "headers/main.h"
#include "headers/log.h"


ARRAYLIST* makeArrayList(){
    ARRAYLIST *arraylist = (ARRAYLIST*) calloc(1, sizeof (ARRAYLIST));
    arraylist->itemList = (ITEM*) calloc(INITIAL_CAPACITY, sizeof (ITEM));
    arraylist->capacity = INITIAL_CAPACITY;
    arraylist->size = 0;

    return arraylist;
}

void addItem(ARRAYLIST *arraylist, ITEM item){
    if(arraylist->size < arraylist->capacity){
//        ITEM *temp = arraylist->itemList + arraylist->size*sizeof (ITEM *);
        ITEM *temp = arraylist->itemList + arraylist->size;
//        ITEM *temp = &arraylist->itemList[arraylist->size];
        memcpy(temp, &item, sizeof (ITEM));
        arraylist->size++;
    } else {
        ITEM *newItemList = (ITEM *) calloc(arraylist->capacity * 2, sizeof(ITEM));
        for (int i = 0; i < arraylist->size; ++i) {
            newItemList[i] = arraylist->itemList[i];
        }
        free(arraylist->itemList);

        arraylist->itemList = newItemList;
        arraylist->capacity = arraylist->capacity * 2;

        ITEM *temp = arraylist->itemList + arraylist->size;
        memcpy(temp, &item, sizeof(ITEM));
        arraylist->size++;
    }
}
void appendSecondListToFirst(ARRAYLIST *mainList, ARRAYLIST *secondList){
    for (int i = 0; i < secondList->size; ++i) {
        addItem(mainList, secondList->itemList[i]);
    }
}