#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int board[51][51];
bool visited[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];   // 0 = 빈 칸, 1 = 벽
		}
	}

	// 방향: 0=북, 1=동, 2=남, 3=서
	// dx, dy 를 (동서남북) 순서로 선언해 두면
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1,  0 };

	int y = r, x = c, dir = d;
	int cleaned = 0;

	while (true) {
		// 1) 현재 칸 청소
		if (board[y][x] == 0 && !visited[y][x]) {
			visited[y][x] = true;
			cleaned++;
		}

		// 2) 네 방향 중 청소할 칸이 있는지 탐색
		bool moved = false;
		for (int i = 0; i < 4; i++) {
			// 반시계(왼쪽)로 90° 회전
			dir = (dir + 3) % 4;
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			// 범위 검사, 빈 칸이고 아직 청소 안 했으면 이동
			if (ny >= 0 && ny < N && nx >= 0 && nx < M
				&& board[ny][nx] == 0 && !visited[ny][nx]) {
				y = ny;
				x = nx;
				moved = true;
				break;
			}
		}
		if (moved) continue;

		// 3) 네 방향 모두 청소되었거나 벽이면 뒤로 한 칸 후진
		int back = (dir + 2) % 4;
		int by = y + dy[back];
		int bx = x + dx[back];
		// 뒤쪽이 벽이면 종료
		if (by < 0 || by >= N || bx < 0 || bx >= M || board[by][bx] == 1) {
			break;
		}
		// 후진만 하고 방향은 유지
		y = by;
		x = bx;
	}

	cout << cleaned << "\n";
	return 0;
}