//링크 표현법으로 생성된 이진트리
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
TreeNode m7 = { 28, NULL, NULL }; // 추가
TreeNode m4 = { 25, NULL, &m7 }; // 변경
TreeNode m5 = { 15, &m3, &m4 };
TreeNode m6 = { 15, &m2, &m5 };
TreeNode* root2 = &m6;

//비단말노드 count
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
	else if (t1 != NULL && t2 != NULL) { //이 조건 추가 !
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

//이진 트리에서 주어진 key 값을 갖는 노드들을 모두 찾아 해당 노드의 갯수를 반환
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

	printf("[non_leaf_node 개수]\n");
	printf("root : %d, root2 : %d\n\n", get_nonleaf_count(root),get_nonleaf_count(root2));
	
	printf("[one_leaf_node 개수]\n");
	printf("root : %d, root2 : %d\n\n", get_oneleaf_count(root), get_oneleaf_count(root2));

	printf("[two_leaf_node 개수]\n");
	printf("root : %d, root2 : %d\n\n", get_twoleaf_count(root), get_twoleaf_count(root2));

	printf("[MAX값을 갖는 노드]\n");
	printf("root : %d, root2 : %d\n\n", get_max(root), get_max(root2));

	printf("[MIN값을 갖는 노드]\n");
	printf("root : %d, root2 : %d\n\n", get_min(root), get_min(root2));

	printf("[key값 search]\n");
	printf("트리에서 15의 개수 : %d\n\n", search(root, 15));

	preorder(root);
	printf("\n");
	node_increase(root);
	preorder(root); //increase 되었는지 확인
	printf("\n\n");

	preorder(root2);
	printf("\n");
	node_increase(root2);
	preorder(root2); //increase 되었는지 확인
	printf("\n\n");
	

	printf("root와 root는 같은가? : %s\n", equal(root, root) ? "같다" : "다르다");
	printf("root2와 root2는 같은가? : %s\n", equal(root2, root2) ? "같다" : "다르다");
	printf("root와 root2는 같은가? : %s\n\n", equal(root, root2) ? "같다" : "다르다");

	
	clone = copy(root) ;
	printf("root : ");
	preorder(root);
	printf("\n");
	printf("root를 복제한 clone : ");
	preorder(clone) ;
	printf("\n");
}