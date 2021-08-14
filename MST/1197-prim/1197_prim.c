//*백 준 에 서 안 돌 아 감*

//1197 최소 스패닝 트리 prim으로 풀어보기 
//Prim skeleton (우선순위큐-배열로 구현)
#include <stdio.h>
#include <stdlib.h>

#define INF 1000L
#define MAX_VERTICES 10010

int v, e;
int rst;

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][INF];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];


//최소 distance [v] 값을 갖는 정점을 반환
int get_min_vertex(int n) {
	int v = 0;

	for (int i = 1; i <= n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (int i = 1; i <= n;i++) {
		if (!selected[i] && (distance[i] < distance[v]))
			v = i;
	}
	return v;
}

void prim(GraphType* g, int s) { //s == start
	int u, v;

	for (u = 1; u <= g->n; u++)
		distance[u] = INF; // 모든 정점 삽입과 동시에 거리 초기화
	distance[s] = 0;
	for (int i = 0; i < g->n; i++) {
		selected[i + 1] = 0;
	}

	for (int i = 0; i < g->n; i++) {
		
		u = get_min_vertex(g->n); //가장 작은 distance를 가지는 정점을 꺼낸다.
		selected[u] = 1; //트리 집합에 새로운 정점 u가 추가됨
		if (distance[u] == INF)return; //비연결그래프일때

		for (v = 1; v <= g->n; v++) {
			if (g->weight[u][v] != INF) { //인접한 정점찾기 (0,1) 이 무한대면 인접정점이아님!
				if (!selected[v] && (g->weight[u][v] < distance[v]))
					distance[v] = g->weight[u][v];
			}
		}
	}
}
int result(GraphType* g) {
	for (int i = 1; i <= g->n;i++)
		rst += distance[i];
	return rst;
}
GraphType g;
int main(void)
{
	int start, end, weight;

	scanf_s("%d %d", &v, &e);
	g.n = v;

	for (int i = 1; i <= g.n; i++) {
		for (int j = 1; j <= g.n; j++) {
			g.weight[i][j] = INF;
		}
	}
	/*for (int i = 1; i <= g.n; i++) {
		for (int j = 1; j <= g.n; j++) {
			printf("%4d ", g.weight[i][j]);
		}
		printf("\n");
	}*/

	for (int i = 1; i <= e; i++) {
		scanf_s("%d %d %d", &start, &end, &weight);
		g.weight[start][end] = weight;
		g.weight[end][start] = weight;
	}
	/*for (int i = 1; i <= g.n; i++) {
		for (int j = 1; j <= g.n; j++) {
			printf("%4d ", g.weight[i][j]);
		}
		printf("\n");
	}*/

	prim(&g, 1);
	printf("%d", result(&g));

	return 0;
}
