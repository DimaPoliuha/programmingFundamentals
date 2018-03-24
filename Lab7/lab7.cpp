#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include "locale.h"

void y(double x, int &a);

void main()
{
	setlocale(LC_ALL, "RUS");
	double x = 0;
	double final_x = 0;
	double temp = 0;
	double step = 0;
	int a;

	printf("Enter double x:");
	scanf("%lf", &x);
	printf("Enter double final x:");
	scanf("%lf", &final_x);
	printf("Enter double step:");
	scanf("%lf", &step);
	printf("Enter int parametr a:");
	scanf("%d", &a);

	printf("|--------------------------|\n");
	printf("|      x     ||      y     |\n");
	printf("|--------------------------|\n");

	if (x > final_x) {
		temp = final_x;
		final_x = x;
		x = temp;
	}
	for (; x < final_x; x += step)
	{
		y(x, a);
	}
	printf("|--------------------------|\n");
	system("pause");
}

void y(double x, int &a)
{
	double sum = 0;
	double y = 0;
	int final_n = 20;
	int n = 1;

	for (n = 1; n <= final_n; n++) {
		sum += x / exp(n + 1);
	}

	if (a*x >= 0)
	{
		y = sqrt(a*x) + sum;

		printf("| %-10.3lf || %-10.3lf |\n", x, y);
	}
	else
	{
		printf("| %-10.3lf ||    Error   |\n", x);
	}
	sum = 0;
}
