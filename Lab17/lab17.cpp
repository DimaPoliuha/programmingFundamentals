#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <cctype>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

int enter();
void search(int file_amount);
void print_struct(int file_amount);
void delet(int file_amount);
void change(int file_amount);
void print_one_file(int i);

struct file
{
	string name;
	int size;
	int day;
	int mounth;
	int year;
	string type;
};

struct file files[30];


int main()
{
	setlocale(LC_ALL, "rus");
	int file_amount = 0;
	int choice;
	int temp = 0;
	do
	{
		cout << "\t Меню"
			<< "\n1. Ввод массива структур"
			<< "\n2. Поиск в массиве структур по заданному параметру"
			<< "\n3. Изменение заданнои? структуры"
			<< "\n4. Удаление структуры из массива"
			<< "\n5. Вывод на экран массива структур"
			<< "\n6. Выход\n\n";

		cout << "Что будем делать?\n";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			file_amount = enter();
			printf("\n Всего файлов: %i\n\n", file_amount);
			break;
		}
		case 2:
		{
			search(file_amount);
			break;
		}
		case 3:
		{
			change(file_amount);
			break;
		}
		case 4:
		{
			delet(file_amount);
			printf("\n Осталось файлов: %i\n\n", file_amount - 1);
			temp = file_amount - 1;
			file_amount = temp;
			break;
		}
		case 5:
		{
			print_struct(file_amount);
			break;
		}
		case 6:
		{
			return 0;
			break;
		}
		default:
		{
			cout << "Повторите попытку!" << endl;
		}
		}
	} while (1);
	system("pause");
	return 0;
}

int enter()
{
	int i = 0;
	int number = 0;
	do {
		cout << "File #" << number + 1 << endl;

		cout << "Введите имя: " << endl;
		cin >> files[number].name;

		cout << "Введите размер (в кб): " << endl;
		cin >> files[number].size;

		cout << "Введите дату создания в формате день/месяц/год (через Enter): " << endl;
		cin >> files[number].day;
		cin >> files[number].mounth;
		cin >> files[number].year;

		cout << "Введите тип файла: " << endl;
		cin >> files[number].type;

		number++;
		cout << "Прекратить работу?(1-нет/0-да)" << endl;
		cin >> i;
	} while (i);
	return(number);
}

void search(int file_amount)
{
	int count = 0;
	int par = 0;
	string par_name;
	int par_size;
	int par_day;
	int par_mounth;
	int par_year;
	cout << "Выберите параметр поиска:"
		<< "\n1.Имя"
		<< "\n2.Размер"
		<< "\n3.Дата создания"
		<< "\n4.Тип"
		<< endl;

	cin >> par;
	if (par == 1)
	{
		cout << "Введите имя файла: ";
		cin >> par_name;
		count = 0;
		for (int i = 0; i < file_amount; i++)
		{
			if (par_name == files[i].name)
			{
				cout << "File #" << i + 1 << endl;
				print_one_file(i);
				count++;
			}
		}
		if (count == 0)
		{
			cout << "Тут нет такого файла" << endl;
		}
	}
	else if (par == 2)
	{
		cout << "Введите размер: ";
		cin >> par_size;
		count = 0;
		for (int i = 0; i < file_amount; i++)
		{
			if (par_size == files[i].size)
			{
				cout << "File #" << i + 1 << endl;
				print_one_file(i);
				count++;
			}
		}
		if (count == 0)
		{
			cout << "Тут нет такого файла" << endl;
		}
	}
	else if (par == 3)
	{
		cout << "Введите дату создания в формате день/месяц/год (через Enter): ";
		cin >> par_day;
		cin >> par_mounth;
		cin >> par_year;
		count = 0;
		for (int i = 0; i < file_amount; i++)
		{
			if (par_day == files[i].day && par_mounth == files[i].mounth && par_year == files[i].year)
			{
				cout << "File #" << i + 1 << endl;
				print_one_file(i);
				count++;
			}
		}
		if (count == 0)
		{
			cout << "Тут нет такого файла" << endl;
		}
	}
	else if (par == 4)
	{
		cout << "Введите тип файла: ";
		cin >> par_name;
		count = 0;
		for (int i = 0; i < file_amount; i++)
		{
			if (par_name == files[i].type)
			{
				cout << "File #" << i + 1 << endl;
				print_one_file(i);
				count++;
			}
		}
		if (count == 0)
		{
			cout << "Тут нет такого файла" << endl;
		}
	}
	else
		cout << "Тут нет такого параметра" << endl;
	cout << "\n ";
}

void change(int file_amount)
{
	int par = 0;
	string new_name;
	int new_size;
	int new_day;
	int new_mounth;
	int new_year;
	int choice;

	cout << "Выберите какой файл изменять:";
	cin >> choice;
	if (choice <= file_amount + 1)
	{
		cout << "Выберите какой параметр изменять:"
			<< "\n1.Имя"
			<< "\n2.Размер"
			<< "\n3.Дата создания"
			<< "\n4.Тип"
			<< endl;

		cin >> par;
		if (par == 1)
		{
			cout << "Введите новое имя: ";
			cin >> new_name;
			files[choice - 1].name = new_name;
			print_one_file(choice - 1);
		}
		else if (par == 2)
		{
			cout << "Введите новый размер: ";
			cin >> new_size;
			files[choice - 1].size = new_size;
			print_one_file(choice - 1);
		}
		else if (par == 3)
		{
			cout << "Введите новую дату создания в формате день/месяц/год (через Enter): ";
			cin >> new_day;
			cin >> new_mounth;
			cin >> new_year;
			files[choice - 1].day = new_day;
			files[choice - 1].mounth = new_mounth;
			files[choice - 1].year = new_year;
			print_one_file(choice - 1);
		}
		else if (par == 4)
		{
			cout << "Введите новый тип: ";
			cin >> new_name;
			files[choice - 1].type = new_name;
			print_one_file(choice - 1);
		}
		else
			cout << "Тут нет такого параметра" << endl;
		cout << "\n";
	}
	else
		cout << "Такого файла нет" << endl;
	cout << "\n";
}

void delet(int file_amount)
{
	int par_number;
	cout << "Выберите номер файла, который нужно удалить: \n";
	cin >> par_number;

	if (par_number >= 0 && par_number <= file_amount)
	{
		for (int i = (par_number - 1); i < file_amount - 1; i++)
		{
			files[i] = files[i + 1];
		}
	}
	else
		cout << "Такого файла нет" << endl;
}

void print_struct(int file_amound)
{
	for (int i = 0; i < file_amound; i++) {
		cout << "Файл: '" << files[i].name << "'" << endl;
		cout << "Размер файла " << files[i].size << "кб" << endl;
		printf("Дата создания файла %i:%i:%i \n", files[i].day, files[i].mounth, files[i].year);
		cout << "Тип файла: " << files[i].type << endl;
	}
}

void print_one_file(int i)
{
	cout << "Файл: '" << files[i].name << "'" << endl;
	cout << "Размер файла " << files[i].size << "кб" << endl;
	printf("Дата создания файла %i:%i:%i \n", files[i].day, files[i].mounth, files[i].year);
	cout << "Тип файла: " << files[i].type << endl;
}