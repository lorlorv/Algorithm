#include <stdio.h>
#include <stdlib.h>

//오름차순
int compare_int_up(const void* a, const void* b) {
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}
//내림차순
int compare_int_down(const void* a, const void* b) {
	if (*(int*)a < *(int*)b)
		return 1;
	else if (*(int*)a > *(int*)b)
		return -1;
	else
		return 0;
}

int main(void) {
	int arr[] = { 5,8,2,3,10,4,7,9,6,1 };

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	qsort(arr, 10, sizeof(arr[0]), compare_int_up);

	printf("\n오름차순 :");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	qsort(arr, 10, sizeof(arr[0]), compare_int_down);

	printf("\n내림차순 :");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}