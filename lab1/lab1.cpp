// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <ctime>
#include <iomanip>
using namespace std;
//создание нового типа данных
struct node
{
	int value;
	node* next;
};

node* head = NULL;
node* tail = NULL;

void show_list()//вывод списка
{
	node* curr = head;
	while (curr)
	{
		cout<<setw(3)/*колличество пробелов между элементами*/ << curr->value << ' ';
		curr = curr->next;
	}
	cout << endl << endl;
}

void check_duplicates(void) {
	node* pel = head;
	int flag = 0;//флаг лож/истина
	while (pel->next != NULL) {
		node* runner = pel->next;
		while (runner != NULL) {
			if (runner->value == pel->value) {
				printf("duplicates: %d\n", runner->value);
				flag = 1;
			}
			runner = runner->next;
		}
		pel = pel->next;
	}
	if (flag == 0) { printf("no duplicates\n"); }//проверка, были ли дубликаты
}

int moveNegativeNumbersToFront(node** head) {
	int count = 0;
	node* current = *head;
	node* prev = NULL;
	while (current != NULL) {
		if (current->value < 0) {
			if (prev != NULL) {
				prev->next = current->next;
			}
			else {
				*head = current->next;
			}
			current->next = *head;
			*head = current;
			count++;
			current = prev != NULL ? prev->next : *head;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
	return count;
}

int main()
{
	srand(time(0));//функция для установки начала последовательности
	//генерация рандомного списка
	for (int i = 0; i < 10; ++i)
	{
		node* add = new node;
		add->next = NULL;
		add->value = -31 + rand() % 61 + 1;

		if (head == NULL) tail = head = add;
		else
		{
			tail->next = add;
			tail = add;
		}
	}

	show_list();//вывод получившегося списка
	check_duplicates();//поиск одинаковых чисел
	int count = moveNegativeNumbersToFront(&head);
	show_list();


	system("pause");
	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
