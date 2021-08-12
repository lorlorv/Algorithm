//레벨 순회
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;
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
		error("공백상태임");
	}
	else
		q->front = (q->front + 1) % MAX;
	return q->data[q->front];
}

void level_order(TreeNode* t) {
	QueueType q;

	init_queue(&q);

	if (t == NULL)
		return;
	enqueue(&q, t);
	while (!is_empty(&q)) {
		t = dequeue(&q);
		printf("[%d] ", t->data);

		if (t->left != NULL)
			enqueue(&q,t->left);
		if (t->right != NULL)
			enqueue(&q, t->right);
	}
}

//      15
//   4      20
// 1       16 25

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int main(void) {
	printf("레벨 순회=");
	level_order(root);
	return 0;
}