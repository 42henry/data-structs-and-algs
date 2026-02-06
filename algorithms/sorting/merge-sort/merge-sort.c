#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../test.c"

#define LENGTH(a) (sizeof(a)/sizeof(a[0]))

void merge_sort(int *array, int length);

int operations;

int main() {

	benchmark(merge_sort);

	return 0;
}

void merge_sort(int *array, int length) {
	if (length == 1) {
		return;
	} 

	int *a1 = malloc(sizeof(int) * length / 2);
	int *a2 = malloc(sizeof(int) * (length - (length / 2)));
	int a1_count = 0;
	int a2_count = 0;
	for (int i = 0; i < length; i++) {
		if (i < length / 2) {
			a1[a1_count] = array[i];
			a1_count++;
		}
		else {
			a2[a2_count] = array[i];
			a2_count++;
		}
		operations++;
	}

	merge_sort(a1, a1_count);
	merge_sort(a2, a2_count);

	int count = 0;
	int a1_length = a1_count;
	int a2_length = a2_count;
	a1_count = 0;
	a2_count = 0;

	while (count < length) {
		if (a1_count == a1_length) {
			array[count] = a2[a2_count];
			a2_count++;
		}
		else if (a2_count == a2_length) {
			array[count] = a1[a1_count];
			a1_count++;
		}
		else if (a1[a1_count] <= a2[a2_count]) {
			array[count] = a1[a1_count];
			a1_count++;
		}
		else if (a2[a2_count] <= a1[a1_count]) {
			array[count] = a2[a2_count];
			a2_count++;
		}
		count++;
		operations++;
	}

	free(a1);
	free(a2);

	return;
}

