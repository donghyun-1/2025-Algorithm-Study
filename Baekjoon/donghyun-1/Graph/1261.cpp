// https://www.acmicpc.net/problem/1261
// 알고스팟 (골드 4)
// 2025-06-07

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Point {
    int row, col, wall;
};

int N, M;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> board;

void input() {
    cin >> M >> N;
    cin.ignore();   // 추가해야 getline 사용 가능

    board.resize(N+1, vector<int>(M+1));

    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);

        for (int j = 0; j < M; j++) {
            board[i+1][j+1] = s[j] - '0';
        }
    }
}

int bfs(int srcRow, int srcCol, int dstRow, int dstCol) {
    deque<Point> dq;
    bool visited[101][101] = { false };
    
    int cnt = 1000;
    dq.push_front({srcRow, srcCol, 0});
    visited[srcRow][srcCol] = true;
    
    while(!dq.empty()) {
        Point curr = dq.front();
        dq.pop_front();

        if (curr.row == dstRow && curr.col == dstCol) {
            return curr.wall;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr > N || nr < 1 || nc > M || nc < 1) continue;
            if (visited[nr][nc]) continue;
            
            visited[nr][nc] = true;

            if (board[nr][nc]) {
                dq.push_back({nr, nc, curr.wall + 1});
            }
            else {
                dq.push_front({nr, nc, curr.wall});
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    int ans = bfs(1, 1, N, M);

    cout << ans;

    return 0;
}