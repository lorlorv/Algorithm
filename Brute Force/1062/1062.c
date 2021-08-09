#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char word[50][50]; //�ܾ� �Է¹ޱ�
int isLearned[26]; //�ܾ �������
int result;

int Max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void checkDFS(int index, int count, int n, int k) {

	if (count == k) {	
		int temp = 0;
		//word�� i�� ��� K���� ���ڿ� ������ �ȵ����� Ȯ��
		for (int i = 0; i < n; i++) {
			int flag = 1;
			for (int j = 0; word[i][j] != '\0'; j++) {
				if (isLearned[word[i][j] - 'a'] != 1) {
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				temp++;	
		}
		result = Max(result, temp);
		return;

	}
	for (int i = index; i < 26; i++) {//a, n, t, i, c�� �̹� isLearned�� TRUE�̹Ƿ� if�� �ɸ�������!
		if (isLearned[i] != 1) { //����� �ʾ����� 
			isLearned[i] = 1;
			checkDFS(i, count + 1, n, k);
			isLearned[i] = 0;
		}
	}
}

int main(void) {
	int n, k;

	scanf_s("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf_s("%s", &word[i], 50);
	}

	if (k < 5) {
		printf("0");
		return 0;
	}

	isLearned[0] = 1;
	isLearned[2] = 1;
	isLearned[8] = 1;
	isLearned[13] = 1;
	isLearned[19] = 1;

	k = k - 5;

	checkDFS(0, 0, n, k);

	printf("%d", result);
	
}