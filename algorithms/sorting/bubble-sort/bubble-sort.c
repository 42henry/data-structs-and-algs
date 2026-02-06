#include <stdio.h>

#include "..\test.c"

#define LENGTH(a) sizeof(a)/sizeof(a[0])

void bubble_sort(int *array, int array_length);

int main() {

	benchmark(bubble_sort);

	return 0;
}

void bubble_sort(int *array, int array_length) {
	for (int i = 0; i < array_length; i++) {
		for (int j = i + 1; j < array_length; j++) {
			if (array[j] < array[i]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
