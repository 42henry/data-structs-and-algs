#include <stdio.h>
#include <stdlib.h>

#define LENGTH(a) sizeof(a)/sizeof(a[0])

void merge_sort(int *array, int length);

int operations;

int main() {

	int array[5] = {4, 3, 2, 5, 1};
	operations = 0;
	printf("\n-------------------\n");
	for (int i = 0; i < LENGTH(array); i++) {
		printf("%d", array[i]);
	}
	printf("\n-------------------\n");

	merge_sort(array, LENGTH(array));

	printf("\n-------------------\n");
	for (int i = 0; i < LENGTH(array); i++) {
		printf("%d", array[i]);
	}
	printf("\n-------------------\n");
	printf("%d operations", operations);

	return 0;
}

void merge_sort(int *array, int length) {
	if (length == 1) {
		return;
	} 

	int *a1 = malloc(sizeof(int) * length / 2);
	int *a2 = malloc(sizeof(int) * length / 2);
	int a1_count = 0;
	int a2_count = 0;
	for (int i = 0; i < length; i++) {
		if (i < length / 2) {
			a1[a1_count] = array[i];
			a1_count++;
		}
		if (i >= length / 2) {
			a2[a2_count] = array[i];
			a2_count++;
		}
		operations++;
	}
	merge_sort(a1, a1_count);
	merge_sort(a2, a2_count);

	int count = 0;
	a1_count = 0;
	a2_count = 0;
	while (count < length) {
		if (a1[a1_count] < a2[a2_count]) {
			array[count] = a1[a1_count];
			count++;
			a1_count++;
		}
		else {
			array[count] = a2[a2_count];
			count++;
			a2_count++;
		}
		operations++;
	}
	free(a1);
	free(a2);

	return;
}

