#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//오름차순
int compare_string_up(const void* a, const void* b) {
	return strcmp((char*)a, (char*)b);
}
//내림차순
int compare_string_down(const void* a, const void* b) {
	return strcmp((char*)b, (char*)a);
}

int main(void) {
	char arr[][10] = { "elephant", "choco", "atom", "banana", "dinosour"};

	for (int i = 0; i < 5; i++) {
		printf("%s ", arr[i]);
	}

	qsort(arr, 5, sizeof(*arr), compare_string_up);

	printf("\n오름차순 :");
	for (int i = 0; i < 5; i++) {
		printf("%s ", arr[i]);
	}

	qsort(arr, 5, sizeof(*arr), compare_string_down);

	printf("\n내림차순 :");
	for (int i = 0; i < 5; i++) {
		printf("%s ", arr[i]);
	}

	return 0;
}