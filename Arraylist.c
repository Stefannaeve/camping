#include <malloc.h>
#include <stdio.h>
#include <memory.h>
#include "Arraylist.h"
#include "headers/main.h"
#include "headers/log.h"


ARRAYLIST* makeArrayList(){
    printf("1\n");
    ARRAYLIST *arraylist = (ARRAYLIST*) calloc(1, sizeof (ARRAYLIST));
    arraylist->itemList = (ITEM*) calloc(INITIAL_CAPACITY, sizeof (ITEM));
    arraylist->capacity = INITIAL_CAPACITY;
    arraylist->size = 0;
    printf("2\n");

    return arraylist;
}

void addItem(ARRAYLIST *arraylist, ITEM item){
    printf("3\n");
    if(arraylist->size < arraylist->capacity){
        printf("4\n");
        ITEM *temp = arraylist->itemList+arraylist->size*sizeof (ITEM);
        memcpy(temp, &item, sizeof (ITEM));
        arraylist->size++;
    } else {
        printf("5\n");
        logDebug("Inside else loop");
        ITEM *newItemList = (ITEM*) calloc(arraylist->capacity*2, sizeof(ITEM));
        for (int i = 0; i < arraylist->size; ++i) {
            newItemList[i] = arraylist->itemList[i];
        }
        printf("6\n");
        free(arraylist->itemList);

        arraylist->itemList = newItemList;
        arraylist->capacity = arraylist->capacity*2;

        ITEM *temp = arraylist->itemList+arraylist->size*sizeof (ITEM);
        memcpy(temp, &item, sizeof (ITEM));
        arraylist->size++;
    }
    printf("7\n");
}