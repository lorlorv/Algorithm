//��ũ ǥ�������� ������ ����Ʈ��
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
// root
//	    15
//   4      15
// 15     16  25
//
//root2
//      15
//   4      15
// 15     16  25
//              28

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
		max = MAX(max, leftMax);
	}
	if (t->right != NULL) {
		rightMax = get_max(t->right);
		max = MAX(max, rightMax);
	}
	return max;
}
int get_min(TreeNode* t) {
	int min = t->data;
	int leftMin, rightMin;
	if (t->left != NULL) {
		leftMin = get_min(t->left);
		min = MIN(min, leftMin);
	}
	if (t->right != NULL) {
		rightMin = get_min(t->right);
		min = MIN(min, rightMin);
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

//���� Ʈ������ �־��� key ���� ���� ������ ��� ã�� �ش� ����� ������ ��ȯ
int search(TreeNode* t, int key) {
	if (t != NULL) {
		if (t->data == key)
			return 1 + search(t->left, key) + search(t->right, key);
		else
			return (search(t->left, key) + search(t->right, key));
	}
	return 0;
}

TreeNode* copy(TreeNode* t) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	if (t != NULL) {
		temp->data = t->data;
		temp->left = copy(t->left);
		temp->right = copy(t->right);
		return temp;
	}
	return NULL;
}

int main(void)
{
	TreeNode* clone;

	printf("[non_leaf_node ����]\n");
	printf("root : %d, root2 : %d\n\n", get_nonleaf_count(root),get_nonleaf_count(root2));
	
	printf("[one_leaf_node ����]\n");
	printf("root : %d, root2 : %d\n\n", get_oneleaf_count(root), get_oneleaf_count(root2));

	printf("[two_leaf_node ����]\n");
	printf("root : %d, root2 : %d\n\n", get_twoleaf_count(root), get_twoleaf_count(root2));

	printf("[MAX���� ���� ���]\n");
	printf("root : %d, root2 : %d\n\n", get_max(root), get_max(root2));

	printf("[MIN���� ���� ���]\n");
	printf("root : %d, root2 : %d\n\n", get_min(root), get_min(root2));

	printf("[key�� search]\n");
	printf("Ʈ������ 15�� ���� : %d\n\n", search(root, 15));

	preorder(root);
	printf("\n");
	node_increase(root);
	preorder(root); //increase �Ǿ����� Ȯ��
	printf("\n\n");

	preorder(root2);
	printf("\n");
	node_increase(root2);
	preorder(root2); //increase �Ǿ����� Ȯ��
	printf("\n\n");
	

	printf("root�� root�� ������? : %s\n", equal(root, root) ? "����" : "�ٸ���");
	printf("root2�� root2�� ������? : %s\n", equal(root2, root2) ? "����" : "�ٸ���");
	printf("root�� root2�� ������? : %s\n\n", equal(root, root2) ? "����" : "�ٸ���");

	
	clone = copy(root) ;
	printf("root : ");
	preorder(root);
	printf("\n");
	printf("root�� ������ clone : ");
	preorder(clone) ;
	printf("\n");
}