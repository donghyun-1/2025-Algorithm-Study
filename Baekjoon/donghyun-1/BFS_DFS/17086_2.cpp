// https://www.acmicpc.net/problem/17086
// 아기 상어 2 (실버 2)
// 2025-05-24

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row, col, dist;
};

int N, M;
int D[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
vector<vector<int>> board;
vector<vector<int>> dist;

void input() {
    cin >> N >> M;
    board.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
}

void bfs() {
    queue<Point> q;
    int visited[51][51] = { false };

    // 상어 위치부터 시작
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) {
                q.push({i, j, 0});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
            if (visited[nr][nc]) continue;
            if (dist[nr][nc] != -1) continue;
            
            visited[nr][nc] = true;
            dist[nr][nc] = curr.dist + 1;
            
            q.push({nr, nc, curr.dist+1});
        }
    }
}

void print() {
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans = max(ans, dist[i][j]);
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

    bfs();

    print();

    return 0;
}