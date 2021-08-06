#include <stdio.h>

int cnt;

int main(void) {
	int N;

	scanf_s("%d", &N);

	while (1) {
		if (N % 5 == 0) { //일단 5로 다 할 수 있으면 개이득이니까
			N /= 5;
			cnt += N;
			printf("%d", cnt);
			break;
		}
		
		N -= 3; //5로 다 안나눠지면 3을 빼간다. 5로 나눠질 때 까지
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