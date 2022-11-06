#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <psapi.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

int program2()
{

    char str[100];
    char firstStr[50];
    char secondStr[50];
    char* ptr = str;  
    char* start = str;  
    int lenStr;
    printf("please enter a str: \n");
    gets(str);
     
    while (str[0] != 0)  //strlen(str) == 0
    {
        int len = strlen(str);

        if (len != 1)
        {
            for (int i = 0; i < len / 2; i++)
            {
                ptr++;
            }

            strncpy(firstStr, start, len / 2);
            firstStr[len / 2] = 0;
            strcpy(str, ptr);
            printf("%s\n", firstStr);
        }
        else
        {
            printf("%s\n", str);
            str[0] = 0;
        }
    }


    return 0;
}