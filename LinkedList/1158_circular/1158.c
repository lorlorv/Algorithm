//1158 - 요세푸스/이중연결리스트
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	struct DListNode* next;
	struct DListNode* pre;
	element data;
}Node;

Node* head = NULL;
Node* tail = NULL;

void insert(element data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (head == NULL) { //노드가 하나도 없을 때 
		head = newNode;
		tail = newNode;
		newNode->pre = head;
		newNode->next = tail;
	}
	else {
		tail->next = newNode;
		newNode->pre = tail;
		head->pre = newNode;
		newNode->next = head;
		tail = newNode;
	}
}

int delete_pos(int pos) {
	Node* p = head;
	if (head == NULL) return 0;

	while (--pos) {
		p = p->next;
	}
	head = p->next; //다음 시작지점 저장

	p->pre->next = p->next;
	p->next->pre = p->pre;

	return p->data;
}

int main(void) {
	int n, k;

	scanf_s("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		insert(i);
	}

	printf("<");
	for (int i = 0; i < n - 1; i++) {
		printf("%d, ", delete_pos(k));
	}
	printf("%d", delete_pos(k));
	printf(">");

	return 0;
}