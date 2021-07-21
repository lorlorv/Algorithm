//2750 - 수 정렬하기 
#include <stdio.h>
#include <stdlib.h>
#define MAX  1001

int list[MAX];
int partition(int list[], int left, int right) {
	int i = left - 1;
	int j = left;

	int pivot = list[right];

	int temp;

	if (left < right) {
		while (j < right) {
			if (list[j] >= pivot)
				j++;
			else {
				temp = list[j];
				list[j] = list[i + 1];
				list[i + 1] = temp;
				i++;
				j++;
			}

		}
		j++;
		temp = list[right];
		list[right] = list[i + 1];
		list[i + 1] = temp;

	}
	return i + 1;
}

void quickSort(int list[], int left, int right) {
	int q;

	if (left < right) {
		q = partition(list, left, right);
		quickSort(list, left, q - 1);
		quickSort(list, q + 1, right);
	}
}
int main(void) {
	int n;
	int flag = 0;

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &list[i]);
	}

	quickSort(list, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d\n", list[i]);
	}
}