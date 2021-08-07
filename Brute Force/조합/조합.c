//조합 Combination
#include <stdio.h>

int n = 4, r = 3; //4개 중에서 3개 뽑기 (순서상관없이)
int check[4];
int result[3]; //결과를 담을 배열
int arr[] = { 1,2,3,4 };

void combination(int idx, int count) { //조합
	if (count == r) {
		for (int i = 0; i < r; i++) {
			printf("%d", result[i]);
		}
		printf("\n");
		return;
	}

	for (int i = idx; i < n; i++) {
		if (check[i] != 1) {
			result[count] = arr[i];
			check[i] = 1; // TRUE
			combination(i, count + 1);
			check[i] = 0; //FALSE
		}
	}
}
int main(void) {
	combination(0, 0);
}