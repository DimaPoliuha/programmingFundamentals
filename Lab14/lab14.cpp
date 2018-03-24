#include "stdafx.h"
#include <iostream>
#include <locale.h>

int **makearr(int row, int kol);//�������� ������������� �������
int tabl(int **array, int row, int col);//���� ������
void FillArr(int **array, int row, int col);//��������� �������
void PrintArr(int **array, int row, int col);//������ �������
void add(int **array, int row, int col);

int main()
{
	setlocale(LC_ALL, "RUS");
	int row = 0, col = 0;
	printf("������� ����������� ����� ���������� �������: ");
	scanf("%i", &row);
	printf("������� ����������� ��������� ���������� �������: ");
	scanf("%i", &col);
	int** array = makearr(row, col);//�������� ������������� �������
	tabl(array, row, col);
	return 0;
}

int **makearr(int row, int col) //�������� ������������� �������
{
	int **arr = new int *[row + 4];
	for (int i = 0; i < row; i++)
		arr[i] = new int[col];
	return arr;
}

int tabl(int **array, int row, int col) {
	int choice = 0, temp = 0;
	printf(" �������� ��������:\n 1. ������������ �������\n 2. ������ �������\n 3. �������� � ���������, ������� � �������� N\n 4. �����\n");
tabl:
	scanf("%i", &choice);
	switch (choice) {
	case 1:
		FillArr(array, row, col);//��������� �������
		goto tabl;
		break;
	case 2:
		PrintArr(array, row, col);//������ �������
		goto tabl;
		break;
	case 3:
		add(array, row, col);
		goto tabl;
		break;
	case 4:
		return 0;
	default:
		printf("�� ����� �������� ��������\n\n");
		goto tabl;
	}
	return 0;
}

void FillArr(int **array, int row, int col) //��������� �������
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			array[i][j] = 1 + rand() % 100;
		}
	}
}

void PrintArr(int **array, int row, int col) //������ �������
{
	printf("\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%4i", array[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void add(int **array, int row, int col)
{
	int i = 0, j = 0;
	int elements = row * col;
	int nrow = 0, ncol = 0, k = 0, last_new_el_row = 0, last_new_el_col = 0;
r:
	printf("������� ������ ���� �������� N: ");
	scanf("%i", &nrow);
	if (nrow > row) {
		printf("�� ����� �������� ��������\n");
		goto r;
	}
c:
	printf("������� ������ ������� �������� N: ");
	scanf("%i", &ncol);
	if (ncol > col) {
		printf("�� ����� �������� ��������\n");
		goto c;
	}
	printf("������� ����������� ��������� K: ");
	scanf("%i", &k);

	last_new_el_row = nrow + (k / col);
	last_new_el_col = ncol + (k / row);

	row = ((elements + k) / col) + 1;
	int** array_temp = makearr(row, col);
	for (i = 0; i < nrow; i++) {
		for (j = 0; j < col; j++) {
			array_temp[i][j] = array[i][j];
		}
	}
	i = nrow;
	for (j = 0; j < col; j++) {
		if (j < ncol)
			array_temp[i][j] = array[i][j];
		if (j >= ncol)
			array_temp[i][j] = -100 + rand() % 100;
	}
	for (i = nrow + 1; i < last_new_el_row; i++) {
		for (j = 0; j < col; j++) {
			array_temp[i][j] = -100 + rand() % 100;
		}
	}
	i = last_new_el_row;
	for (j = 0; j < col; j++) {
		if (j < last_new_el_col)
			array_temp[i][j] = -100 + rand() % 100;
		if (j >= last_new_el_col)
			array_temp[i][j] = array[i][j];
	}
	PrintArr(array_temp, row, col);
}