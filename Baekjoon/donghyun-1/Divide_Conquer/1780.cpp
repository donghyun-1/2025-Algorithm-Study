// https://www.acmicpc.net/problem/1780
// 종이의 개수 (실버 2)
// 2025-06-25

#include <iostream>
#include <vector>

using namespace std;

int N;
int ans[3] = {0, 0, 0};
vector<vector<int>> board;

void input() {
    cin >> N;

    board.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}

bool check_board(int row, int col, int size) {
    int num = board[row][col];

    for (int i = row; i < row+size; i++) {
        for (int j = col; j < col+size; j++) {
            if (board[i][j] != num) 
                return false;
        }
    }

    return true;
}

void divide(int row, int col, int size) {
    if (check_board(row, col, size)) {
        if (board[row][col] == -1) ans[0]++;
        else if (board[row][col] == 0) ans[1]++;
        else if (board[row][col] == 1) ans[2]++;
    }
    else {
        int d_size = size / 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int nr = row + d_size * i;
                int nc = col + d_size * j;

                divide(nr, nc, d_size);
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    divide(0, 0, N);

    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];

    return 0;
}