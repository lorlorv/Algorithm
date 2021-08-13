//���� ��� Ʈ��
#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int evaluate(TreeNode* t) {
	if (t == NULL)return 0;
	if (t->left == NULL && t->right == NULL) return t->data; //�ܸ����
	else {
		int op1 = evaluate(t->left); //���� ���� Ʈ�� ���
		int op2 = evaluate(t->right); //������ ���� Ʈ�� ���

		printf("%d %c %d�� ����մϴ�.\n", op1, t->data, op2);

		switch (t->data) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}
	}
	return 0;
}
//        +  
//    *       /
//  3  4     8  2

TreeNode n1 = { 3, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 8, NULL, NULL };
TreeNode n5 = { 2, NULL, NULL };
TreeNode n6 = { '/', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode* root = &n7;

int main(void) {
	printf("����=%d\n", evaluate(root));
	return 0;
}