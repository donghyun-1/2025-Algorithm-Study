// https://www.acmicpc.net/problem/7562
// 나이트의 이동 (실버 1)
// 2025-09-05

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Point {
	int row, col, cnt;
};

int l;
int srcRow, srcCol, dstRow, dstCol;
bool visited[301][301];
int D[8][2] = {{-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void input() {
	cin >> l;
	cin >> srcRow >> srcCol >> dstRow >> dstCol;
}

void bfs(int srcRow, int srcCol, int dstRow, int dstCol) {
	queue<Point> q;
	q.push({srcRow, srcCol, 0});
	visited[srcRow][srcCol] = true;

	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		if (curr.row == dstRow && curr.col == dstCol) {
			cout << curr.cnt << "\n";
		}

		for (int i = 0; i < 8; i++) {
			int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
			if (nr < 0 || nr > l-1 || nc < 0 || nc > l-1) continue;
			if (visited[nr][nc]) continue;
			
			visited[nr][nc] = true;
			q.push({nr, nc, curr.cnt+1});
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		input();

		bfs(srcRow, srcCol, dstRow, dstCol);

		memset(visited, 0, sizeof(visited));
	}

	return 0;
}