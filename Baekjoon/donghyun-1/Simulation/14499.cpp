// https://www.acmicpc.net/problem/14499
// 주사위 굴리기 (골드 4)
// 2025-10-20

#include <iostream>
#include <queue>

using namespace std;

int dice[6] = {0, 0, 0, 0, 0, 0};
int board[21][21];
int N, M, x, y, K;
int D[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

struct Point {
	int row, col;
};

void input() {
	cin >> N >> M >> x >> y >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}

void roll_dice(int dir, int temp_dice[]) {
	if (dir == 1) {
		dice[0] = temp_dice[2];
		dice[1] = temp_dice[0];
		dice[2] = temp_dice[5];
		dice[3] = temp_dice[3];
		dice[4] = temp_dice[4];
		dice[5] = temp_dice[1];
	}
	else if (dir == 2) {
		dice[0] = temp_dice[1];
		dice[1] = temp_dice[5];
		dice[2] = temp_dice[0];
		dice[3] = temp_dice[3];
		dice[4] = temp_dice[4];
		dice[5] = temp_dice[2];	
	}
	else if (dir == 3) {
		dice[0] = temp_dice[4];
		dice[1] = temp_dice[1];
		dice[2] = temp_dice[2];
		dice[3] = temp_dice[0];
		dice[4] = temp_dice[5];
		dice[5] = temp_dice[3];
	}
	else if (dir == 4) {
		dice[0] = temp_dice[3];
		dice[1] = temp_dice[1];
		dice[2] = temp_dice[2];
		dice[3] = temp_dice[5];
		dice[4] = temp_dice[0];
		dice[5] = temp_dice[4];
	}
}

Point move(Point curr, int op) {
	int nr = curr.row + D[op-1][0], nc = curr.col + D[op-1][1];

	if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) return curr;

	int temp[6];
    for (int i = 0; i < 6; i++) temp[i] = dice[i];  // 원본 백업
    roll_dice(op, temp);  // 주사위 굴리기

	// 이동한 칸이 0인 경우
	if (board[nr][nc] == 0) {
		board[nr][nc] = dice[0];
	}
	else {
		dice[0] = board[nr][nc];
		board[nr][nc] = 0;
	}

	// 윗면 출력
	cout << dice[5] << "\n";
	return {nr, nc};
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	int op;
	Point p = {x, y};
	for (int i = 0; i < K; i++) {
		cin >> op;
		p = move(p, op);
	}
	
	return 0;
}