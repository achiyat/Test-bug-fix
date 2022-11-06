#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <psapi.h>
#include <time.h>
#include <conio.h>
#pragma warning(disable : 4996)

void Add(int id_lottery, char date[11], int number_1, int number_2, int number_3, int number_4, int number_5, int number_6, int strongNum);
void searchitem(int key);

struct LOTO
{
    int id_lottery;
    char date[11];
    int number_1;
    int number_2;
    int number_3;
    int number_4;
    int number_5;
    int number_6;
    int strongNum;
    struct LOTO* next;
    struct LOTO* prev;
};

struct LOTO* head = NULL;
struct LOTO* tail = NULL;
struct LOTO* current;
struct LOTO* find;

char* token;
char userResponse = '0';
int num;

int program4()
{
    int id_lottery;
    char date[11];
    int number_1;
    int number_2;
    int number_3;
    int number_4;
    int number_5;
    int number_6;
    int strongNum;

    FILE* f;
    f = fopen("Lotto.txt", "r");

    if (f == NULL)
    {
        puts("Error - The file did not open!");
        exit(1);
    }
    else
    {
        char str[500];

        fgets(str, 500, f);

        char* token = strtok(str, ",");

        while (fgets(str, 500, f) != NULL)
        {
            // קריאה מהקובץ והשמה של המספרים
            token = strtok(str, ",");
            id_lottery = atoi(token);

            token = strtok(NULL, ",");
            strcpy(date, token);

            token = strtok(NULL, ",");
            number_1 = atoi(token);

            token = strtok(NULL, ",");
            number_2 = atoi(token);

            token = strtok(NULL, ",");
            number_3 = atoi(token);

            token = strtok(NULL, ",");
            number_4 = atoi(token);

            token = strtok(NULL, ",");
            number_5 = atoi(token);

            token = strtok(NULL, ",");
            number_6 = atoi(token);

            token = strtok(NULL, ",");
            strongNum = atoi(token);

            token = strtok(NULL, "\n");

            // השמה לרשימה המקושרת
            Add(id_lottery, date, number_1, number_2, number_3, number_4, number_5, number_6, strongNum);

        }

        fclose(f);
    }

	while (userResponse != 'Q')
	{
		printf("Click 'N' for choose a lottery number \n");
		printf("Click 'Q' for Quit \n\n");

		userResponse = getch();

		switch (userResponse)
		{
		case 'N':
			printf("Please select a lottery number \n");
			scanf("%d", &num);
			searchitem(num);

			if (find == NULL)
			{
				printf("\nNo lottery number exists for this list!\n\n");
			}
			else //find->key == key
			{
				printf("\nid_lottery %d -> date %s\n\n", find->id_lottery, find->date);
			}
			break;

		case 'Q':
			printf("end");
			break;
		}
	}

    return 0;
}

void Add(int id_lottery, char date[11], int number_1, int number_2, int number_3, int number_4, int number_5, int number_6, int strongNum)
{
    current = (struct LOTO*)malloc(sizeof(struct LOTO));

    current->id_lottery = id_lottery;
    strcpy(current->date, date);
    current->number_1 = number_1;
    current->number_2 = number_2;
    current->number_3 = number_3;
    current->number_4 = number_4;
    current->number_5 = number_5;
    current->number_6 = number_6;
    current->strongNum = strongNum;
    current->next = NULL;
    current->prev = NULL;

    if (head == NULL)
    {
        head = current;
        tail = current;
    }
    else
    {
        current->prev = tail;
        tail->next = current;
        tail = current;
    }
}

void searchitem(int key)
{
    find = head;

    while (find != NULL && find->id_lottery != key)
    {
        find = find->next;
    }
    return;
}