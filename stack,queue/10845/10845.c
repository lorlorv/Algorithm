#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100001

typedef int element;
typedef struct {
	element data[MAX];
	int front, rear;
}QueueType;

void error(char* message) {
	printf("%s\n", message);
	exit(1);
}
//초기화
void init_queue(QueueType* q) {
	q->front = q->rear = 0;

}
//공백 상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX == q->front);
}

//원형 큐 출력 함수 
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

//삽입함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("포화상태임");
	}
	else
		q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = item;
}

//삭제 함수 
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		return -1;
	}
	else
		q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}
element front(QueueType* q) {
	if (is_empty(q))
		return -1;
	else
		return q->data[q->front + 1];
}
element back(QueueType* q) {
	if (is_empty(q))
		return -1;
	else
		return q->data[q->rear];
}


int main(void) {
	QueueType queue;
	int n, item = 0;
	char s[10];

	init_queue(&queue);

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%s", s, sizeof(s));

		if (strcmp(s, "push") == 0) {
			scanf_s("%d", &item);
			enqueue(&queue, item);
		}
		else if (strcmp(s, "pop") == 0) {
			printf("%d\n", dequeue(&queue));
		}
		else if (strcmp(s, "front") == 0)
			printf("%d\n", front(&queue));
		else if (strcmp(s, "back") == 0)
			printf("%d\n", back(&queue));
		else if (strcmp(s, "size") == 0)
			printf("%d\n", (queue.rear - queue.front));
		else if (strcmp(s, "empty") == 0) {
			if (is_empty(&queue))
				printf("1\n");
			else
				printf("0\n");
		}
	}

	return 0;
}

