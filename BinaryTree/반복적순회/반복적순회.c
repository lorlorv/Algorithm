//반복적 순회
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

typedef TreeNode* element;

typedef struct StackNode {
	element item;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode* top;
}LinkedStackType;

//스택 초기화 함수
void init(LinkedStackType* s) {
	s->top = NULL;
}
//공백 상태 검출 함수
int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}
//포화 상태 검출 함수
int is_full(LinkedStackType* s) {
	return 0;
}
//삽입함수
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}
//삭제 함수
element pop(LinkedStackType* s) {
	StackNode* temp = s->top;
	element item;
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}
//피크함수
element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->top->item;
}
////스택에 들어 있는 요소 출력 함수
//void stack_print(LinkedStackType* s) {
//	int i;
//	StackNode* temp = s->top;
//
//	if (is_empty(s))
//		printf("<empty>");
//	else {
//		while (temp != NULL) {
//			if (temp == s->top)
//				printf("%d<-top\n", temp->item);
//			else
//				printf("%d\n", temp->item);
//			temp = temp->link;
//		}
//	}
//	printf("--\n");
//}
void inorder_iter(TreeNode* root) {
	LinkedStackType s;

	init(&s);

	while (1) {
		for (; root; root = root->left) //루트의 왼쪽 노드 전부를 스택에 push
			push(&s, root);
		if (is_empty(&s)) //스택이 빌때까지
			break;
		else
			root = pop(&s); //pop한 노드를 root로
		printf("[%d]", root->data);
		root = root->right; //root의 오른쪽 자식이 root가 됨
	}
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int main(void) {

	printf("중위순회=");
	inorder_iter(root);
	printf("\n");
	return 0;
}



