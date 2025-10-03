// https://www.acmicpc.net/problem/1992
// 쿼드트리 (실버 1)
// 2025-09-30

#include <iostream>

using namespace std;

int N;
int board[65][65];

void input() {
	cin >> N;

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < N; j++) {
			board[i][j] = s[j] - '0';
		}
	}
}

void dfs(int row, int col, int size) {
	// 크기가 1일 때
	if (size == 1) {
		cout << board[row][col];
		return;
	}

	// 0, 1만 있는지 check
	bool onlyZero = true, onlyOne = true;
	for (int i = row; i < row + size; i++) {
		for (int j = col; j < col + size; j++) {
			if (board[i][j] == 0) onlyOne = false;
			if (board[i][j] == 1) onlyZero = false;
		}
	}

	if (onlyZero) {
		cout << 0;
		return;
	}

	if (onlyOne) {
		cout << 1;
		return;
	}

	cout << "(";
	dfs(row, col, size/2);
	dfs(row, col + size/2, size/2);
	dfs(row + size/2, col, size/2);
	dfs(row + size/2, col + size/2, size/2);
	cout << ")";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	dfs(0, 0, N);

	return 0;
}