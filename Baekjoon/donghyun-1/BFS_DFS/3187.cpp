// https://www.acmicpc.net/problem/3187
// 양치기 꿍 (실버 1)
// 2025-06-21

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row, col;
};

int R, C;
int total_sheep = 0;
int total_wolf = 0;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<char>> board;
vector<vector<bool>> visited;

void input() {
    cin >> R >> C;

    board.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];         // 늑대 = v, 양 = k
        }
    }
}

void bfs(int row, int col) {
    int sheep = 0;
    int wolf = 0;

    queue<Point> q;
    q.push({row, col});

    visited[row][col] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (board[curr.row][curr.col] == 'k') {
            sheep++;
        }
        else if (board[curr.row][curr.col] == 'v') {
            wolf++;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > R-1 || nc < 0 || nc > C-1) continue;
            if (board[nr][nc] == '#') continue;
            if (visited[nr][nc]) continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    if (sheep > wolf) {
        total_sheep += sheep;
    }
    else {
        total_wolf += wolf;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!visited[i][j] && board[i][j] != '#') {
                bfs(i, j);
            }
        }
    }

    cout << total_sheep << " " << total_wolf;

    return 0;
}