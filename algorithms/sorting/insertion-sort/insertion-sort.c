#include <stdio.h>

#include "..\test.c"

#define LENGTH(a) sizeof(a)/sizeof(a[0])

void insertion_sort(int *array, int array_length);

int main() {

	benchmark(insertion_sort);

	return 0;
}

void insertion_sort(int *array, int array_length) {
	int count = 0;
	for (int i = 1; i < array_length; i++) {
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
	return;
}
