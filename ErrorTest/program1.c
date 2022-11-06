#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <psapi.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

int program1()
{
    // כתבו תוכנית שקולטת מחרוזת ומחלקת אותה לשניים, מדפיסה את שתי המחרוזות בשורות נפרדות - המחרוזת לא תהיה גדולה מ 100 תוים

    char str[100];
    char firstStr[50];
    char secondStr[50];
    char* ptr = str;  // מצביע על הכתובת הנוכחית
    char* start = str;  // מצביע על הכתובת הראשונה
    printf("\nplease enter a str: \n");
    getchar();
    gets(str);

    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
    {
        ptr++;
    }

    strncpy(firstStr, start, len / 2);
    firstStr[len / 2] = 0;
    strcpy(secondStr, ptr);
    printf("%s\n", firstStr);
    printf("%s\n", secondStr);

    return 0;
}