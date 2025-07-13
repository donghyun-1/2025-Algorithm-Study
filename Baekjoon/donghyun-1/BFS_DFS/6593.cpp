// https://www.acmicpc.net/problem/6593
// 상범 빌딩 (골드 5)
// 2025-07-13

/* 
    <접근 방법>
    [1] 
    L, R, C 입력, building 3차원으로 입력, 시작 좌표 기록
    L, R, C가 0이면 종료

    [2]
    BFS 사용해서 시작 지점으로부터 최단 거리로 탈출구 찾기 (동/서/남/북 + 상/하 방향 고려)
    (3차원 토마토 문제랑 비슷)
    
    [3]
    걸린 시간 출력
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int floor, row, col, minutes;
};

int L, R, C;
int srcFloor, srcRow, srcCol;
int D[6][3] = {{-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};
vector<vector<vector<char>>> building;

void building_input() {
    building.clear();
    building.resize(L, vector<vector<char>>(R, vector<char>(C)));

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cin >> building[i][j][k];

                if (building[i][j][k] == 'S') {
                    srcFloor = i;
                    srcRow = j;
                    srcCol = k;
                }
            }
        }
    }
}

int bfs(int floor, int row, int col, int minutes) {
    vector<vector<vector<bool>>> visited(L, vector<vector<bool>>(R, vector<bool>(C, false)));
    queue<Point> q;
    q.push({floor, row, col, minutes});

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (building[curr.floor][curr.row][curr.col] == 'E') {
            return curr.minutes;
        }

        for (int i = 0; i < 6; i++) {
            int nf = curr.floor + D[i][0], nr = curr.row + D[i][1], nc = curr.col + D[i][2];
            if (nf < 0 || nf > L-1 || nr < 0 || nr > R-1 || nc < 0 || nc > C-1) continue;
            if (visited[nf][nr][nc]) continue;
            if (building[nf][nr][nc] == '#') continue;

            visited[nf][nr][nc] = true;
            q.push({nf, nr, nc, curr.minutes+1});
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        building_input();

        int minutes = bfs(srcFloor, srcRow, srcCol, 0);

        // 결과 출력
        if (minutes == -1) {
            cout << "Trapped!\n";
        }
        else {
            cout << "Escaped in " << minutes << " minute(s).\n";
        }
    }

    return 0;
}