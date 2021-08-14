//Prim skeleton (�켱����ť-�迭�� ����)
#include <stdio.h>
#include <stdlib.h>

#define INF 1000L
#define MAX_VERTICES 100

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][INF];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];


//�ּ� distance [v] ���� ���� ������ ��ȯ
int get_min_vertex(int n) {
	int v = 0;

	GraphType g;
	for (int i = 0; i < n; i++) 
		if (!selected[i]) {
			v = i;
			break;
		}
	for (int i = 0; i < n;i++) {
		if (!selected[i] && (distance[i] < distance[v]))
			v = i;
	}
	return v;
}

void prim(GraphType* g, int s) { //s == start
	int u, v;

	for (u = 0; u < g->n; u++)
		distance[u] = INF; // ��� ���� ���԰� ���ÿ� �Ÿ� �ʱ�ȭ
	distance[s] = 0;

	for (int i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n); //���� ���� distance�� ������ ������ ������.
		selected[u] = 1; //Ʈ�� ���տ� ���ο� ���� u�� �߰���
		if (distance[u] == INF)return; //�񿬰�׷����϶�
		printf("���� %d �߰�\n", u);

		for (v = 0; v < g->n; v++) {
			if (g->weight[u][v] != INF) { //������ ����ã�� (0,1) �� ���Ѵ�� ���������̾ƴ�!
				if (!selected[v] && (g->weight[u][v] < distance[v]))
					distance[v] = g->weight[u][v];
			}
		}
	}
}
int main(void)
{
	GraphType g = { 7,
	{{ 0, 29, INF, INF, INF, 10, INF },
	{ 29, 0, 16, INF, INF, INF, 15 },
	{ INF, 16, 0, 12, INF, INF, INF },
	{ INF, INF, 12, 0, 22, INF, 18 },
	{ INF, INF, INF, 22, 0, 27, 25 },
	{ 10, INF, INF, INF, 27, 0, INF },
	{ INF, 15, INF, 18, 25, INF, 0 } }
	};
	prim(&g, 0);
	return 0;
}