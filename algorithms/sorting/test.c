#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>

#define MAX 1000000

int sort_test(void (*sort_function)(int*, int), int array_length);
int benchmark(void (*sort_function)(int*, int));

int sort_test(void (*sort_function)(int*, int), int array_length) {

	srand(time(NULL));

	int *array = malloc(sizeof(int) * array_length);
	if (array == NULL) {
		printf("\nout of space!");
		return 0;
	}
	for (int i = 0; i < array_length; i++){
		array[i] = (rand() % MAX) + 1;
	}


	clock_t begin = clock();

	sort_function(array, array_length);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\n%d entries took %f seconds", array_length, time_spent);
	if (time_spent > 1) {
		return -1;
	}

	//for (int i = 0; i < array_length; i++){
		//for (int j = i + 1; j < array_length; j++){
			//if (array[i] > array[j]) {
				//printf("\narray not in order");
				//return -1;
			//}
		//}
	//}
	//printf("\narray successfully ordered");

	return 0;
}

int benchmark(void (*sort_function)(int*, int)) {

	int array_length = 10;
	while (sort_test(sort_function, array_length) > -1) {
		array_length *= 10;
	}

	return 0;
}
