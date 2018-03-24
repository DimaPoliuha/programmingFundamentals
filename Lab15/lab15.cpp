#include "stdafx.h" 
#include <iostream> 
#include <locale.h> 
#define M_PI 3.1415 

double *makearr(int size);//создание динамического массива
int tabl();//меню выбора
void fill_array(double *array, int size);//заполение массива
void print_array(double *array, int size);//печать массива
void bubble_sort(double *array, int size);//сортировка методом пузырька
void selection_sort(double *array, int size);//сортировка методом выбора
void insertion_sort(double *array, int size);//сортировка методом вставок

int main()
{
	setlocale(LC_ALL, "RUS");
	tabl();
	return 0;
}

int tabl() {
	int choice = 0;
	int size = ((M_PI - (-M_PI)) / (M_PI / 10));
	double* array = makearr(size);
	printf(" ¬ыберите действие:\n 1. ‘ормирование массива\n 2. ѕечать массива\n 3. —ортировка методом пузырька\n 4. —ортировка методом выбора\n 5. —ортировка методом вставок\n 6. ¬ыход\n");
tabl:
	scanf("%i", &choice);
	switch (choice) {
	case 1:
		fill_array(array, size);
		printf(" √отово! ћожно продолжать...\n");
		goto tabl;
		break;
	case 2:
		print_array(array, size);
		goto tabl;
		break;
	case 3:
		bubble_sort(array, size);
		goto tabl;
		break;
	case 4:
		selection_sort(array, size);
		goto tabl;
		break;
	case 5:
		insertion_sort(array, size);
		goto tabl;
		break;
	case 6:
		return 0;
	default:
		printf("¬ы ввели неверное значение\n\n");
		goto tabl;
	}
	return 0;
}

double *makearr(int size) //создание динамического массива
{
	double* arr = new double[size];
	return arr;
}

void fill_array(double *array, int size)//заполение массива
{
	int i = 0;
	double x = (-M_PI), y = 0, final_x = M_PI, step = (M_PI / 10);
	for (; x <= final_x; x += step) {
		y = cos(pow(x, 2) + 2);
		array[i] = y;
		i++;
	}
}

void print_array(double *array, int size)//печать массива
{
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("|%.2lf", array[i]);
	}
	printf("|");
	printf("\n\n");
}

void bubble_sort(double *array, int size)//сортировка методом пузырька
{
	double temp = 0;
	for (int k = 0; k < size; k++) {
		for (int i = 0; i < size - k - 1; i++) {
			if (array[i] > array[i + 1]) {
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

void selection_sort(double *array, int size)//сортировка методом выбора
{
	double temp = 0;
	int min = size - 1;
	for (int k = 0; k < size; k++) {
		for (int i = k; i < size; i++) {
			if (array[i] < array[min]) {
				min = i;
			}
		}
		temp = array[min];
		array[min] = array[k];
		array[k] = temp;
		min = size - 1;
	}
}

void insertion_sort(double *array, int size)//сортировка методом вставок
{
	int i, j;
	double temp;
	for (int i = 0; i < size; i++)
	{
		temp = array[i];
		j = i - 1;
		while ((j >= 0) && (array[j] > temp))
		{
			array[j + 1] = array[j];
			j -= 1;
		}
		array[j + 1] = temp;
	}
}