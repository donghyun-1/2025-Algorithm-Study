// https://www.acmicpc.net/problem/7576
// 토마토 (골드 5)
// 2025-06-14

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row, col, day;
};

int N, M, ans = -1;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> board;
queue<Point> q;

void input() {
    cin >> M >> N;

    board.resize(N, vector<int>(M));
    
    bool check = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];

            if (board[i][j] == 1) {
                q.push({i, j, 0});
            }

            if (board[i][j] == 0) {
                check = true;
            }
        }
    }

    // 이미 다 익음
    if (!check) {
        cout << 0;
        exit(0);
    }
}

void bfs() {
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        ans = max(ans, curr.day);

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
            if (board[nr][nc] != 0) continue;
            
            // 방문 처리 효과
            board[nr][nc] = 1;

            q.push({nr, nc, curr.day+1});
        }
    }
}

// 다 익었는지 확인
bool tomato_check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    bfs();

    if (tomato_check()) {
        cout << ans;
    }
    else {
        cout << -1;
    }
    
    return 0;
}