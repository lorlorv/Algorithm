//1181 - Á¤·Ä
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20001
#define MAX_STRING 51
#pragma warning(disable:4996)

char list[MAX][MAX_STRING];
char tmp[MAX][MAX_STRING];

int partition(char list[][MAX_STRING], int left, int right) {
	int pivot = strlen(list[right]);
	int i, j;
	char temp[MAX_STRING] = "";

	i = left - 1;
	j = left;

	if (left < right) {
		while (j < right) {
			int size = strlen(list[j]);
			if (size > pivot) {
				j++;
			}
			else if (size == pivot) {
				if (strcmp(list[j], list[right]) > 0) {
					strcpy(temp, list[right]);
					strcpy(list[right], list[i + 1]);
					strcpy(list[i + 1], temp);
				}
				i++;
				j++;								
			}
			else {
				strcpy(temp, list[j]);
				strcpy(list[j], list[i + 1]);
				strcpy(list[i + 1], temp);
				i++;
				j++;
			}
		}
		j++;

		strcpy(temp, list[right]);
		strcpy(list[right], list[i + 1]);
		strcpy(list[i + 1], temp);
	}
	return i + 1;

}
void quickSort(char list[][MAX_STRING], int left, int right) {
	int q;

	if (left < right) {
		q = partition(list, left, right);
		quickSort(list, left, q - 1);
		quickSort(list, q + 1, right);
	}
}
int main(void) {
	int n;
	int k = 0;
	int flag = 0;
	char temp[MAX_STRING] = "";

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%s", tmp[i], MAX_STRING);
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (strcmp(list[j], tmp[i]) == 0) {
				flag = 0;
				break;
			}
			flag = 1;
		}
		if (flag == 1)
			strcpy(list[k++], tmp[i]);
	}

	quickSort(list, 0, k - 1);

	for (int i = 0; i < k; i++) {
		printf("%s\n", list[i]);
	}

	return 0;
}

