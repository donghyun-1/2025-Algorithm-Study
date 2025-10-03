// https://www.acmicpc.net/problem/21736
// 헌내기는 친구가 필요해 (실버 2)
// 2025-10-01

#include <iostream>
#include <queue>

using namespace std;

struct Point {
	int row, col;
};

int N, M;
queue<Point> q;
char board[601][601];
bool visited[601][601];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void input() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'I') {
				q.push({i, j});
				visited[i][j] = true;
			}
		}
	}
}

void bfs() {
	int cnt = 0;

	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		if (board[curr.row][curr.col] == 'P') {
			cnt++;
		}

		for (int i = 0; i < 4; i++) {
			int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
			if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
			if (board[nr][nc] == 'X') continue;
			if (visited[nr][nc]) continue;

			visited[nr][nc] = true;
			q.push({nr, nc});
		}
	}
	
	if (cnt == 0) {
		cout << "TT";
	}
	else {
		cout << cnt;
	}
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	bfs();

	return 0;
}