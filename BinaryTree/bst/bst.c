//이진 탐색 트리
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
	else { //삭제할 key를 찾았으니 진짜 삭제 시작!
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

	printf("이진 탐색 트리 전위 순회 결과 \n");
	preorder_print(root);
	printf("\n\n");
	printf("이진 탐색 트리의 높이 : %d\n", get_height(root));
	printf("이진 탐색 트리의 노드 개수 : %d\n", node_count(root));
	printf("\n");

	printf("-----------------------------------------\n\n");

	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견하지 못함 \n");

	printf("\n-----------------------------------------\n");

	root = delete(root, 20);
	printf("\n이진 탐색트리에서 20을 삭제\n");
	preorder_print(root);
	printf("\n\n");

	printf("이진 탐색 트리의 높이 : %d\n", get_height(root));
	printf("이진 탐색 트리의 노드 개수 : %d\n", node_count(root));

	return 0;
}