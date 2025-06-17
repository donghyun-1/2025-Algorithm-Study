// https://www.acmicpc.net/problem/7569
// 토마토 (골드 5)
// 2025-06-16

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int height, row, col, day;
};

queue<Point> q;

int ans = 0;
int N, M, H;
int D[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};    // 위, 아래, 앞, 뒤, 왼쪽, 오른쪽
vector<vector<vector<int>>> tomato;

void input() {
    bool t = true;

    cin >> M >> N >> H;
    
    tomato.resize(H, vector<vector<int>>(N, vector<int>(M)));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> tomato[i][j][k];

                if (tomato[i][j][k] == 1) {
                    q.push({i, j, k, 0});
                }

                if (tomato[i][j][k] == 0)
                    t = false;
            }
        }
    }

    // 이미 다 익어있음
    if (t) {
        cout << 0;
        exit(0);
    }
}

void bfs() {
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        ans = max(ans, curr.day);

        for (int i = 0; i < 6; i++) {
            int nh = curr.height + D[i][0], nr = curr.row + D[i][1], nc = curr.col + D[i][2];
            if (nh < 0 || nh > H-1 || nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
            if (tomato[nh][nr][nc] != 0) continue;

            tomato[nh][nr][nc] = 1;
            q.push({nh, nr, nc, curr.day+1});
        }
    }
}

bool tomato_check() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (tomato[i][j][k] == 0) {
                    return false;
                }
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

    if (tomato_check()) {     // 다 익음
        cout << ans;
    }
    else {                  // 안 익은거 있음
        cout << -1;
    }

    return 0;
}