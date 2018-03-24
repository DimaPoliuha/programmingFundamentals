#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void fill_Arr(int *arr, int size);//������ �������� �������
void printArr(int *arr, int size);//�������� ������
int searchElement(int *arr, int size);//����� �������� �������� 3 
void moveArr(int *arr, int size);//����������� �����

int main(void) {

	setlocale(LC_ALL, "");

	int arr[10];//������� ������
	int size = 10;//������ �������

	int sorted = 0;//����������� ���������, ������� ������� �� 3 (������� ��� ��������� � �����)
	int elementsExist = 1;//true ���� ��� �������� ������� 3 �� ���������� � �����
	int position = 0;//������ ������� �������� �������� �� �����������

	fill_Arr(arr, size);//������ �������� �������

	printArr(arr, size);//�������� ������

	printf("\n\t | � � � � � |\n");
	do {
		position = searchElement(arr, size - sorted);//����� �������� �������� 3 
		if (position != -1) {
			printf("\n����������� ������� � ������� %i � �����:", position);
			for (int i = 0; i < size - 1 - sorted - position; i++) {
				/*(size - 1 - sorted) - ������ ������� ������� ����������������� ����������
				- position - ������� ��. ����� ��������, ������ ��� ��. ������� 3 �� ��������� ����� ����������������� ����� �������*/
				moveArr(arr, size - sorted);//����������� �����
			}
			printArr(arr, size);
			sorted++;
		}
		else {
			elementsExist = 0;
		}
	} while (elementsExist == 1);

	printf("\n\n�� ����������� %i ��. � ����� �������\n", sorted);

	system("pause");
	return 0;
}

void fill_Arr(int *arr, int size) {//������ �������� �������
	for (int i = 0; i < size; i++) {
		printf("������� �������[%i]: ", i);
		scanf("%d", &arr[i]);
	}
}

void printArr(int *arr, int size) {//�������� ������
	printf("\n��� ������:");
	for (int i = 0; i < size; i++) {
		printf("   %i", arr[i]);
	}
	printf("\n");
}

int searchElement(int *arr, int size) {//����� �������� �������� 3 
	int position = 0;
	int found = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] % 3 == 0 ) {
			if (found == 0) {
				found = 1;
				position = i;//������� ����� ��. = ������
			}
		}
	}

	if (found) {//���� �� 0
		return position;//���������� ������ ����� ��������
	}
	else {
		return -1;//����� ��������� �� ����������
	}
}

void moveArr(int *arr, int size) {//����������� �����
	int lastVal = arr[size - 1];//��������� ��.

	for (int i = size - 1; i != 0; i--) {//���� ���� � ����� �������
		arr[i] = arr[i - 1];
	}

	arr[0] = lastVal;//������� �� ����������� ���� ����������
}
