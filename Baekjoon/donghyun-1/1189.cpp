// https://www.acmicpc.net/problem/1189
// 컴백홈 (실버 1)
// 2025-06-24

#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int row, col, dist;
};

int R, C, K;
int ans = 0;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<char>> board;

void input() {
    cin >> R >> C >> K;

    board.resize(R, vector<char>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
}

void dfs(Point curr, vector<vector<bool>>& visited) {
    if (curr.row == 0 && curr.col == C-1) {
        if (curr.dist == K) {
            ans++;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
        if (nr < 0 || nr > R-1 || nc < 0 || nc > C-1) continue;
        if (board[nr][nc] == 'T') continue;
        if (visited[nr][nc]) continue;

        visited[nr][nc] = true;
        dfs({nr, nc, curr.dist+1}, visited);
        visited[nr][nc] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    vector<vector<bool>> v;

    v.resize(R, vector<bool>(C));
    v[R-1][0] = true;

    dfs({R-1, 0, 1}, v);

    cout << ans;

    return 0;
}