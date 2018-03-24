#include "stdafx.h"
#include <iostream>
#include <locale.h>
#define a 2
#define b 3

void fill_array(int arr[a][b]);
void print_array(int arr[a][b]);
void sum(int arr[a][b]);

int main()
{
	setlocale(LC_ALL, "RUS");
	int array[a][b];

	fill_array(array);
	print_array(array);
	sum(array);

	system("pause");
	return 0;
}

void fill_array(int arr[a][b]) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			arr[i][j] = 10 + rand() % 40;

		}
	}
}

void print_array(int arr[a][b]) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf(" %3i ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void sum(int arr[a][b]) {
	int sum = 0;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (i % 2 == 0)
				sum += arr[i][j];
		}
		if (i % 2 == 0)
			printf("В строке %i сумма элементов: %i\n", i, sum);
		sum = 0;
	}
	for (int j = 0; j < b; j++) {
		for (int i = 0; i < a; i++) {
			if (j % 2 == 1)
				sum += arr[i][j];
		}
		if (j % 2 == 1)
			printf("В столбце %i сумма элементов: %i\n", j, sum);
		sum = 0;
	}
}