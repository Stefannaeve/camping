//
// Created by Stefan on 21/09/2024.
//

#ifndef TELTTUR_MAIN_H
#define TELTTUR_MAIN_H

#define ARRAY_LENGTH 2
#define USER_INPUT 4

#define ERROR -1
#define FALSE 0
#define TRUE 1

typedef enum {
    MAIN_ROOM_BOTTOM,
    MAIN_ROOM_TOP,
    SIDE_ROOM_LEFT,
    SIDE_ROOM_RIGHT,
    TOP_CAP_BOTTOM,
    TOP_CAP_TOP,
    OUTSIDE_LEFT,
    OUTSIDE_RIGHT,
    FRONT_POCKET,
    OUTSIDE_FRONT,
    STOMACH_BELT,
    ON_PERSON
} PLACEMENT;

typedef struct {
    char *item;
    PLACEMENT placement;
    char *color;
} ITEM;

#endif //TELTTUR_MAIN_H
