// ����3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "Windows.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	/* ���������� ���������� */
	double a, x, b;

	/*��� ������ ���������?*/
	printf("%s\n%s\n%s\t%s\n",
		"���� � == 5, y = a * x / b",
		"���� x < 5, y = log(a * x * b)",
		"���� x > 5, y = tan(a * x * b)");

	/*���� ������*/
	printf("\n%s ", "������� �������� � =");
	scanf("%lf", &x);

	printf("%s ", "������� �������� � =");
	scanf("%lf", &a);

	printf("%s ", "������� �������� b =");
	scanf("%lf", &b);
	/*���������� ������ � ����� ����������*/
	if (x == 5) {
		if (b == 0) {
			printf("\n%s\n", "������������ �������� b");
		}
		else {
			printf("\ny = %.1lf\n", a * x / b);
		}
	}
	if (x < 5) {
		if (a * x * b < 0) {
			printf("\n%s\n", "������������ �������� b");
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



