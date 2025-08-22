// https://www.acmicpc.net/problem/1600
// 말이 되고픈 원숭이 (골드 3)
// 2025-08-21

#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int row, col, dist, jump;
};

int K, W, H;
int board[201][201];
bool visited[201][201][31];

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int D2[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};

void input() {
    cin >> K >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }
}

void bfs(int srcRow, int srcCol, int dstRow, int dstCol) {
    queue<Point> q;
    q.push({srcRow, srcCol, 0, K});
    visited[srcRow][srcCol][K] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.row == dstRow && curr.col == dstCol) {
            cout << curr.dist;
            return;
        }

        // 말 처럼 이동
        if (curr.jump > 0) {
            for (int i = 0; i < 8; i++) {
                int nr = curr.row + D2[i][0], nc = curr.col + D2[i][1];
                if (nr < 0 || nr > H-1 || nc < 0 || nc > W-1) continue;
                if (visited[nr][nc][curr.jump-1]) continue;
                if (board[nr][nc] == 1) continue;

                visited[nr][nc][curr.jump-1] = true;
                q.push({nr, nc, curr.dist+1, curr.jump-1});
            }
        }

        // 그냥 이동
        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > H-1 || nc < 0 || nc > W-1) continue;
            if (visited[nr][nc][curr.jump]) continue;
            if (board[nr][nc] == 1) continue;

            visited[nr][nc][curr.jump] = true;
            q.push({nr, nc, curr.dist+1, curr.jump});
        }
    }

    cout << -1;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    bfs(0, 0, H-1, W-1);

    return 0;
}