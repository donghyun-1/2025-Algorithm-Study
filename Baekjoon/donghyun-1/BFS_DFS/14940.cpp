// https://www.acmicpc.net/problem/14940
// 쉬운 최단거리 (실버 1)
// 2025-05-21

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row, col, dst;
};

int n, m;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> board;
vector<vector<int>> ans;

void bfs(int srcRow, int srcCol) {
    bool visited[1001][1001] = { false };
    visited[srcRow][srcCol] = true;

    queue<Point> q;
    q.push({srcRow, srcCol, 0});

    while(!q.empty()) {
        Point curr = q.front();
        q.pop();

        ans[curr.row][curr.col] = curr.dst;

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > n-1 || nc < 0 || nc > m-1) continue;
            if (board[nr][nc] == 0) continue;
            if (visited[nr][nc]) continue;

            visited[nr][nc] = true;
            q.push({nr, nc, curr.dst + 1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    int srcRow, srcCol;
    board.resize(n, vector<int>(m));
    ans.resize(n, vector<int>(m, -1));

    // 보드 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (board[i][j] == 2) {
                srcRow = i;
                srcCol = j;
            }
            else if (board[i][j] == 0) {
                ans[i][j] = 0;
            }
        }
    }

    // bfs
    bfs(srcRow, srcCol);

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}