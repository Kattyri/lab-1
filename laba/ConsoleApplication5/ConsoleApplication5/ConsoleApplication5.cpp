﻿#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <iostream>
#include "list.h"
void Menu()
{
    int i, k, n, num;
    char c;
    const char* ss[] = { " 0 - Печать списка", " 1 - Включение с сортировкой", " 2 -Включение в начало", \
 " 3 - Добавление в конец", " 4 - Включение по номеру", " 5 - Удаление из начала",
" 6 - Удаление из конца",\
 " 7 -Удаление по значению", " 8 - Удаление по номеру", " 9 - ВЫХОД" };
    k = sizeof(ss) / sizeof(ss[0]);
    List* head = NULL;
    for (;;)
    {
        puts("\n--------------------РАБОТА С ОДНОСВЯЗНЫМ СПИСКОМ ----------------");
        for (i = 0; i < k; i++) puts(ss[i]); // Вывод меню
        c = _getch(); // выбор действия со списком
        switch (c)
        {
        case '0': Print_list(head); break;
        case '1': printf("число: "); scanf("%d", &num); head = Insert_Sort(num,
            head); break;
        case '2': printf("число: "); scanf("%d", &num); head = Insert_first(num,
            head); break;
        case '3': printf("число: "); scanf("%d", &num); head = Add_last(num, head);
            break;
        case '4': printf("номер: "); scanf("%d", &num); printf("число: ");
            scanf("%d", &n);
            head = Insert_Number(num, n, head); break;
        case '5': head = Delete_first(num, head); break;
        case '6': head = Delete_last(num, head); break;
        case '7': printf("число: "); scanf("%d", &num); head = Delete_value(num,
            head); break;
        case '8': printf("номер: "); scanf("%d", &num); head = Delete_Number(num,
            head); break;
        case '9': return;
        }
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color F0");
    Menu();
}