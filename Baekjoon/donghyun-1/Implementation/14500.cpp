// https://www.acmicpc.net/problem/14500
// 테트로미노 (골드 4)
// 2025-10-07

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int board[501][501];

int shape1[8][2] = {{0, 0}, {0, 1}, {0, 2}, {0, 3},
					{0, 0}, {1, 0}, {2, 0}, {3, 0}};

int shape2[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

int shape3[32][2] = {{0, 0}, {1, 0}, {2, 0}, {2, 1},
					{0, 0}, {0, 1}, {0, 2}, {-1, 2},
					{0, 0}, {0, 1}, {1, 1}, {2, 1},
					{0, 0}, {-1, 0}, {-1, 1}, {-1, 2},
					{0, 0}, {1, 0}, {2, 0}, {2, -1},
					{0, 0}, {0, 1}, {0, 2}, {1, 2},
					{0, 0}, {0, -1}, {1, -1}, {2, -1},
					{0, 0}, {1, 0}, {1, 1}, {1, 2}};

int shape4[16][2] = {{0, 0}, {1, 0}, {1, 1}, {2, 1},
					{0, 0}, {0, 1}, {-1, 1}, {-1, 2},
					{0, 0}, {1, 0}, {1, -1}, {2, -1},
					{0, 0}, {0, 1}, {1, 1}, {1, 2}};

int shape5[16][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 1},
					{0, 0}, {1, 0}, {2, 0}, {1, -1},
					{0, 0}, {0, 1}, {0, 2}, {-1, 1},
					{0, 0}, {1, 0}, {2, 0}, {1, 1}};

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}

int check_shape(int row, int col) {
	int cnt = 0;
	int temp;

	// 1번 도형
	for (int i = 0; i < 2; i++) {
		temp = 0;
		for (int j = 4*i; j < 4*i+4; j++) {
			int nr = row + shape1[j][0], nc = col + shape1[j][1];

			if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) break;
			temp += board[nr][nc];
		}
		cnt = max(cnt, temp);
	}

	// 2번 도형
	for (int i = 0; i < 1; i++) {
		temp = 0;
		for (int j = 4*i; j < 4*i+4; j++) {
			int nr = row + shape2[j][0], nc = col + shape2[j][1];

			if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) break;
			temp += board[nr][nc];
		}
		cnt = max(cnt, temp);
	}

	// 3번 도형
	for (int i = 0; i < 8; i++) {
		temp = 0;
		for (int j = 4*i; j < 4*i+4; j++) {
			int nr = row + shape3[j][0], nc = col + shape3[j][1];

			if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) break;
			temp += board[nr][nc];
		}
		cnt = max(cnt, temp);
	}

	// 4번 도형
	for (int i = 0; i < 4; i++) {
		temp = 0;
		for (int j = 4*i; j < 4*i+4; j++) {
			int nr = row + shape4[j][0], nc = col + shape4[j][1];

			if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) break;
			temp += board[nr][nc];
		}
		cnt = max(cnt, temp);
	}

	// 5번 도형
	for (int i = 0; i < 4; i++) {
		temp = 0;
		for (int j = 4*i; j < 4*i+4; j++) {
			int nr = row + shape5[j][0], nc = col + shape5[j][1];

			if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) break;
			temp += board[nr][nc];
		}
		cnt = max(cnt, temp);
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans = max(ans, check_shape(i, j));
		}
	}

	cout << ans;

	return 0;
}