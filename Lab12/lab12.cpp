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

		cout << "������� ���: " << endl;
		fflush(stdin);
		fgets(files[number].name, 20, stdin);//������� ��� ���������� ����� (stdin - ����������� ����� ����� - �������)
		files[number].name[strlen(files[number].name) - 1] = '\0';//���������  \0 �� enter

		cout << "������� ������ (� ��): " << endl;
		fflush(stdin);
		scanf("i", &files[number].size);

		cout << "������� ���� �������� � ������� ����/�����/��� (����� Enter): " << endl;
		fflush(stdin);
		scanf("i", &files[number].day);
		scanf("i", &files[number].mounth);
		scanf("i", &files[number].year);

		cout << "������� ��� �����: " << endl;
		fflush(stdin);
		fgets(files[number].type, 20, stdin);//������� ��� ���������� ����� (stdin - ����������� ����� ����� - �������)
		files[number].type[strlen(files[number].type) - 1] = '\0';//���������  \0 �� enter

		number++;
		cout << "���������� ������?(1/0)" << endl;
		cin >> i;
	} while (i);

	for (i = 0; i < number; i++) {
		cout << "����: '" << files[i].name << "'" << endl;
		cout << "������ ����� " << files[i].size << "��" << endl;
		printf("���� �������� ����� %i:%i:%i \n", files[i].day, files[i].mounth, files[i].year);
		cout << "��� �����: " << files[i].type << endl;
	}

	system("pause");
	return 0;
}
