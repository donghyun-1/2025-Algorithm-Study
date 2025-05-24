// https://www.acmicpc.net/problem/17086
// 아기 상어 2 (실버 2)
// 2025-05-24

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row, col, dst;
};

int N, M;
int D[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
vector<vector<int>> board;

void input() {
    cin >> N >> M;
    board.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
}

int bfs(int row, int col) {
    int ans = 100;
    queue<Point> q;
    q.push({row, col, 0});

    int visited[51][51] = { false };
    visited[row][col] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (board[curr.row][curr.col] == 1) {
            // 가장 가까운 상어
            ans = min(ans, curr.dst);
        }

        for (int i = 0; i < 8; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
            if (visited[nr][nc]) continue;
            
            visited[nr][nc] = true;
            q.push({nr, nc, curr.dst+1});
        }
    }
    return ans;
}

void simulation() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 안전거리 최댓값
            ans = max(ans, bfs(i, j));
        }
    }

    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    simulation();

    return 0;
}