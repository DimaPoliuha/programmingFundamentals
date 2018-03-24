#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[12][12];
	int startArr[12][12];
	int size = 12;
	int k = 0;
	system("color 4");

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = 1;
			startArr[i][j] = 1;
		}
	}

	if (size % 2 == 0) {
		k = size / 2;
	}
	else {
		k = size / 2 + 1;
	}

	for (int i = 0; i != k; i++) {
		for (int j = k; j != size / 2 + k - i; j++) {
			arr[i][j] = 0;
		}
	}

	int count = 1;
	for (int i = k; i != size; i++, count++) {
		for (int j = k; j != k + count && count != k + 1; j++) {
			arr[i][j] = 0;
		}
	}

	printf("\n\n");

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%i ", startArr[i][j]);
		}

		printf("\t\t");

		for (int j = 0; j < size; j++) {
			printf("%i ", arr[i][j]);
		}

		printf("\n");
	}

	printf("\n\n");
	system("pause");
	return 0;
}
