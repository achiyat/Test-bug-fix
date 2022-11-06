#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <psapi.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

void targil2()
{
	// Variable x and y are not initialized
	int x = 0;
	int y = 0;
	int nums[6];
	int* arrPtr;

	// Section A - Print the variables
	puts("***** Section A *****");
	x = 10;
	y = 5;
	printf(" Base = %d\n", x);
	printf(" Height = %d\n", y);
	printf(" Area = %d\n", x * y);
	// Section B - Print the static array "nums".
	puts("***** Section B *****");
	int i = 0;
	while (i < 6) {
		printf(" nums[%d] = %d\n", i, i);
		i++;
	}

	// Section C - Print allocated array.
	puts("***** Section C *****");
	arrPtr = malloc(sizeof(int) * 10);
	if (arrPtr) {
		for (i = 0; i < 6; i++) {
			arrPtr[i] = i;
			printf(" array[%d] = %d\n", i, arrPtr[i]);
		}
	}
	else {
		printf("Error Allocating Memory!\n");
		exit(1);
	}

	return 0;
}