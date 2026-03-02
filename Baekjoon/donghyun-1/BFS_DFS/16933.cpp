// https://www.acmicpc.net/problem/16933
// 벽 부수고 이동하기 3 (골드 1)
// 2025-12-29 ~ 2025-01-02

#include <iostream>
#include <queue>

using namespace std;

struct Point {
	int row, col, cnt, k;
	bool night;
};

int N, M, K;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int board[1001][1001];
bool visited[1001][1001][11][2];

void input()
{
	string s;

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			board[i][j] = s[j] - '0';
		}
	}
}

int bfs(int row, int col, int dest_row, int dest_col)
{
	queue<Point> q;
	q.push({row, col, 1, K, false});
	visited[row][col][K][0] = true;

	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		if (curr.row == dest_row && curr.col == dest_col) {
			return curr.cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
			if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
			
			// 벽 아닐 때
			if (board[nr][nc] == 0 && !visited[nr][nc][curr.k][!curr.night]) {
				visited[nr][nc][curr.k][!curr.night] = true;
				q.push({nr, nc, curr.cnt+1, curr.k, !curr.night});
			}
			// 벽 일 때
			else {
				// 낮일 때 벽 부수기 가능
				if (!curr.night && curr.k > 0 && !visited[nr][nc][curr.k-1][!curr.night]) {
					visited[nr][nc][curr.k-1][!curr.night] = true;
					q.push({nr, nc , curr.cnt+1, curr.k-1, !curr.night});
				}
				// 밤일 때는 제자리
				else if (curr.night && !visited[curr.row][curr.col][curr.k][!curr.night]) {
					visited[curr.row][curr.col][curr.k][!curr.night] = true;
					q.push({curr.row, curr.col , curr.cnt+1, curr.k, !curr.night});
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	cout << bfs(0, 0, N-1, M-1);

	return 0;
}