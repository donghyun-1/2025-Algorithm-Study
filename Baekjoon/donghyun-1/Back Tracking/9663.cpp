// https://www.acmicpc.net/problem/9663
// N-Queen (골드 4)
// 2025-10-04

#include <iostream>

using namespace std;

int N, cnt = 0;
bool col[15], diag1[30], diag2[30]; 
// col: 세로, diag1: ↘ 대각선(row+col), diag2: ↙ 대각선(row-col+N-1)

void bt(int row) {
    if (row == N) {
        cnt++;
        return;
    }

    for (int c = 0; c < N; c++) {
        if (col[c] || diag1[row+c] || diag2[row-c+N-1]) continue;

        col[c] = diag1[row+c] = diag2[row-c+N-1] = true;
        bt(row+1);
        col[c] = diag1[row+c] = diag2[row-c+N-1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;

    bt(0);
    
	cout << cnt;
    
	return 0;
}