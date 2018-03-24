// Лаба3.cpp: определяет точку входа для консольного приложения.
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
	double a, x, b;

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
	/*Вычисление данных и вывод результата*/
	if (x == 5) {
		if (b == 0) {
			printf("\n%s\n", "Недопустимое значение b");
		}
		else {
			printf("\ny = %.1lf\n", a * x / b);
		}
	}
	if (x < 5) {
		if (a * x * b < 0) {
			printf("\n%s\n", "Недопустимое значение b");
		}
		else {
			printf("\ny = %lf\n", log(a * x * b));
		}
	}
	if (x > 5) {
		printf("\ny = %lf\n", tan(a * x * b));
	}


system("pause");

return 0;
}



