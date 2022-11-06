#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <psapi.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

int targil1()
{
	//  No type was defined for variable b
	int a = 4;
	int b = 7;

	float c;
	// A pointer to the address was missing "&"
	scanf("%f", &c);
	if (c == 5)
	{
		// The name of the function was "print", The correct name is "printf"
		printf("%f", c);
	}

	return 0;
}

