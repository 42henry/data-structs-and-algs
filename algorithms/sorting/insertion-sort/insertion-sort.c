#include <stdio.h>

#define LENGTH(a) sizeof(a)/sizeof(a[0])

int main() {

	int array[5] = {4, 3, 2, 5, 1};

	printf("\n-----------------------\n");
	for (int i = 0; i < LENGTH(array); i++) {
		printf("%d", array[i]);
	}
	printf("\n-----------------------\n");

	int count = 0;
	for (int i = 1; i < LENGTH(array); i++) {
		int curr = array[i];
		int j = i - 1;
		while ((j > -1) && (array[j] > curr)) {
			array[j + 1] = array[j];
			j--;
			count++;
		}
		j++;
		array[j] = curr;
	}

	printf("\n-----------------------\n");
	for (int i = 0; i < LENGTH(array); i++) {
		printf("%d", array[i]);
	}
	printf("\n-----------------------\n");
	printf("\ntook %d operations", count);

	return 0;
}
