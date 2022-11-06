#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <psapi.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

//typedef char small[100];

// struct to collect counting info about english letters found in a text file.
struct letter
{
    // Change to small1
    char small1;
    char big;
    int counter;
    // Add next and prev
    struct letter* next;
    struct letter* prev;
};


//Function to free linked list
void freeList(struct letter* head)
{
    struct letter* releaseItem;
    struct letter* runItem = head;
    while (runItem != NULL) {
        releaseItem = runItem;
        runItem = runItem->next;
        free(releaseItem);
    }
}

void targil3()
{
    //Next two string represents all the english alphabets (small1 and capital)
    char* smallAlpha = "abcdefghijklmnopqrstuvwxyz";
    char* bigAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // Change to char
    char lettersCountArr[30] = { 0 };
    char readChar, ch;
    FILE* f;
    f = fopen("myFile.txt", "r");

    // Dis[lay the content of myFile.txt and count letters
    printf("the content of myFile.txt :\n");
    // Change 0 => EOF
    while ((readChar = fgetc(f)) != EOF) {
        printf("%c", readChar);
        for (int i = 0; i < strlen(smallAlpha); ++i) {
            // I added brackets
            if (readChar == smallAlpha[i] || readChar == bigAlpha[i])
            {
                lettersCountArr[i]++;
            }
        }
    }
    fclose(f);

    // Build Linked list from file content
    // Every node represent English letter (small1 and big).

    struct letter* HEAD = NULL;
    struct letter* TAIL = NULL;
    for (int j = 0; j < strlen(smallAlpha); ++j) {
        struct letter* letterItem = (struct letter*)malloc(sizeof(struct letter));
        if (!letterItem) {
            puts("Error Allocating Memory!");
            exit(1);
        }

        letterItem->small1 = 'a' + j;
        letterItem->big = 'A' + j;
        letterItem->counter = lettersCountArr[j];
        letterItem->next = NULL;
        letterItem->prev = NULL;


        // Creating the linked list
        if (HEAD == NULL)
        {
            HEAD = letterItem;
            TAIL = letterItem;
        }
        else
        {
            TAIL->next = letterItem;
            letterItem->prev = TAIL;
            TAIL = letterItem;
        }
    }
    
    
    freeList(HEAD);

    return 0;
}