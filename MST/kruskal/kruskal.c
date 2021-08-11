//1197 - 최소 스패닝 트리
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10010
#define MAX_EDGE 100001
#define INF 2147483648

int parent[MAX_VERTICES];
int v, e;
int edgeCnt;

void set_init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = -1;
	}
}

int set_find(int curr) {
	if (parent[curr] == -1)
		return curr; //curr이 부모노드일때(root)
	while (parent[curr] != -1)
		curr = parent[curr];
	return curr;
}

void set_union(int a, int b) {
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;
}

struct Edge { //간선을 나타내는 구조체
	int start, end, weight;
};
typedef struct GraphType {
	int n;
	struct Edge edges[MAX_EDGE];
}GraphType;

//그래프 초기화
void graph_init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX_EDGE; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}
//간선 삽입 연산 
void insert_edge(GraphType* g, int start, int end, int w, int cnt) {
	g->edges[cnt].start = start;
	g->edges[cnt].end = end;
	g->edges[cnt].weight = w;
}

//compare
int compare(const void* a, const void* b) {
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

//kruskal
int kruskal(GraphType* g) {
	int edge_accepted = 0; //현재까지 선택된 간선의 수
	int uset, vset, temp = 0;
	struct Edge edge;

	set_init(g->n);
	qsort(g->edges, edgeCnt, sizeof(struct Edge), compare);

	int i = 0;
	while (edge_accepted < (g->n - 1)) {
		edge = g->edges[i];
		uset = set_find(edge.start);
		vset = set_find(edge.end);

		if (uset != vset) {
			temp += edge.weight;
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}	
	return temp;
}

int main(void) {
	GraphType g;
	int start, end, weight;

	scanf_s("%d %d", &v, &e);
	g.n = v;

	edgeCnt = 0;
	for (int i = 0; i < e; i++) {
		scanf_s("%d %d %d", &start, &end, &weight);
		insert_edge(&g, start, end, weight, edgeCnt++);
	}

	printf("%d", kruskal(&g));

	return 0;
}