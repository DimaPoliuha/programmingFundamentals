#include "stdafx.h"
#include <iostream>
#include <locale.h>

int **makearr(int row, int kol);//создание динамического массива
int tabl(int **array, int row, int col);//меню выбора
void FillArr(int **array, int row, int col);//заполение массива
void PrintArr(int **array, int row, int col);//печать массива
void add(int **array, int row, int col);

int main()
{
	setlocale(LC_ALL, "RUS");
	int row = 0, col = 0;
	printf("Введите колличество рядов двумерного массива: ");
	scanf("%i", &row);
	printf("Введите колличество столбиков двумерного массива: ");
	scanf("%i", &col);
	int** array = makearr(row, col);//создание динамического массива
	tabl(array, row, col);
	return 0;
}

int **makearr(int row, int col) //создание динамического массива
{
	int **arr = new int *[row + 4];
	for (int i = 0; i < row; i++)
		arr[i] = new int[col];
	return arr;
}

int tabl(int **array, int row, int col) {
	int choice = 0, temp = 0;
	printf(" Выберите действие:\n 1. Формирование массива\n 2. Печать массива\n 3. Добавить К элементов, начиная с элемента N\n 4. Выход\n");
tabl:
	scanf("%i", &choice);
	switch (choice) {
	case 1:
		FillArr(array, row, col);//заполение массива
		goto tabl;
		break;
	case 2:
		PrintArr(array, row, col);//печать массива
		goto tabl;
		break;
	case 3:
		add(array, row, col);
		goto tabl;
		break;
	case 4:
		return 0;
	default:
		printf("Вы ввели неверное значение\n\n");
		goto tabl;
	}
	return 0;
}

void FillArr(int **array, int row, int col) //заполение массива
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			array[i][j] = 1 + rand() % 100;
		}
	}
}

void PrintArr(int **array, int row, int col) //печать массива
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
	printf("Введите индекс ряда элемента N: ");
	scanf("%i", &nrow);
	if (nrow > row) {
		printf("Вы ввели неверное значение\n");
		goto r;
	}
c:
	printf("Введите индекс столбца элемента N: ");
	scanf("%i", &ncol);
	if (ncol > col) {
		printf("Вы ввели неверное значение\n");
		goto c;
	}
	printf("Введите колличество элементов K: ");
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