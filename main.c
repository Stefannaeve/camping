#include <stdio.h>
#include <windows.h>
#include "headers/main.h"
#include "headers/log.h"
#include "Arraylist.h"

void combineLists(ITEM finalList[], ITEM list[], int finalListLength, int listListLength);
int yesOrNo(char *question);
int inputWithCharLimit(char *charArray, int iLengthOfArray);


int main(void) {
    ITEM item;
    int iStatus = 0;
    //globalDebug = TRUE;
    ITEM *finalList;

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

    ITEM startList[] = {
            {"Vann flaske", OUTSIDE_RIGHT},
            {"Vann", OUTSIDE_LEFT},
            {"Mat", MAIN_ROOM_TOP},
            {"Snacks", MAIN_ROOM_TOP},
            {"Gå Snacks", STOMACH_BELT},
            {"Kniv", TOP_CAP_TOP},
            {"Toalett Papir", TOP_CAP_BOTTOM},
            {"Wet Wipes", TOP_CAP_BOTTOM},
            {"Sokker", MAIN_ROOM_BOTTOM},
            {"Tskjorte", MAIN_ROOM_BOTTOM},
            {"Paracet", TOP_CAP_TOP},
            {"Skje", MAIN_ROOM_TOP},
            {"Sitteunderlag", OUTSIDE_RIGHT}
    };

    ITEM sunny[] = {
            {"Solkrem", FRONT_POCKET},
            {"Solbriller", FRONT_POCKET},
    };

    ITEM cold[] = {
            {"Windbreaker/Warm-sweater", ON_PERSON},
            {"Super undertøy", ON_PERSON},
            {"Buff / Skjerf", ON_PERSON},
            {"Lue", ON_PERSON},
            {"Hansker", ON_PERSON},
            {"Ullsokker", ON_PERSON}
    };

    ITEM longTrip[] = {
            {"Sovepose", OUTSIDE_FRONT},
            {"Telt", MAIN_ROOM_BOTTOM},
            {"Liggeunderlag", MAIN_ROOM_BOTTOM},
            {"Hodelykt", TOP_CAP_TOP},
            {"Lys for telt", MAIN_ROOM_BOTTOM},
            {"Tannkost", TOP_CAP_BOTTOM},
            {"Tannkrem", TOP_CAP_BOTTOM},
            {"Pute", MAIN_ROOM_BOTTOM}
    };

    ITEM baal[] = {
            {"Ved", MAIN_ROOM_BOTTOM},
            {"Lighter", TOP_CAP_TOP},
            {"Påtennings materiale", TOP_CAP_TOP}
    };

    ARRAYLIST *arraylist = makeArrayList();
    ITEM ved = {"Ved", MAIN_ROOM_BOTTOM};
    ITEM ved2 = {"Ved2", MAIN_ROOM_TOP};
    addItem(arraylist, ved);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);
    addItem(arraylist, ved2);

    /*
    logDebug("%s, %d %s", "Amund e", 10, "Dustemikkel");
    logError("Something");
    logInfo("Stefan er kul");
*/

    //iStatus = yesOrNo("Is the trip going to be longer than one day? (y/n)");
    /*
    if (iStatus == TRUE){
        combineLists(finalList,
                     longTrip,
                     (sizeof(finalList) / sizeof(finalList[0])),
                     (sizeof(longTrip) / sizeof(longTrip[0])));
    } else {
        printf("True things did not happen\n");
    }
     */

    //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    /*
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        char *placement = list[startList[i].placement];

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        printf("Placement: ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        printf("%s, ", placement);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        printf("%s\n", startList[i].item);

    }*/
    return 0;
}

void combineLists(ITEM finalList[], ITEM list[], int finalListLength, int listListLength){

}

int yesOrNo(char *question){
    char character[4] = {0};
    int iStatus = 0;

    while (1) {
        printf("%s\n", question);
        iStatus = inputWithCharLimit(character, USER_INPUT);
        if (iStatus != TRUE){
            return ERROR;
        }
        if (strncmp(character, "yes", 3) == 0){
            return TRUE;
        }
        if (character[0] == 'y' && character[1] == '\0'){
            return TRUE;
        }
        if (strncmp(character, "no", 2) == 0){
            printf("3\n");
            return FALSE;
        }
        if (character[0] == 'n' && character[1] == '\0'){
            printf("4\n");
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
    printf("Input 0: %s\n", userInput);

    while (userInput[strlen(userInput) - 1] == '\r' || userInput[strlen(userInput) - 1] == '\n') {
        userInput[strlen(userInput) - 1] = 0;
    }

    strncpy(charArray, userInput, iLengthOfArray);

    charArray[iLengthOfArray - 1] = '\0';

    fflush(stdin);

    return TRUE;
}
