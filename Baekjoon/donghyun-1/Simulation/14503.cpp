// https://www.acmicpc.net/problem/14503
// 로봇 청소기 (골드 5)
// 2025-05-19

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row, col, dir;
};

int N, M;
int D[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};   // 북, 동, 남, 서
vector<vector<int>> board;
int ans = 0;


void simulation(int row, int col, int dir) {
    queue<Point> q;
    q.push({row, col, dir});

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        // 청소하기
        if (board[curr.row][curr.col] == 0) {
            board[curr.row][curr.col] = 2;
            ans++;
        }

        for (int i = 0; i < 4; i++) {
            int ndir = (curr.dir + 3 - i) % 4;   // 반시계
            int nr = curr.row + D[ndir][0], nc = curr.col + D[ndir][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
            if (board[nr][nc] != 0) continue;

            // 청소하지 않은 빈칸 있으면
            q.push({nr, nc, ndir});
            break;
        }

        // 청소하지 않은 빈칸 없으면
        if (q.empty()) {
            int ndir = (curr.dir + 2) % 4;      // 후진
            int nr = curr.row + D[ndir][0], nc = curr.col + D[ndir][1];
            if (board[nr][nc] == 1) return;     // 벽이면 종료

            q.push({nr, nc, curr.dir});
        }
    }
}


int main()
{
    int r, c, dir;

    cin >> N >> M;
    cin >> r >> c >> dir;

    board.resize(N, vector<int>(M));

    // 보드 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    simulation(r, c, dir);

    cout << ans;

    return 0;
}