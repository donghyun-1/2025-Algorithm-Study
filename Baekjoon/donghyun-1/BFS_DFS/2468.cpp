// https://www.acmicpc.net/problem/2468
// 안전 영역 (실버 1)
// 2025-05-20

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int row, col;
};

int N;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> board;
vector<vector<bool>> visited;

void bfs(int row, int col, int height) {
    queue<Point> q;
    q.push({row, col});

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
            if (board[nr][nc] <= height) continue;
            if (visited[nr][nc]) continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int ans = 0;
    int max_height = 0;
    board.resize(N, vector<int>(N));

    // 보드 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] > max_height) {
                max_height = board[i][j];
            }
        }
    }

    // 높이별 bfs
    for (int i = 0; i <= max_height; i++) {
        int safe = 0;
        visited.assign(N, vector<bool>(N, false));

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (board[r][c] > i && !visited[r][c]) {
                    bfs(r, c, i);
                    safe++;
                }
            }
        }

        ans = max(safe, ans);
    }

    cout << ans;

    return 0;
}