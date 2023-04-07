#define _CRT_SECURE_NO_WARNINGS 
#include <conio.h>
#include <stdio.h>
#include <Windows.h> 
#include <math.h> 
#include <iostream>
#pragma once
//Функции для работы с односвязным списком
#define N 6
struct List // Создание нового типа данных
{
    int value; // информационная часть
    List* next; // служебная часть
    List(int val = 0, List* p = NULL) // конструктор
    {
        value = val;
        next = p;
    }
};

// Включение элемента в начало списка
List* Insert_first(int n, List* head)
{
    List* q = new List(n, head);
    return q;
}

// Включение элемента в конец списка
List* Add_last(int n, List* head)
{
    List* q = new List(n), * p = head;
    if (head == NULL) return q;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
    return head;
}

// Включение элемента в упорядоченный список
List* Insert_Sort(int n, List* head)
{
    List* q = new List(n), * p = head;

    if (head == NULL) return q;

    if (n < head->value) // Включение элемента в начало списка
    {
        q->next = head;
        return q;
    }

    while (p->next != NULL)
        if (n < p->next->value) // Включение элемента в середину списка
        {
            q->next = p->next;
            p->next = q;
            break;
        }
        else
            p = p->next;
    p->next = q; // Включение элемента в конец списка
    return head;
}

// Включение элемента  в список по номеру
List* Insert_Number(int Num, int n, List* head)
{
    List* p = head, * q = new List(n);
    int i = 1;
    if (head == NULL) return q;
    if (Num == 1) // Включение элемента в начало списка
    {
        q->next = head;
        return q;
    }
    while (p->next != NULL)
        if (Num == i + 1) // Включение элемента в середину списка
        {
            q->next = p->next;
            p->next = q;
            return head;
        }
        else
        {
            i++;
            p = p->next;
        }
    if (Num == i + 1) // Включение элемента в конец списка
        p->next = q;
    else
        puts("Такого номера в списке нет!");
    return head;
}

// Создание списка (добавляя элементы в начало)
typedef struct Mylist
{
    List* root, * carr;
} Mylist;

Mylist* InitMylist(void)
{
    Mylist* u = (Mylist*)malloc(sizeof(Mylist));
    u->root = (List*)malloc(sizeof(List));
    u->carr = u->root;
    if (u->root == NULL)return NULL;
    u->root->next = NULL;
    return u;
}


void Delete_Mylist(Mylist* u)
{
    List* uk;
    while (u->root != NULL)
    {
        uk = u->root;
        u->root = u->root->next;
        free(uk);
    }
    free(u);
}
List* Creat_list()
{
    Mylist* sp = InitMylist();
    int d;
    char x;

    for (int i = 1; i <= N; ++i)
    {
        printf("Vvedite chisla v spisok: ");
        scanf("%d", &d);
        Add_last(sp, d);
        printf("Prodolzhit? y/n: ");
        while (getchar() != '\n');
        scanf("%c", &x);
        if (x == 'n')break;
    }
    Print_list(sp);

    Delete_Mylist(sp);

    sp = NULL;

    return 0;
    char str[N];
    List* head = NULL;
    puts("Создание списка. Вводите числа:");
    for (;;)
    {
        gets_s(str);
        if (!str[0]) break;
        head = Insert_first(atoi(str), head); // вызов функции "Включение элемента в начало списка"
    }
    return head;
}

// Удаление элемента из начала списка
List* Delete_first(int& n, List* head)
{
    List* p = head;
    if (p == NULL)puts("Список пуст!");
    else
    {
        n = p->value;
        head = head->next;
        delete p;
    }
    return head;
}

// Удаление элемента из конца списка
List* Delete_last(int& n, List* head)
{
    List* p = head;
    if (p == NULL) { puts("Список пуст!"); return NULL; }
    if (head->next == NULL) // один элемент в списке
    {
        n = head->value;
        delete head;
        return NULL;
    }
    while (p->next->next != NULL)
        p = p->next;
    n = p->next->value;
    delete p->next;
    p->next = NULL;
    return head;
}

// Удаление элемента из списка по значению
List* Delete_value(int n, List* head)
{
    List* p = head, * t;
    if (head == NULL) { puts("Список пуст!"); return NULL; }
    if (head->value == n) // Удаление элемента из начала списка
    {
        t = head;
        head = head->next;
        delete t;
        return head;
    }
    while (p->next != NULL) // Удаление элемента из середины списка
        if (p->next->value == n)
        {
            t = p->next;
            p->next = p->next->next;
            delete t;
            return head;
        }
        else p = p->next;
    puts("Такого значения в списке нет!");
    return head;
}

// Удаление элемента из списка по номеру
List* Delete_Number(int Num, List* head)
{
    List* p = head, * t;
    int i = 1;
    if (head == NULL) { puts("Список пуст!"); return NULL; }
    if (Num == 1) // Удаление элемента из начала списка
    {
        t = head;
        head = head->next;
        delete t;
        return head;
    }
    while (p->next != NULL)
        if (Num == i + 1) // Удаление элемента из середины списка
        {
            t = p->next;
            p->next = p->next->next;
            delete t;
            return head;
        }
        else
        {
            i++;
            p = p->next;
        }
    puts("Такого номера в списке нет!"); // Такого номера в списке нет
    return head;
}

// Печать содержимого списка
void Print_list(List* head)
{
    List* p = head;
    puts("\n PRINT LIST");
    if (p == NULL) puts("Список пуст!");
    else
        while (p != NULL)
        {
            printf("%d ", p->value);
            p = p->next;
        }
}


void Menu()
{
    int i, k, n, num;
    char c;
    const char* ss[] = { " 0 - Печать списка", " 1 - Включение с сортировкой", " 2 - Включение в начало", \
    " 3 - Добавление в конец", " 4 - Включение по номеру", " 5 - Удаление из начала", " 6 - Удаление из конца",\
    " 7  -Удаление по значению", " 8 - Удаление по номеру","9-vyvod", " 10 - ВЫХОД" };
    k = sizeof(ss) / sizeof(ss[0]);

    List* head = NULL;
    for (;;)
    {
        puts("\n--------------------РАБОТА С ОДНОСВЯЗНЫМ СПИСКОМ ----------------");
        for (i = 0; i < k; i++) puts(ss[i]); // Вывод меню
        c = _getch(); // выбор действия со списком
        switch (c)
        {
        case '0': Print_list(head);    break;
        case '1': printf("число: "); scanf("%d", &num); head = Insert_Sort(num, head);    break;
        case '2': printf("число: "); scanf("%d", &num); head = Insert_first(num, head);    break;
        case '3': printf("число: "); scanf("%d", &num); head = Add_last(num, head);        break;
        case '4': printf("номер: "); scanf("%d", &num); printf("число: "); scanf("%d", &n);
            head = Insert_Number(num, n, head); break;
        case '5': head = Delete_first(num, head); break;
        case '6': head = Delete_last(num, head);  break;
        case '7': printf("число: "); scanf("%d", &num); head = Delete_value(num, head); break;
        case '8': printf("номер: "); scanf("%d", &num); head = Delete_Number(num, head); break;
        case '9': printf("номер: "); scanf("%d", &num); head = Creat_list(); break;
        case '10': return;
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
