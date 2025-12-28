// https://www.acmicpc.net/problem/2638
// 치즈 (골드 3)
// 2025-12-22 ~ 2025-12-26

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

struct Point {
	int row, col;
	bool stat;
};

int N, M, cheeseCount = 0;
int board[101][101];
int visited[101][101];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<Point> cheese;

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == 1) {
				cheese.push_back({i, j, true});
				cheeseCount++;
			}
		}
	}
}

void bfs(int row, int col)
{
	queue<pii> q;
	visited[row][col] = true;
	q.push({row, col});

	while (!q.empty()) {
		pii curr = q.front();
		q.pop();

		if (board[curr.first][curr.second] == 0) {
			board[curr.first][curr.second] = 2;
		}

		for (int i = 0; i < 4; i++) {
			int nr = curr.first + D[i][0], nc = curr.second + D[i][1];
			if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
			if (visited[nr][nc]) continue;
			if (board[nr][nc] == 1) continue;

			visited[nr][nc] = true;
			q.push({nr, nc});
		}
	}
}

bool checkCheese(int row, int col) {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int nr = row + D[i][0], nc = col + D[i][1];
		if (board[nr][nc] == 2) {
			cnt++;
		}
	}

	if (cnt >= 2) {
		board[row][col] = 0;
		cheeseCount--;
		return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;

	input();

	while (cheeseCount != 0) {
		memset(visited, 0, sizeof(visited));

		// 1. 공기 접촉 처리
		bfs(0, 0);

		// 2. 치즈 제거
		for (int i = 0; i < cheese.size(); i++) {
			if (cheese[i].stat) {
				cheese[i].stat = checkCheese(cheese[i].row, cheese[i].col);
			}
		}

		ans++;
	}

	cout << ans;

	return 0;
}