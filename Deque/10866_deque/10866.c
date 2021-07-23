//10866 - DEQUE
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

//�����Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		printf("��ȭ������");
	}
	else
		q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = item;
}

void push_front(QueueType* q, element item) {
	if (is_full(q)) {
		printf("��ȭ������");
	}
	else {
		q->data[q->front] = item;
		q->front = (q->front - 1 + MAX) % MAX;
	}
	
}

//���� �Լ� 
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		return -1;
	}
	else
		q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}

element pop_back(QueueType* q) {
	int rear;
	if (is_empty(q)) {
		return -1;
	}
	else {
		rear = q->data[q->rear];
		q->rear = (q->rear - 1 + MAX) % MAX;
	}
	return rear;
}
element front(QueueType* q) {
	if (is_empty(q))
		return -1;
	else
		return q->data[(q->front + 1) % MAX];
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
	char s[15];

	init_queue(&queue);

	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf_s("%s", s, sizeof(s));

		//push_front
		if (strcmp(s, "push_front") == 0) {
			scanf_s("%d", &item);
			push_front(&queue, item);
		}
		//push_back
		else if (strcmp(s, "push_back") == 0) {
			scanf_s("%d", &item);
			enqueue(&queue, item);
		}
		//pop_front
		else if (strcmp(s, "pop_front") == 0) {
			printf("%d\n", dequeue(&queue));
		}
		//pop_back
		else if (strcmp(s, "pop_back") == 0)
			printf("%d\n", pop_back(&queue));
		//front
		else if (strcmp(s, "front") == 0)
			printf("%d\n", front(&queue));
		//back
		else if (strcmp(s, "back") == 0)
			printf("%d\n", back(&queue));
		//size
		else if (strcmp(s, "size") == 0)
			printf("%d\n", (queue.rear - queue.front + MAX) % MAX);
		//empty
		else if (strcmp(s, "empty") == 0) {
			if (is_empty(&queue))
				printf("1\n");
			else
				printf("0\n");
		}
	}

	return 0;
}

