//���� Ž�� Ʈ��
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a > b) ? a : b)
#define MIN(a,b) ((a < b) ? a : b)

typedef int element;
typedef struct TreeNode{
	element data;
	struct TreeNode* left, *right;
}TreeNode;

TreeNode* newNode(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert(TreeNode* t, int key) {
	if (t == NULL) return newNode(key);

	if (key < t->data)
		t->left = insert(t->left, key);
	else if (key > t->data)
		t->right = insert(t->right, key);

	return t;
}
TreeNode* get_Min(TreeNode* t) {
	TreeNode* temp = t;
	while (temp->left != NULL) temp = temp->left;
	return temp;
}
TreeNode* delete(TreeNode* t, int key) {
	TreeNode* temp;

	if (t == NULL)return NULL;

	if (key < t->data)
		t->left = delete(t->left, key);
	else if (key > t->data)
		t->right = delete(t->right, key);
	else { //������ key�� ã������ ��¥ ���� ����!
		//case 1, 2
		if (t->left == NULL) {
			TreeNode* temp = t->right;
			free(t);
			return temp;
		}
		else if (t->right == NULL) {
			TreeNode* temp = t->left;
			free(t);
			return temp;
		}
		//case 3
		TreeNode* temp = get_Min(t->right);
		t->data = temp->data;
		t->right = delete(t->right, temp->data);
	}
	return t;
}
TreeNode* search(TreeNode* t, int key) {
	if (t == NULL)return NULL;
	if (t->data == key)
		return t;
	else if (key < t->data)
		return  search(t->left, key);
	else
		return search(t->right, key);
}

void preorder_print(TreeNode* t) {
	if (t != NULL) {		
		printf("[%d] ", t->data);
		preorder_print(t->left);
		preorder_print(t->right);
	}
}
int get_height(TreeNode* t) {
	int height;

	if (t == NULL)return 0;
	if (t != NULL) {
		height = 1 + MAX(get_height(t->left), get_height(t->right));
	}
	return height;
}

int node_count(TreeNode* t) {
	int cnt = 0;
	if (t == NULL) return 0;
	if (t != NULL) {
		cnt = 1 + node_count(t->left) + node_count(t->right);
	}
	return cnt;
}

int main(void) {
	TreeNode* root = NULL;

	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 60);

	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	preorder_print(root);
	printf("\n\n");
	printf("���� Ž�� Ʈ���� ���� : %d\n", get_height(root));
	printf("���� Ž�� Ʈ���� ��� ���� : %d\n", node_count(root));
	printf("\n");

	printf("-----------------------------------------\n\n");

	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰����� ���� \n");

	printf("\n-----------------------------------------\n");

	root = delete(root, 20);
	printf("\n���� Ž��Ʈ������ 20�� ����\n");
	preorder_print(root);
	printf("\n\n");

	printf("���� Ž�� Ʈ���� ���� : %d\n", get_height(root));
	printf("���� Ž�� Ʈ���� ��� ���� : %d\n", node_count(root));

	return 0;
}