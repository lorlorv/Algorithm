//��ũ ǥ�������� ������ ����Ʈ�� skeleton
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
// root
// 15
// 4 15
// 15 16 25
//
//root2
//15
//4 15
//15 16 25
//28
TreeNode n1 = { 15, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;
TreeNode m1 = { 15, NULL, NULL };
TreeNode m2 = { 4, &n1, NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL }; // �߰�
TreeNode m4 = { 25, NULL, &m7 }; // ����
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;

//��ܸ���� count
int get_nonleaf_count(TreeNode* t) {
	if (t != NULL) {
		if (t->left == NULL && t->right == NULL)
			return 0;
		else
			return (1 + get_nonleaf_count(t->left) + get_nonleaf_count(t->right));
	}
	else
		return 0;
}
int equal(TreeNode* t1, TreeNode* t2) {
	if (t1 == NULL && t2 == NULL)
		return 1;
	else if (t1 != NULL && t2 != NULL) { //�� ���� �߰� !
		if (t1->data == t2->data) {
			if (!equal(t1->left, t2->left))
				return 0;
			if (!equal(t1->right, t2->right))
				return 0;
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}
int get_oneleaf_count(TreeNode* node) {
	int count = 0;

	if (node->left != NULL && node->right == NULL || node->left == NULL && node->right != NULL)
		count++;
	if (node->left != NULL)
		count += get_oneleaf_count(node->left);
	if (node->right != NULL)
		count += get_oneleaf_count(node->right);
	return count;
}
int get_twoleaf_count(TreeNode* node) {
	int count = 0;
	
	if (node->left != NULL && node->right != NULL)
		count++;
	if (node->left != NULL)
		count += get_twoleaf_count(node->left);
	if (node->right != NULL)
		count += get_twoleaf_count(node->right);

	return count;
}
int get_max(TreeNode* t) {
	int max = t->data;
	int leftMax, rightMax;
	if (t->left != NULL) {
		leftMax = get_max(t->left);
		if (leftMax > max) {
			max = leftMax;
		}
	}
	if (t->right != NULL) {
		rightMax = get_max(t->right);
		if (rightMax > max) {
			max = rightMax;
		}
	}
	return max;
}
int get_min(TreeNode* t) {
	int min = t->data;
	int leftMin, rightMin;
	if (t->left != NULL) {
		leftMin = get_min(t->left);
		if (leftMin < min) {
			min = leftMin;
		}
	}
	if (t->right != NULL) {
		rightMin = get_min(t->right);
		if (rightMin < min) {
			min = rightMin;
		}
	}
	return min;

}
void node_increase(TreeNode* node) {
	if (node == NULL)
		return;
	node->data += 1;

	node_increase(node->left);
	node_increase(node->right);
}
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int main(void)
{
	//TreeNode* result[MAX_TREE_SIZE];
	//TreeNode* clone;
	//int i, num;
	printf("��)\n");
	printf("Ʈ�� root �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root));
	printf("Ʈ�� root2 �� ��ܸ������ ������ %d.\n", get_nonleaf_count(root2));
	printf("Ʈ�� root �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� �ϳ��� �ִ� ����� ������ %d.\n", get_oneleaf_count(root2));
	printf("Ʈ�� root �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root));
	printf("Ʈ�� root2 �� �ڽ��� ���� �ִ� ����� ������ %d.\n", get_twoleaf_count(root2));
	printf("Ʈ�� root ���� ���� ū ���� %d.\n", get_max(root));
	printf("Ʈ�� root2 ���� ���� ū ���� %d.\n", get_max(root2));
	printf("Ʈ�� root ���� ���� ���� ���� %d.\n", get_min(root));
	printf("Ʈ�� root2 ���� ���� ���� ���� %d.\n", get_min(root2));
	printf("\n ��)\n");
	//num = search(root, 15, result);
	// for (i = 0; i < num; i++)
	//printf("(0x%p, %d), ", result[i], result[i]->data);
	/*printf("\n");
	printf("\n ��)\n");
	preorder(root);
	node_increase(root);
	printf("\n");
	preorder(root);
	printf("\n");
	preorder(root2);
	node_increase(root2);
	printf("\n");
	preorder(root2);
	printf("\n");*/

	printf("%s\n", equal(root, root) ? "����" : "�ٸ���");
	printf("%s\n", equal(root2, root2) ? "����" : "�ٸ���");
	printf("%s\n", equal(root, root2) ? "����" : "�ٸ���");
	printf("\n ��)\n");
	// clone = copy(root) ;
	preorder(root);
	printf("\n");
	// preorder(clone) ;
	printf("\n");
}