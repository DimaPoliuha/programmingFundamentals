/**************************************************/
/*            Лабораторная работа = 2             */
/*       Арифметические выражения и функции       */
/*                 Вариант = 16                   */
/**************************************************/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Windows.h"
int main(void) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/* параметры, которые вводятся */
	double x, y;
	/* параметры, которые задаются в программе */
	double a = 12.5, b = 1.3;
	double c = 14.1, d = 2.7;
	double t1, t2;   /* результаты */
	double ax;       /* рабочая переменная */

	printf("Введите x, y >");
	scanf("%lf %lf", &x, &y);

	t1 = (1 / (pow(a, 2)*pow(c, 2) + pow(b, 2)))*abs(c*log(b + c*x) - (c / 2)*log(y));

	t2 = (1 / a)*log((1 + cos(a*x)) / a*x);

	printf("t1 = %lg\n", t1);
	printf("t2 = %lg\n", t2);
	system("pause");
	return 0;
}