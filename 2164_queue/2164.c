#include <stdio.h>
#include <stdlib.h>
#define MAX 500001


typedef int element;
typedef struct {
	element data[MAX];
	int front, rear;
}QueueType;

void error(char* message) {
	printf("%s\n", message);
	exit(1);
}
//�ʱ�ȭ
void init_queue(QueueType* q) {
	q->front = q->rear = 0;

}
//���� ���� ���� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX == q->front);
}

//���� ť ��� �Լ� 
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

//�����Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("��ȭ������");
	}
	else
		q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = item;
}

//���� �Լ� 
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("���������");
	}
	else
		q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}

//ī�� �Լ�
void card(QueueType* q) {
	int tmp;

	while ((q->front + 1) % MAX != q->rear % MAX) {
		dequeue(q);
		tmp = dequeue(q);
		enqueue(q, tmp);
	}

	printf("%d", q->data[q->rear]);
}

int main(void) {
	QueueType queue;
	int n;

	init_queue(&queue);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		enqueue(&queue, i + 1);
	}

	card(&queue);

	return 0;
}

