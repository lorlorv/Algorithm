#include <stdio.h>
#include <stdlib.h>
int list1[1000000];
int temp[1000000];

void merge(int A[], int left, int mid, int right) {
	int i, j, k, l;

	i = left, j = mid + 1; k = left;

	while (i <= mid && j <= right) {
		if (A[i] <= A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}
	if (i > mid) {
		for (l = j; l <= right; l++)
			temp[k++] = A[l];
	}
	else
		for (l = i; l <= mid; l++)
			temp[k++] = A[l];

	for (l = left; l <= right; l++) {
		A[l] = temp[l];
	}
}
void mergeSort(int A[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid + 1, right);
		merge(A, left, mid, right);
	}
}

void printList(int A[], int s, int e) {
	int i;
	for (i = s; i <= e; i++)
		printf("%d\n", A[i]);
}

int main(void) {

	int i, n;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &list1[i]);
	}

	mergeSort(list1, 0, n - 1);
	for (i = 0; i < n; i++)
	{
		printf("%d\n", list1[i]);
	}
	return 0;
}
