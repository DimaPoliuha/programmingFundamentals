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
		cout << "\t ����"
			<< "\n1. ���� ������� ��������"
			<< "\n2. ����� � ������� �������� �� ��������� ���������"
			<< "\n3. ��������� ��������? ���������"
			<< "\n4. �������� ��������� �� �������"
			<< "\n5. ����� �� ����� ������� ��������"
			<< "\n6. �����\n\n";

		cout << "��� ����� ������?\n";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			file_amount = enter();
			printf("\n ����� ������: %i\n\n", file_amount);
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
			printf("\n �������� ������: %i\n\n", file_amount - 1);
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
			cout << "��������� �������!" << endl;
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

		cout << "������� ���: " << endl;
		cin >> files[number].name;

		cout << "������� ������ (� ��): " << endl;
		cin >> files[number].size;

		cout << "������� ���� �������� � ������� ����/�����/��� (����� Enter): " << endl;
		cin >> files[number].day;
		cin >> files[number].mounth;
		cin >> files[number].year;

		cout << "������� ��� �����: " << endl;
		cin >> files[number].type;

		number++;
		cout << "���������� ������?(1-���/0-��)" << endl;
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
	cout << "�������� �������� ������:"
		<< "\n1.���"
		<< "\n2.������"
		<< "\n3.���� ��������"
		<< "\n4.���"
		<< endl;

	cin >> par;
	if (par == 1)
	{
		cout << "������� ��� �����: ";
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
			cout << "��� ��� ������ �����" << endl;
		}
	}
	else if (par == 2)
	{
		cout << "������� ������: ";
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
			cout << "��� ��� ������ �����" << endl;
		}
	}
	else if (par == 3)
	{
		cout << "������� ���� �������� � ������� ����/�����/��� (����� Enter): ";
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
			cout << "��� ��� ������ �����" << endl;
		}
	}
	else if (par == 4)
	{
		cout << "������� ��� �����: ";
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
			cout << "��� ��� ������ �����" << endl;
		}
	}
	else
		cout << "��� ��� ������ ���������" << endl;
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

	cout << "�������� ����� ���� ��������:";
	cin >> choice;
	if (choice <= file_amount + 1)
	{
		cout << "�������� ����� �������� ��������:"
			<< "\n1.���"
			<< "\n2.������"
			<< "\n3.���� ��������"
			<< "\n4.���"
			<< endl;

		cin >> par;
		if (par == 1)
		{
			cout << "������� ����� ���: ";
			cin >> new_name;
			files[choice - 1].name = new_name;
			print_one_file(choice - 1);
		}
		else if (par == 2)
		{
			cout << "������� ����� ������: ";
			cin >> new_size;
			files[choice - 1].size = new_size;
			print_one_file(choice - 1);
		}
		else if (par == 3)
		{
			cout << "������� ����� ���� �������� � ������� ����/�����/��� (����� Enter): ";
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
			cout << "������� ����� ���: ";
			cin >> new_name;
			files[choice - 1].type = new_name;
			print_one_file(choice - 1);
		}
		else
			cout << "��� ��� ������ ���������" << endl;
		cout << "\n";
	}
	else
		cout << "������ ����� ���" << endl;
	cout << "\n";
}

void delet(int file_amount)
{
	int par_number;
	cout << "�������� ����� �����, ������� ����� �������: \n";
	cin >> par_number;

	if (par_number >= 0 && par_number <= file_amount)
	{
		for (int i = (par_number - 1); i < file_amount - 1; i++)
		{
			files[i] = files[i + 1];
		}
	}
	else
		cout << "������ ����� ���" << endl;
}

void print_struct(int file_amound)
{
	for (int i = 0; i < file_amound; i++) {
		cout << "����: '" << files[i].name << "'" << endl;
		cout << "������ ����� " << files[i].size << "��" << endl;
		printf("���� �������� ����� %i:%i:%i \n", files[i].day, files[i].mounth, files[i].year);
		cout << "��� �����: " << files[i].type << endl;
	}
}

void print_one_file(int i)
{
	cout << "����: '" << files[i].name << "'" << endl;
	cout << "������ ����� " << files[i].size << "��" << endl;
	printf("���� �������� ����� %i:%i:%i \n", files[i].day, files[i].mounth, files[i].year);
	cout << "��� �����: " << files[i].type << endl;
}