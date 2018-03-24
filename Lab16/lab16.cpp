#include "stdafx.h" 
#include <iostream> 
#include <locale.h>
#include <functional>
#define M_PI 3.1415
using namespace std;

double *makearr(int size);//создание динамического массива
int tabl();//меню выбора
void fill_array(double *array, int size);//заполение массива
void print_array(double *array, int size);//печать массива
void shell_sort(double *array, int size);// сортировка Ўелла
void hoare_sort(double *array, int first, int last);// сортировка ’оора
void quick_sort(double *array, int first, int last);// QuickSort

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
	printf(" ¬ыберите действие:\n 1. ‘ормирование массива\n 2. ѕечать массива\n 3. —ортировка методом Ўелла\n 4. —ортировка методом ’оора\n 5. QuickSort\n 6. ¬ыход\n");
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
		shell_sort(array, size);
		goto tabl;
		break;
	case 4:
		hoare_sort(array, 0, (size - 1));
		goto tabl;
		break;
	case 5:
		quick_sort(array, 0, (size - 1));
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

void sort_shell(double *array, int size)//сортировка Ўелла
{
	int i, j, step;
	double temp;
	for (step = size / 2; step > 0; step /= 2)
	{
		for (i = step; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= step; j -= step)
			{
				if (temp < array[j - step])
					array[j] = array[j - step];
				else
					break;
			}
			array[j] = temp;
		}
	}
}

void hoare_sort(double *array, int first, int last)
{
	int i = first, j = last, step = -1;
	bool condition = 1;
	double temp1;
	int temp2;
	if (first >= last)
		return;                   // сортировать нечего

	do {                         // сортируем с левой границы до правой
		if (condition == isless(array[j], array[i]))
		{
			temp1 = array[i];
			array[i] = array[j];
			array[j] = temp1;
			temp2 = i;
			i = j;
			j = temp2;
			step = -step;                 // теперь - в другую сторону
			condition = !condition;       // обмен услови€ на противоположное
		}
		j += step;                        // передвинем индекс
	} while (j != i);                     // пока индексы не сойдутс€
	hoare_sort(array, first, i - 1);               // левое подмножество
	hoare_sort(array, i + 1, last);               // правое подмножество
}

void shell_sort(double *array, int size)
{
	double temp;
	for (int gap = size / 2; gap > 0; gap /= 2) // выбор интервала
	{
		for (int i = gap; i < size; i++) // проход массива
		{
			// сравнение пар, отсто€щих на gap друг от друга
			for (int j = i - gap; j >= 0 && isless(array[j + gap], array[j]); j -= gap)
			{
				temp = array[j];
				array[j] = array[j + gap];
				array[j + gap] = temp;
			}

		}
	}
}

void quick_sort(double *array, int first, int last)
{
	int i = first, j = last;
	double x = array[(first + last) / 2];
	double temp;
	do {
		while (isless(array[i], x)) i++;
		while (isless(x, array[j])) j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		};
	} while (i<j);
	if (first < j) quick_sort(array, first, j);
	if (i < last) quick_sort(array, i, last);
}