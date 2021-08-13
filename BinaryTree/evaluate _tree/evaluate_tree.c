//수식 계산 트리
#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

int evaluate(TreeNode* t) {
	if (t == NULL)return 0;
	if (t->left == NULL && t->right == NULL) return t->data; //단말노드
	else {
		int op1 = evaluate(t->left); //왼쪽 서브 트리 계산
		int op2 = evaluate(t->right); //오른쪽 서브 트리 계산

		printf("%d %c %d을 계산합니다.\n", op1, t->data, op2);

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
	printf("값은=%d\n", evaluate(root));
	return 0;
}