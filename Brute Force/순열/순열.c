#include<stdio.h>

int n = 4, r = 3; //4개 중에서 3개 뽑기
int check[4]; 
int result[3]; //결과를 담을 배열
int arr[] = { 1,2,3,4 };

void permutation(int idx) { //순열
	if (idx == r) {
		for (int i = 0; i < r; i++) {
			printf("%d", result[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (check[i] != 1) {
			result[idx] = arr[i];
			check[i] = 1; // TRUE
			permutation(idx + 1);
			check[i] = 0; //FALSE
		}
	}
}
int main(void) {
	permutation(0);
}