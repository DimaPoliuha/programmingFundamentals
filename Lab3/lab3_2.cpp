// Лаба3(2).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "Windows.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	/* Объявление переменных */
	double a, b, x;

	/*Что делает программа?*/
	printf("%s\n%s\n%s\t%s\n",
		"Если х == 5, y = a * x / b",
		"Если x < 5, y = log(a * x * b)",
		"Если x > 5, y = tan(a * x * b)");

	/*Ввод данных*/
	printf("\n%s ", "Введите значение х =");
	scanf("%lf", &x);
	printf("%s ", "Введите значение а =");
	scanf("%lf", &a);
	printf("%s ", "Введите значение b =");
	scanf("%lf", &b);
	/*Ввод(по необходимости), вычисление данных и вывод результата*/
	if (x == 5 && b != 0)
	{
		printf("\ny = %lf\n", a * x / b);
	}

	else
	{
		if (x < 5 && a * x * b > 0) {
			printf("\ny = %lf\n", log(a * x * b));
		}
		else {
			if (x > 5) {
				printf("\ny = %lf\n", tan(a * x * b));
			}
			else {
				printf("Недопустиме значення ОДЗ\n");
			}
		}
	}

	system("pause");

	return 0;
}
