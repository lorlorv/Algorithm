#include <stdio.h>
#define MAX 1000000000 + 1
#define MIN -(1000000000 + 1)

int N;
int sum = 0, max = MIN, min = MAX;
int arr[12];
int operator[4];

void calc(int index, int sum) {//index == 1, sum == arr[0]

	//������ �� ������ MAX���� MIN���� �Ǻ�
	if (index == N) {
		if (max < sum) max = sum;
		if (min > sum) min = sum;

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operator[i]) { //operator[i]�� 0�� �ƴҵ���
			operator[i]--; //�ѹ� �����ϱ�
			if (i == 0)
				calc(index + 1, sum + arr[index]);
			else if (i == 1)
				calc(index + 1, sum - arr[index]);
			else if (i == 2)
				calc(index + 1, sum * arr[index]);
			else
				calc(index + 1, sum / arr[index]);

			//��Ʈ��ŷ���� �ٸ� �����ڸ� �־��ش�
			operator[i]++;
		}	
	}	
}

int main(void) {
	int number;
	int count;

	scanf_s("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &number);
		arr[i] = number;
	}

	for (int i = 0; i < 4; i++) { //+, - , *, / �� ���� ��� �ִ� �� ex) 2112
		scanf_s("%d", &count); 
		operator[i] = count;
	}
	calc(1, arr[0]);
	printf("%d\n%d", max, min);
}