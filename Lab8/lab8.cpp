#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <Windows.h>

void p_mass(int *mass1, int n); //������� ����� ������
int zero(int *mass2, int n); //�������� �� ������������� 0
int dob(int *mass3, int n); //������������ ���������
void sort_mass(int *mass4, int n);//������� ������������� ��������, ���� ������ 0

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;

	printf("������� ����������� ���������: ");
	scanf("%d", &n);

	//������� ����� ������
	int* mass = new int[n];

	for (int i = 0; i < n; i++)
	{
		printf("������� �������[%d]: ", i);
		scanf("%d", &mass[i]);
	}

	printf("�������� �������:");

	p_mass(mass, n);


	//���������� �������
	if (!zero(mass, n)) //���� ����������� ����� ����� 0, �� ������� ������, ���� ��� - �����������
	{
		printf("������ ����� ����������: ");

		sort_mass(mass, n);

		int dobutok = dob(mass, n);

		printf("\n������������ ���� ��������� = %d\n", dobutok);
	}

	system("pause");
	return 0;
}

void p_mass(int *mass1, int n) //������� ����� ������
{
	for (int i = 0; i < n; i++)
		printf(" %d", mass1[i]);
}

int zero(int *mass2, int n) //�������� �� ������������� 0
{
	int zero_element = 0;

	for (int temp = 0; temp < n; temp++)
	{
		if (mass2[temp] == 0)
			zero_element++;
	}

	printf("\n����������� �����: %d\n", zero_element);

	return zero_element;
}

int dob(int* mass3, int n) //������������ ���� ���������
{
	int z = 1;

	for (int i = 0; i < n; i++)
	{
		z *= mass3[i];
	}

	return z;
}

void sort_mass(int *mass4, int n) // ���������� ������� ���������
{
	int temp = 0;
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (mass4[j] > mass4[j + 1]) {
				// ������ �������� �������
				temp = mass4[j];
				mass4[j] = mass4[j + 1];
				mass4[j + 1] = temp;
			}
		}
	}

	// ����� ���������������� ������� �� �����
	for (int i = 0; i < n; i++) {
		printf("%d ", mass4[i]);
	}
}