// https://www.acmicpc.net/problem/2630
// 색종이 만들기 (실버 2)
// 2025-10-02

#include <iostream>

using namespace std;

int N;
int board[129][129];
int w = 0;
int b = 0;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}

void div(int row, int col, int size) {
	bool onlyOne = true;
	bool onlyZero = true;

	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (board[i][j] == 1) {
				onlyZero = false;
			}

			if (board[i][j] == 0) {
				onlyOne = false;
			}
		}
	}

	if (onlyOne) {
		b++;
		return;
	}

	if (onlyZero) {
		w++;
		return;
	}

	div(row, col, size/2);
	div(row, col + size/2, size/2);
	div(row + size/2, col, size/2);
	div(row + size/2, col + size/2, size/2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	div(0, 0, N);

	cout << w << "\n" << b;

	return 0;
}