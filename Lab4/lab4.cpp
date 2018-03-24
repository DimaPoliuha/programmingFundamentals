#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <Windows.h>


int main(void)
{
	double a, b, xstart, xend, step, x, y;

	printf("Enter a = ");
	scanf("%lf", &a);
	printf("\nEnter b = ");
	scanf("%lf", &b);
	printf("\nEnter xstart = ");
	scanf("%lf", &xstart);
	printf("\nEnter xend = ");
	scanf("%lf", &xend);
	printf("\nEnter step = ");
	scanf("%lf", &step);

	if (step <= 0 || xstart > xend)
		printf("\nError!");
	else
	{
		printf("\n|----------|----------|");
		printf("\n|         table       |");
		printf("\n|---------------------|");
		printf("\n|     x    |     y    |");
		printf("\n|---------------------|");

		x = xstart;

		do
		{
			if (sqrt(a + b * x) != 0)
			{
				y = (3*a + sin(x) * cos(x)) / sqrt(a + b * x);
				printf("\n| %8.2lf | %8.2lf |", x, y);
			}
			else
				printf("\n| %8.2lf | error |", x);

			x += step;

		} while (x <= xend);
	}

	printf("\n|----------|----------|\n");
	system("pause");
	return 0;
}
