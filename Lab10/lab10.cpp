#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void fill_Arr(int arr[][4], int size);//вводим елементы массива
									  //void fillRandom(int arr[][8], int size);
void printArr(int arr[][4], int size);//печатает массив

int main(void) {
	setlocale(LC_ALL, "");
	int arr[4][4];//массив 4 на 4
	int size = 4;
	int sum = 0;

	fill_Arr(arr, size);//вводим елементы массива
						//fillRandom(arr, size); - заполнение массива рандомными числами
	printArr(arr, size);//печатает массив
	int max = arr[0][4];//присваиваем максимальное значение елементу

	for (int k = 0; k < size; k++) {
		int i = k;
		int j = size - 1;
		for (; i >= 0; i--, j--) {
			sum += arr[i][j];
		}
		printf("\nСумма%i = %i", k, sum);
		if (sum > max) {
			max = sum;
		}
		sum = 0;
	}

	for (int k = 0; k < size; k++) {
		int i = size - 1;
		int j = size - k - 1;
		for (; j >= 0; i--, j--) {
			sum += arr[i][j];
		}
		printf("\nСумма%i = %i", k + 4, sum);
		if (sum > max) {
			max = sum;
		}
		sum = 0;
	}

	printf("\n\nМаксимальная сумма: %i\n", max);

	system("pause");
	return 0;
}

void printArr(int arr[][4], int size) {//печатает массив
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%i  ", arr[i][j]);
		}
		printf("\n");
	}
}

void fill_Arr(int arr[][4], int size) {//вводим елементы массива
	int i = 0;
	int j = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("Введите элемент[%i][%i]: ", i, j);
			scanf("%i", &arr[i][j]);
		}
	}
}

/*void fillRandom(int arr[8][8], int size) {
srand(time(NULL));

for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
arr[i][j] = rand() % 10;
}
}
}*/