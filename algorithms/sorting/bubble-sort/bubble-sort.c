#include <stdio.h>

#define LENGTH(a) sizeof(a)/sizeof(a[0])

int main() {

	int array[5] = {3, 4, 2, 1, 5};

	printf("\n-----------------------\n");
	for (int i = 0; i < LENGTH(array); i++) {
		printf("%d", array[i]);
	}
	printf("\n-----------------------\n");

	for (int i = 0; i < LENGTH(array); i++) {
		for (int j = i + 1; j < LENGTH(array); j++) {
			if (array[j] < array[i]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}

	printf("\n-----------------------\n");
	for (int i = 0; i < LENGTH(array); i++) {
		printf("%d", array[i]);
	}
	printf("\n-----------------------\n");

	return 0;
}
