//*�� �� �� �� �� �� �� ��*

//1197 �ּ� ���д� Ʈ�� prim���� Ǯ��� 
//Prim skeleton (�켱����ť-�迭�� ����)
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


//�ּ� distance [v] ���� ���� ������ ��ȯ
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
		distance[u] = INF; // ��� ���� ���԰� ���ÿ� �Ÿ� �ʱ�ȭ
	distance[s] = 0;
	for (int i = 0; i < g->n; i++) {
		selected[i + 1] = 0;
	}

	for (int i = 0; i < g->n; i++) {
		
		u = get_min_vertex(g->n); //���� ���� distance�� ������ ������ ������.
		selected[u] = 1; //Ʈ�� ���տ� ���ο� ���� u�� �߰���
		if (distance[u] == INF)return; //�񿬰�׷����϶�

		for (v = 1; v <= g->n; v++) {
			if (g->weight[u][v] != INF) { //������ ����ã�� (0,1) �� ���Ѵ�� ���������̾ƴ�!
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
