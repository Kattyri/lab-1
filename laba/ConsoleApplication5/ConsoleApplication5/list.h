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
 while (p -> next != NULL)
 p = p -> next;
 p -> next = q;
 return head;
}
// Включение элемента в упорядоченный список
List* Insert_Sort(int n, List* head)
{
 List* q = new List(n), * p = head;
 if (head == NULL) return q;
 if (n < head -> value) // Включение элемента в начало списка
 {
 q -> next = head;
 return q;
 }
 while (p -> next != NULL)
 if (n < p -> next -> value) // Включение элемента в середину списка
 {
 q -> next = p -> next;
 p -> next = q;
 break;
 }
 else
 p = p -> next;
 p -> next = q; // Включение элемента в конец списка
 return head;
}
// Включение элемента в список по номеру
List* Insert_Number(int Num, int n, List* head)
{
 List* p = head, * q = new List(n);
 int i = 1;
 if (head == NULL) return q;
 if (Num == 1) // Включение элемента в начало списка
 {
 q -> next = head;
 return q;
 }
 while (p -> next != NULL)
 if (Num == i + 1) // Включение элемента в середину списка
 {
 q -> next = p -> next;
 p -> next = q;
 return head;
 }
 else
 {
 i++;
 p = p -> next;
 }
 if (Num == i + 1) // Включение элемента в конец списка
 p -> next = q;
 else
 puts("Такого номера в списке нет!");
 return head;
}
// Создание списка (добавляя элементы в начало)
List* Creat_list()
{
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
 n = p -> value;
 head = head -> next;
 delete p;
 }
 return head;
}
// Удаление элемента из конца списка
List* Delete_last(int& n, List* head)
{
 List* p = head;
 if (p == NULL) { puts("Список пуст!"); return NULL; }
 if (head -> next == NULL) // один элемент в списке
 {
 n = head -> value;
 delete head;
 return NULL;
 }
 while (p -> next -> next != NULL)
 p = p -> next;
 n = p -> next -> value;
 delete p -> next;
 p -> next = NULL;
 return head;
}
// Удаление элемента из списка по значению
List* Delete_value(int n, List* head)
{
 List* p = head, * t;
 if (head == NULL) { puts("Список пуст!"); return NULL; }
 if (head -> value == n) // Удаление элемента из начала списка
 {
 t = head;
 head = head -> next;
 delete t;
 return head;
 }
 while (p -> next != NULL) // Удаление элемента из середины списка
 if (p -> next -> value == n)
 {
 t = p -> next;
 p -> next = p -> next -> next;
 delete t;
 return head;
 }
 else p = p -> next;
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
 head = head -> next;
 delete t;
 return head;
 }
 while (p -> next != NULL)
 if (Num == i + 1) // Удаление элемента из середины списка
 {
 t = p -> next;
 p -> next = p -> next -> next;
 delete t;
 return head;
 }
 else
 {
 i++;
 p = p -> next;
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
 printf("%d ", p -> value);
 p = p -> next;
 }
}