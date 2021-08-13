//������ ���� Ʈ��
#include <stdio.h>
typedef int element;
typedef struct TreeNode {
	element data;
	struct TreeNode* left, *right;
	element is_thread;
}TreeNode;

//���� �ļ��ڸ� ��ȯ�ϴ� �Լ� 
TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right;
	if (q == NULL || p->is_thread == 1)
		return q;

	//���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�
	while (q->left != NULL) q = q->left;
	return q;
}

void thread_inorder(TreeNode* t) {
	TreeNode* q;
	q = t;
	while (q->left != NULL) q = q->left;
	do {
		printf("%d->", q->data);
		q = find_successor(q);
	} while (q); //�ļ��ڰ� NULL�� �ƴҶ�����
}

//      7
//   3     6
// 1     4   8
//     5

TreeNode n1 = { 1, NULL, NULL,1 };
TreeNode n2 = { 3, &n1, NULL,1 };
TreeNode n3 = { 5, NULL, NULL ,1};
TreeNode n4 = { 4, &n3, NULL,1 };
TreeNode n5 = { 8, NULL, NULL,0 };
TreeNode n6 = { 6, &n4, &n5 ,0};
TreeNode n7 = { 7, &n2, &n6 ,0};
TreeNode* root = &n7;

int main(void) {
	//������ ����
	n1.right = &n2;
	n2.right = &n7;
	n3.right = &n4;
	n4.right = &n6;

	//���� ��ȸ
	thread_inorder(root);
	printf("\n");
	return 0;
}