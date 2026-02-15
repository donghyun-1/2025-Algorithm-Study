// https://www.acmicpc.net/problem/16234
// 인구 이동 (골드 4)
// 2026-02-09 ~ 2026-02-13

#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    int row, col;
};

int N, L, R;
int country[51][51];
bool visited[51][51];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void input()
{
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> country[i][j];
        }
    }
}

bool bfs(int row, int col) 
{
    vector<Point> unions;
    queue<Point> q;

    q.push({row, col});
    visited[row][col] = true;
    unions.push_back({row, col});
    
    int sum = country[row][col];

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
            if (visited[nr][nc]) continue;
            int diff = abs(country[curr.row][curr.col] - country[nr][nc]);
            if (diff >= L && diff <= R) {
                visited[nr][nc] = true;
                q.push({nr, nc});
                unions.push_back({nr, nc});
                sum += country[nr][nc];
            }
        }
    }

    if (unions.size() == 1) return false;

    int avg = sum / (int)unions.size();
    for (int i = 0; i < unions.size(); i++) {
        country[unions[i].row][unions[i].col] = avg;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    int days = 0;
    while (1) {
        memset(visited, false, sizeof(visited));
        bool mv = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    if (bfs(i, j)) {
                        mv = true;
                    }
                }
            }
        }
        if (!mv) break;
        days++;
    }
    cout << days;

    return 0;
}