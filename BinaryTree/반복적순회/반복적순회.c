//�ݺ��� ��ȸ
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

//���� �ʱ�ȭ �Լ�
void init(LinkedStackType* s) {
	s->top = NULL;
}
//���� ���� ���� �Լ�
int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}
//��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s) {
	return 0;
}
//�����Լ�
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ翡��\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}
//���� �Լ�
element pop(LinkedStackType* s) {
	StackNode* temp = s->top;
	element item;
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else {
		item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}
//��ũ�Լ�
element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->top->item;
}
////���ÿ� ��� �ִ� ��� ��� �Լ�
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
		for (; root; root = root->left) //��Ʈ�� ���� ��� ���θ� ���ÿ� push
			push(&s, root);
		if (is_empty(&s)) //������ ��������
			break;
		else
			root = pop(&s); //pop�� ��带 root��
		printf("[%d]", root->data);
		root = root->right; //root�� ������ �ڽ��� root�� ��
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

	printf("������ȸ=");
	inorder_iter(root);
	printf("\n");
	return 0;
}



