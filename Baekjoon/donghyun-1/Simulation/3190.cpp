// https://www.acmicpc.net/problem/3190
// 뱀 (골드 4) 
// 2025-11-08

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Point {
	int row, col;
};

int N, K, L;
int board[101][101];
int D[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 	// 우, 좌, 하, 상
vector<pair<int, char>> dir;

void input()
{
	cin >> N >> K;

	int r, c;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		r--;
		c--;
		board[r][c] = 1;
	}

	// 방향
	cin >> L;
	int t;
	char ch;
	for (int i = 0; i < L; i++) {
		cin >> t >> ch;
		dir.push_back({t, ch});
	}
}

int turn(int d, char c) 
{
	if (c == 'L') {
		if (d == 0) return 3;
		if (d == 1) return 2;
		if (d == 2) return 0;
		if (d == 3) return 1;
	}

	if (c == 'D') {
		if (d == 0) return 2;
		if (d == 1) return 3;
		if (d == 2) return 1;
		if (d == 3) return 0;
	}
	return -1;
}

void move() 
{
	deque<Point> dq;
	dq.push_back({0, 0});
	int row = 0, col = 0;
	int d = 0;
	int time = 0;
	int idx = 0;
	board[row][col] = 2;

	while (1) {
		time++;

		int nr = row + D[d][0], nc = col + D[d][1];

		if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1 || board[nr][nc] == 2) {
			break;
		}
		else if (board[nr][nc] == 0) {
			board[nr][nc] = 2;
			board[dq.back().row][dq.back().col] = 0;
			dq.pop_back();
			dq.push_front({nr, nc});
		}
		// 사과
		else if (board[nr][nc] == 1) {
			board[nr][nc] = 2;
			dq.push_front({nr, nc});
		}

		if (idx < dir.size()) {
			if (time == dir[idx].first) {
				if (dir[idx].second == 'L') {
					d = turn(d, 'L');
				}
				else if (dir[idx].second == 'D') {
					d = turn(d, 'D');
				}
				idx++;
			}
		}
		row = nr;
		col = nc;
	}
	cout << time << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	move();

	return 0;
}