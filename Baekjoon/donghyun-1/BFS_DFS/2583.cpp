// https://www.acmicpc.net/problem/2583
// 영역 구하기 (실버 1)
// 2025-05-22

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
    int row, col;
};

int M, N;   // row, col;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> board;
vector<vector<bool>> visited;

// bfs
int bfs(int row, int col) {
    queue<Point> q;
    q.push({row, col});

    visited[row][col] = true;
    int area = 1;

    while(!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > M-1 || nc < 0 || nc > N-1) continue;
            if (visited[nr][nc]) continue;
            if (board[nr][nc] == 1) continue;

            area++;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return area;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    vector<int> ans;

    cin >> M >> N >> K;

    board.resize(M,vector<int>(N, 0));
    visited.resize(M, vector<bool>(N, false));

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        // 영역 채우기
        for (int row = M - x2; row < M - x1; row++) {
            for (int col = y1; col < y2; col++) {
                board[row][col] = 1;
            }
        }
    }

/*  
    // 색칠된 보드 확인 (Debug)
    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            cout << board[row][col] << " ";
        }
        cout << "\n";
    }
*/

    // 넓이 구하기 (bfs)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) continue;

            if (!visited[i][j]) {
                int area = bfs(i, j);
                ans.push_back(area);
            }
        }
    }

    // 출력
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}