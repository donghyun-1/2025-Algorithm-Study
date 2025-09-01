// https://www.acmicpc.net/problem/10026
// 적록색약 (골드 5)
// 2025-09-01

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
char board[101][101];
bool visited[101][101];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Point {
    int row, col;
    char color;
};

void input() {
    cin >> N;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            board[i][j] = s[j];
        }
    }
}

void normal_bfs(int srcRow, int srcCol) {
    queue<Point> q;
    q.push({srcRow, srcCol, board[srcRow][srcCol]});
    visited[srcRow][srcCol] = true;

    while(!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
            if (visited[nr][nc]) continue;
            if (board[nr][nc] != curr.color) continue;

            visited[nr][nc] = true;
            q.push({nr, nc, curr.color});
        }
    }
}

void rg_bfs(int srcRow, int srcCol) {
    queue<Point> q;
    q.push({srcRow, srcCol, board[srcRow][srcCol]});
    visited[srcRow][srcCol] = true;

    while(!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
            if (visited[nr][nc]) continue;
            if (board[nr][nc] == 'B' && curr.color == 'R') continue;
            if (board[nr][nc] == 'B' && curr.color == 'G') continue;
            if (board[nr][nc] == 'R' && curr.color == 'B') continue;
            if (board[nr][nc] == 'G' && curr.color == 'B') continue;

            visited[nr][nc] = true;
            q.push({nr, nc, curr.color});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                normal_bfs(i, j);
                ans1++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                rg_bfs(i, j);
                ans2++;
            }
        }
    }

    cout << ans1 << " " << ans2;

    return 0;
}