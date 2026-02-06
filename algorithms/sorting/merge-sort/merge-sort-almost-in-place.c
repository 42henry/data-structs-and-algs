#include <stdio.h>

#include "../test.c"

#define LENGTH(a) sizeof(a)/sizeof(a[0])

void merge_sort(int *array, int start, int end);
void merge_sort_almost_in_place(int *array, int array_length);

int operations = 0;

int main() {

	int array[5] = {2, 1, 5, 3, 4};
	printf("\narray before: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}
	merge_sort_almost_in_place(array, 5);
	printf("\narray after: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}

	//benchmark(merge_sort_almost_in_place);

	return 0;
}

void merge_sort_almost_in_place(int *array, int array_length) {
	merge_sort(array, 0, array_length);
	return;
}

void merge_sort(int *array, int start, int end) {
	if (start == end) {
		return;
	}

	int s1 = start;
	int e1 = (start + end) / 2;
	int s2 = e1 + 1;
	int e2 = end;
	merge_sort(array, s1, e1);
	merge_sort(array, s2, e2);

	int count = start;
	int temparray[end + 1];

	while (count < end + 1) {
		if (s1 > e1) {
			temparray[count] = array[s2];
			s2++;
		}
		else if (s2 > e2) {
			temparray[count] = array[s1];
			s1++;
		}
		else if ((array[s1] >= array[s2])) {
			temparray[count] = array[s2];
			s2++;
		}
		else {
			temparray[count] = array[s1];
			s1++;
		}
		count++;
		operations++;
	}

	for (int i = start; i < end + 1; i++) {
		array[i] = temparray[i];
		operations++;
	}

	return;
}
