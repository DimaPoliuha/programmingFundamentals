#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void fill_Arr(int *arr, int size);//вводим елементы массива
void printArr(int *arr, int size);//печатает массив
int searchElement(int *arr, int size);//поиск елемнета кратного 3 
void moveArr(int *arr, int size);//циклический сдвиг

int main(void) {

	setlocale(LC_ALL, "");

	int arr[10];//создаем массив
	int size = 10;//размер массива

	int sorted = 0;//колличество елементов, которые делятся на 3 (которые уже перенесли в конец)
	int elementsExist = 1;//true пока все елементы кратные 3 не перемещены в конец
	int position = 0;//хранит позицию кратного елемента до перемещения

	fill_Arr(arr, size);//вводим елементы массива

	printArr(arr, size);//печатает массив

	printf("\n\t | С Т А Р Т |\n");
	do {
		position = searchElement(arr, size - sorted);//поиск елемнета кратного 3 
		if (position != -1) {
			printf("\nПередвигаем елемент с позиции %i в конец:", position);
			for (int i = 0; i < size - 1 - sorted - position; i++) {
				/*(size - 1 - sorted) - размер массива занятый неотсортироваными елементами
				- position - сколько ел. нужно сдвинуть, прежде чем ел. кратный 3 не достигнет конца неотсортированной части массива*/
				moveArr(arr, size - sorted);//циклический сдвиг
			}
			printArr(arr, size);
			sorted++;
		}
		else {
			elementsExist = 0;
		}
	} while (elementsExist == 1);

	printf("\n\nМы передвинули %i ел. в конец массива\n", sorted);

	system("pause");
	return 0;
}

void fill_Arr(int *arr, int size) {//вводим елементы массива
	for (int i = 0; i < size; i++) {
		printf("Введите элемент[%i]: ", i);
		scanf("%d", &arr[i]);
	}
}

void printArr(int *arr, int size) {//печатает массив
	printf("\nВаш массив:");
	for (int i = 0; i < size; i++) {
		printf("   %i", arr[i]);
	}
	printf("\n");
}

int searchElement(int *arr, int size) {//поиск елемнета кратного 3 
	int position = 0;
	int found = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] % 3 == 0 ) {
			if (found == 0) {
				found = 1;
				position = i;//позиция этого ел. = индекс
			}
		}
	}

	if (found) {//если не 0
		return position;//возвращаем индекс этого елемента
	}
	else {
		return -1;//таких елементов не существует
	}
}

void moveArr(int *arr, int size) {//циклический сдвиг
	int lastVal = arr[size - 1];//последний ел.

	for (int i = size - 1; i != 0; i--) {//цикл идет с конца массива
		arr[i] = arr[i - 1];
	}

	arr[0] = lastVal;//первому ел присваивает знач последнего
}
