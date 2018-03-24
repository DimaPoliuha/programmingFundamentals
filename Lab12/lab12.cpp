#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>

using namespace std;

struct file
{
	char name[20];
	int size;
	int day;
	int mounth;
	int year;
	char type[20];
};
struct file files[30];

int number = 0;
int i = 0;

int main() {
	setlocale(LC_ALL, "rus");

	do {
		cout << "File #" << number + 1 << endl;

		cout << "Введите имя: " << endl;
		fflush(stdin);
		fgets(files[number].name, 20, stdin);//функция для считывания строк (stdin - стандартный поток ввода - консоль)
		files[number].name[strlen(files[number].name) - 1] = '\0';//вставляем  \0 до enter

		cout << "Введите размер (в кб): " << endl;
		fflush(stdin);
		scanf("i", &files[number].size);

		cout << "Введите дату создания в формате день/месяц/год (через Enter): " << endl;
		fflush(stdin);
		scanf("i", &files[number].day);
		scanf("i", &files[number].mounth);
		scanf("i", &files[number].year);

		cout << "Введите тип файла: " << endl;
		fflush(stdin);
		fgets(files[number].type, 20, stdin);//функция для считывания строк (stdin - стандартный поток ввода - консоль)
		files[number].type[strlen(files[number].type) - 1] = '\0';//вставляем  \0 до enter

		number++;
		cout << "Прекратить работу?(1/0)" << endl;
		cin >> i;
	} while (i);

	for (i = 0; i < number; i++) {
		cout << "Файл: '" << files[i].name << "'" << endl;
		cout << "Размер файла " << files[i].size << "кб" << endl;
		printf("Дата создания файла %i:%i:%i \n", files[i].day, files[i].mounth, files[i].year);
		cout << "Тип файла: " << files[i].type << endl;
	}

	system("pause");
	return 0;
}
