// ����3(2).cpp: ���������� ����� ����� ��� ����������� ����������.
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
	double a, b, x;

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
	/*����(�� �������������), ���������� ������ � ����� ����������*/
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
				printf("����������� �������� ���\n");
			}
		}
	}

	system("pause");

	return 0;
}
