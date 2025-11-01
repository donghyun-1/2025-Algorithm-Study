// https://www.acmicpc.net/problem/10159
// 저울 (골드 4)
// 2025-10-27

#include <iostream>

using namespace std;

int N, M;
bool graph[101][101];

void input()
{
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a][b] = true;
	}
}

void floyd()
{
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++){
				// 연결 됐는지 확인
				graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	floyd();

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (!graph[i][j] && !graph[j][i]) cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}