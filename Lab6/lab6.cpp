#include "stdafx.h" 
#include "math.h" 
#include "windows.h" 

int main()
{
	double Y0 = 3.1;
	double Y;
	double x = 9.5;
	double e;
	printf("enter e=");
	scanf("%lf", &e);
	Y = (Y0 + x / Y0) / 2;
	while (fabs(Y - (x / Y0)) >= 2 * e) {
		Y = (Y + x / Y0) / 2;
		printf("sqrtx=%lf\n", Y);
	}
	system("pause");
	return 0;
}