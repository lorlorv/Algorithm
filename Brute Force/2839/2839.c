#include <stdio.h>

int cnt;

int main(void) {
	int N;

	scanf_s("%d", &N);

	while (1) {
		if (N % 5 == 0) { //�ϴ� 5�� �� �� �� ������ ���̵��̴ϱ�
			N /= 5;
			cnt += N;
			printf("%d", cnt);
			break;
		}
		
		N -= 3; //5�� �� �ȳ������� 3�� ������. 5�� ������ �� ����
		cnt++;

		
	    if (N == 0) {
			printf("%d", cnt);
			break;
		}
		else if (N < 3) {
			printf("-1");
			break;
		}
	}

	return 0;
}