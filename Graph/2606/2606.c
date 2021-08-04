//2606 - 바이러스
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1001
#define TRUE 1;
#define FALSE 0;

int visited[MAX_VERTICES]; //방문시 1

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;

void graph_init(GraphType* g) {
	int v;
	g->n = 1;
	for (v = 0; v < MAX_VERTICES; v++) {
		g->adj_list[v] = NULL;
	}
}

//정점 삽입 연산 
void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) //정점 개수 초과
		return;

	g->n++;
}

//간선 삽입 연산
void insert_edge(GraphType* g, int u, int v) {
	//노드 생성 
	GraphNode* node;
	GraphNode* p = g->adj_list[u];
	GraphNode* pre = NULL;
	int flag = 0;

	if (u >= g->n || v >= g->n) {
		return;
	}

	//u를 v에 매단다. insert_last
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;

	if (g->adj_list[u] == NULL) {//처음 insert
		node->link = g->adj_list[u];
		g->adj_list[u] = node;
	}

	else {
		while (p != NULL) {
			if (p->vertex > node->vertex) {
				flag = 1;
				break;
			}
			pre = p;
			p = p->link;
		}

		if (flag == 1) {//중간에 삽입해야함
			if (p == g->adj_list[u]) { //맨 첫자리에 삽입
				node->link = g->adj_list[u];
				g->adj_list[u] = node;
			}
			else {
				node->link = p;
				pre->link = node;
			}
		}
		else {
			node->link = NULL;
			pre->link = node;
		}
	}
}
int cnt = 0;
int dfs(GraphType* g, int v) {
	GraphNode* w;	
	visited[v] = TRUE;
	
	for (w = g->adj_list[v]; w != NULL; w = w->link) {
		if (!visited[w->vertex]) {
			dfs(g, w->vertex);
			cnt++;
		}
	}
	
	return cnt;
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p != NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}
void visited_init() {
	int i;
	for (i = 0; i < MAX_VERTICES; i++) {
		visited[i] = 0;
	}
}
int main(void) {
	GraphType g;
	int v, e;
	int u, w;
	graph_init(&g);

	scanf_s("%d", &v);
	scanf_s("%d", &e);
	for (int i = 0; i < v; i++) {
		insert_vertex(&g, i);
	}
	for (int i = 0; i < e; i++) {
		scanf_s("%d %d", &u, &w);
		insert_edge(&g, u, w);
		insert_edge(&g, w, u);
	}

	//print_adj_list(&g);
	visited_init();
	printf("%d", dfs(&g, 1));

}