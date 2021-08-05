#include <stdio.h>
#include <stdlib.h>

#define row 30
#define col 30

int visited[row][col]; //방문시 1
int house_cnt;
int cnt[row * col / 2];

typedef struct GraphType {
	int n;
	int adj_mat[row][col];
}GraphType;

void dfs_mat(GraphType* g, int u, int v) {
	visited[u][v] = 1;
	cnt[house_cnt]++;

	if (g->adj_mat[u + 1][v] == 1 && visited[u + 1][v] == 0) //우
		dfs_mat(g, u + 1, v);
	if (g->adj_mat[u - 1][v] == 1 && visited[u - 1][v] == 0) //좌
		dfs_mat(g, u - 1, v);
	if (g->adj_mat[u][v + 1] == 1 && visited[u][v + 1] == 0) //상
		dfs_mat(g, u, v + 1);
	if (g->adj_mat[u][v - 1] == 1 && visited[u][v - 1] == 0) //하
		dfs_mat(g, u, v - 1);

	return;
}

void search_house(GraphType* g) {
	for (int i = 1; i <= g->n; i++) {
		for (int j = 1; j <= g->n; j++) {
			if (g->adj_mat[i][j] == 1 && visited[i][j] == 0) {
				house_cnt++;
				dfs_mat(g, i, j);				
			}
		}
	}
}

int main(void) {
	GraphType g;
	int N;//지도의 크기
	int v;//지도에 넣을 숫자

	scanf_s("%d", &N);
	g.n = N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf_s("%1d", &v);
			g.adj_mat[i][j] = v;

			if (v == 0)
				visited[i][j] = 1;
			else
				visited[i][j] = 0;
		}
	}

	search_house(&g);
	printf("%d\n", house_cnt);

	//정렬을 위한 코드
	int temp;
	for (int i = 1; i <= house_cnt - 1; i++) {
		for (int j = 1; j <= house_cnt- i; j++) {
			if (cnt[j] > cnt[j + 1]) {
				temp = cnt[j];
				cnt[j] = cnt[j + 1];
				cnt[j + 1] = temp;
			}
		}
	}

	for (int i = 1; i <= house_cnt; i++) {
		printf("%d\n", cnt[i]);
	}
}