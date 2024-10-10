#include <stdio.h>
#include <windows.h>
#include "headers/main.h"
#include "headers/log.h"
#include "Arraylist.h"

void combineLists(ITEM finalList[], ITEM list[], int finalListLength, int listListLength);
int appendListIfYes(ARRAYLIST *mainList, ARRAYLIST *secondList, char *question);
int inputWithCharLimit(char *charArray, int iLengthOfArray);
void addItemToArrayList(ARRAYLIST *mainArray, char *name, PLACEMENT placement);


int main(void) {
    ITEM item;
    int iStatus = 0;
    ITEM *finalList;

    ARRAYLIST *mainList = makeArrayList();
    ARRAYLIST *sunny = makeArrayList();
    ARRAYLIST *cold = makeArrayList();
    ARRAYLIST *longTrip = makeArrayList();
    ARRAYLIST *baal = makeArrayList();

    char *list[] = {"Main room bottom",
            "Main room top",
            "Side room left",
            "Side room right",
            "Top cap bottom",
            "Top cap top",
            "Outside left",
            "Outside right",
            "Front pocket",
            "Outside front",
            "Stomach belt",
            "On person"
            };

    addItemToArrayList(mainList, "Vann flaske", OUTSIDE_RIGHT);
    addItemToArrayList(mainList, "Vann", OUTSIDE_LEFT);
    addItemToArrayList(mainList, "Mat", MAIN_ROOM_TOP);
    addItemToArrayList(mainList, "Snacks", MAIN_ROOM_TOP);
    addItemToArrayList(mainList, "Gå Snacks", STOMACH_BELT);
    addItemToArrayList(mainList, "Kniv", TOP_CAP_TOP);
    addItemToArrayList(mainList, "Toalett Papir", TOP_CAP_BOTTOM);
    addItemToArrayList(mainList, "Wet Wipes", TOP_CAP_BOTTOM);
    addItemToArrayList(mainList, "Sokker", MAIN_ROOM_BOTTOM);
    addItemToArrayList(mainList, "Tskjorte", MAIN_ROOM_BOTTOM);
    addItemToArrayList(mainList, "Paracet", TOP_CAP_TOP);
    addItemToArrayList(mainList, "Skje", MAIN_ROOM_TOP);
    addItemToArrayList(mainList, "Sitteunderlag", OUTSIDE_RIGHT);

    addItemToArrayList(sunny, "Solkrem", FRONT_POCKET);
    addItemToArrayList(sunny, "Solbriller", FRONT_POCKET);

    addItemToArrayList(cold, "Windbreaker/Warm-sweater", ON_PERSON);
    addItemToArrayList(cold, "Super undertøy", ON_PERSON);
    addItemToArrayList(cold, "Buff / Skjerf", ON_PERSON);
    addItemToArrayList(cold, "Lue", ON_PERSON);
    addItemToArrayList(cold, "Hansker", ON_PERSON);
    addItemToArrayList(cold, "Ullsokker", ON_PERSON);

    addItemToArrayList(longTrip, "Sovepose", OUTSIDE_FRONT);
    addItemToArrayList(longTrip, "Telt", MAIN_ROOM_BOTTOM);
    addItemToArrayList(longTrip, "Liggeunderlag", MAIN_ROOM_BOTTOM);
    addItemToArrayList(longTrip, "Hodelykt", TOP_CAP_TOP);
    addItemToArrayList(longTrip, "Lys for telt", MAIN_ROOM_BOTTOM);
    addItemToArrayList(longTrip, "Tannkost", TOP_CAP_BOTTOM);
    addItemToArrayList(longTrip, "Tannkrem", TOP_CAP_BOTTOM);
    addItemToArrayList(longTrip, "Pute", MAIN_ROOM_BOTTOM);

    addItemToArrayList(baal, "Ved", MAIN_ROOM_BOTTOM);
    addItemToArrayList(baal, "Lighter", TOP_CAP_TOP);
    addItemToArrayList(baal, "Påtennings materiale", TOP_CAP_TOP);

    logDebug("%s, %d %s", "Amund e", 10, "Dustemikkel");
    logError("Something");
    logInfo("Stefan er kul");

    iStatus = appendListIfYes(mainList, longTrip, "Is the trip going to be longer than one day? (y/n)");
    iStatus = appendListIfYes(mainList, sunny, "Is it going to be sunny? (y/n)");
    iStatus = appendListIfYes(mainList, baal, "Are you going to make a bonfire? (y/n)");
    iStatus = appendListIfYes(mainList, cold, "Is it going to be cold? (y/n)");

//    for (int i = 0; i < mainList->size; ++i) {
//        printf("%i: %s\n", i, mainList->itemList[i].item);
//    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    for (int i = 0; i < mainList->size; ++i) {
        char *placement = list[mainList->itemList[i].placement];

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        printf("Placement: ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("%s, ", placement);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("%s\n", mainList->itemList[i].item);

    }
    return 0;
}

void addItemToArrayList(ARRAYLIST *mainArray, char *name, PLACEMENT placement){
    ITEM temp = {name, placement};
    addItem(mainArray, temp);
}

int appendListIfYes(ARRAYLIST *mainList, ARRAYLIST *secondList, char *question){
    char character[4] = {0};
    int iStatus = 0;

    while (1) {
        printf("%s\n", question);
        iStatus = inputWithCharLimit(character, USER_INPUT);
        if (iStatus != TRUE){
            return ERROR;
        }
        if (strncmp(character, "yes", 3) == 0){
            printf("Appending list\n");
            appendSecondListToFirst(mainList, secondList);
            return TRUE;
        }
        if (character[0] == 'y' && character[1] == '\0'){
            printf("Appending list\n");
            appendSecondListToFirst(mainList, secondList);
            return TRUE;
        }
        if (strncmp(character, "no", 2) == 0){
            return FALSE;
        }
        if (character[0] == 'n' && character[1] == '\0'){
            return FALSE;
        }
        printf("Wrong input, it has to be \"y\" or \"n\"\n");

    }
}

int inputWithCharLimit(char *charArray, int iLengthOfArray){
    char userInput[USER_INPUT] = {0};

    if (charArray == NULL){
        errno = ENOMEM;
        printf("Memory allocation issue, given array is NULL - error message", strerror(errno));
        return ERROR;
    }

    memset(charArray, 0, iLengthOfArray);
    fgets(userInput, USER_INPUT, stdin);

    while (userInput[strlen(userInput) - 1] == '\r' || userInput[strlen(userInput) - 1] == '\n') {
        userInput[strlen(userInput) - 1] = 0;
    }

    strncpy(charArray, userInput, iLengthOfArray);

    charArray[iLengthOfArray - 1] = '\0';

    fflush(stdin);

    return TRUE;
}
