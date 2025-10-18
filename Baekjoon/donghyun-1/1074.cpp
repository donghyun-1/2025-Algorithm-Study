// https://www.acmicpc.net/problem/1074
// Z (골드 5)
// 2025-10-11

#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
int cnt = 0;

void div(int row, int col, int size) {
	if (size == 1) return;

	int half = size / 2;
	int area = half * half;

	// 더 줄여야되면
	if (r < row+half && c < col+half) {
		div(row, col, half);
	}
	// 우상
	else if (r < row+half && c >= col+half) {
		cnt += area;
		div(row, col + half, half);
	}
	// 좌하
	else if (r >= row + half && c < col + half) {
        cnt += area * 2;
        div(row + half, col, half);
    }
    // 우하
    else {
        cnt += area * 3;
        div(row + half, col + half, half);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	div(0, 0, 1 << N);
	cout << cnt;

	return 0;
}