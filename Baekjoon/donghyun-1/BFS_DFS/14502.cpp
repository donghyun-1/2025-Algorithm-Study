// https://www.acmicpc.net/problem/14502
// 연구소 (골드 4)
// 2025-10-24

#include <iostream>
#include <queue>

using namespace std;

struct Point {
	int row, col;
};

int N, M, ans = 0;
int board[9][9];
int temp[9][9];
bool visited[9][9];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<Point> q;


void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}

void bfs()
{
	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
			if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
			if (visited[nr][nc]) continue;
			if (temp[nr][nc] != 0) continue;

			temp[nr][nc] = 2;
			visited[nr][nc] = true;
			q.push({nr, nc});
		}
	}
	
	// 안전구역 count
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) cnt++;
		}
	}

	ans = max(ans, cnt);
}

void wall(int wall_cnt)
{
	if (wall_cnt == 3) {
		// 보드 복사
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				temp[i][j] = board[i][j];
			}
		}

		// queue 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 2) {
					q.push({i, j});
				}
			}
		}

		// visited 초기화
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
			}
		}

		bfs();
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				board[i][j] = 1;
				wall(wall_cnt+1);
				board[i][j] = 0;
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

	// 벽 3개 세우기
	wall(0);

	cout << ans;

	return 0;
}