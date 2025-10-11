// https://www.acmicpc.net/problem/4179
// 불! (골드 3)
// 2025-09-18

#include <iostream>
#include <queue>
#include <vector>

#define INF (~0U >> 2)

using namespace std;

struct Point {
	int row, col, cnt;
};

int R, C;
char board[1001][1001];
bool visited[1001][1001];
// bool fire_visited[1001][1001];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<Point> q;
vector<pair<int, int>> fire;
vector<vector<int>> fire_time;
pair<int, int> start;

void input() {
	cin >> R >> C;

	fire_time.resize(R, vector<int>(C, INF));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'F') {
				fire.push_back({i, j});
				fire_time[i][j] = 0;
			}
			else if (board[i][j] == 'J') {
				start = {i, j};
				visited[i][j] = true;
			}
		}
	}
}

void bfs() {
	for (int i = 0; i < fire.size(); i++) {
		q.push({fire[i].first, fire[i].second, 0});
		fire_time[fire[i].first][fire[i].second] = 0;
	}

	// 불 bfs
	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
			if (nr < 0 || nr > R-1 || nc < 0 || nc > C-1) continue;
			if (fire_time[nr][nc] < INF) continue;
			if (board[nr][nc] == '#') continue;

			// fire_visited[nr][nc] = true;
			fire_time[nr][nc] = curr.cnt+1;
			q.push({nr, nc, curr.cnt+1});
		}
	}

	q.push({start.first, start.second, 0});

	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		if (curr.row == R-1 || curr.col == C-1 || curr.row == 0 || curr.col == 0) {
			if (curr.cnt < fire_time[curr.row][curr.col]) {
				cout << curr.cnt + 1;
				return;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
			if (nr < 0 || nr > R-1 || nc < 0 || nc > C-1) continue;
			if (visited[nr][nc]) continue;
			if (board[nr][nc] == 'F' || board[nr][nc] == '#') continue;
			
			if (curr.cnt + 1 < fire_time[nr][nc]) {
				visited[nr][nc] = true;
				q.push({nr, nc, curr.cnt+1});
			}
		}
	}
	cout << "IMPOSSIBLE";
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