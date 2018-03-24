#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <Windows.h>

void p_mass(int *mass1, int n); //создаем новый массив
int zero(int *mass2, int n); //проверка на существование 0
int dob(int *mass3, int n); //произведение элементов
void sort_mass(int *mass4, int n);//функція впорядкування елементів, якщо відсутні 0

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;

	printf("Введите колличество элементов: ");
	scanf("%d", &n);

	//создаем новый массив
	int* mass = new int[n];

	for (int i = 0; i < n; i++)
	{
		printf("Введите элемент[%d]: ", i);
		scanf("%d", &mass[i]);
	}

	printf("Элементы массива:");

	p_mass(mass, n);


	//сортировка массива
	if (!zero(mass, n)) //Если колличество нулей равно 0, то считаем дальше, если нет - заканчиваем
	{
		printf("Массив после сортировки: ");

		sort_mass(mass, n);

		int dobutok = dob(mass, n);

		printf("\nПроизведение всех элементов = %d\n", dobutok);
	}

	system("pause");
	return 0;
}

void p_mass(int *mass1, int n) //создаем новый массив
{
	for (int i = 0; i < n; i++)
		printf(" %d", mass1[i]);
}

int zero(int *mass2, int n) //проверка на существование 0
{
	int zero_element = 0;

	for (int temp = 0; temp < n; temp++)
	{
		if (mass2[temp] == 0)
			zero_element++;
	}

	printf("\nКолличество нулей: %d\n", zero_element);

	return zero_element;
}

int dob(int* mass3, int n) //произведение всех элементов
{
	int z = 1;

	for (int i = 0; i < n; i++)
	{
		z *= mass3[i];
	}

	return z;
}

void sort_mass(int *mass4, int n) // Сортировка массива пузырьком
{
	int temp = 0;
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (mass4[j] > mass4[j + 1]) {
				// меняем элементы местами
				temp = mass4[j];
				mass4[j] = mass4[j + 1];
				mass4[j + 1] = temp;
			}
		}
	}

	// Вывод отсортированного массива на экран
	for (int i = 0; i < n; i++) {
		printf("%d ", mass4[i]);
	}
}