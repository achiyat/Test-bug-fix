#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <psapi.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

int program3(int num)
{
    if (num == 101)
    {
        return 0;
    }
    printf("%d\n", num);
    return program3(num + 1) + 1;
}