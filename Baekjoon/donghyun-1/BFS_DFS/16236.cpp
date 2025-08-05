// https://www.acmicpc.net/problem/16236
// 아기 상어 (골드 3)
// 2025-08-04

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Point {
    int row, col, dist;

    // priority_queue는 max_heap이라 부등호 반대로
    bool operator<(const Point& other) const {
        if (dist != other.dist) return dist > other.dist;       // 거리순
        if (row != other.row) return row > other.row;           // 상위순
        return col > other.col;                                 // 왼쪽순
    }
};

int N;
int D[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};     // 상, 좌, 우, 하
int board[21][21];
bool visited[21][21];

int shark_size = 2;
int fish_cnt = 0;
int total_second = 0;
Point shark_pos;                        // 상어 현재 위치

bool bfs() {
    queue<Point> q;                     // 이동 할 좌표 저장
    priority_queue<Point> fish_q;       // eat 가능한 물고기 좌표 저장
    memset(visited, false, sizeof(visited));

    q.push({shark_pos.row, shark_pos.col, shark_pos.dist});
    visited[shark_pos.row][shark_pos.col] = true;

    // 먹을 수 있는 물고기 bfs로 찾기기
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];

            if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
            if (visited[nr][nc]) continue;
            if (board[nr][nc] > shark_size) continue;

            visited[nr][nc] = true;
            q.push({nr, nc, curr.dist + 1});

            // 먹을 수 있는 물고기 추가
            if (board[nr][nc] != 0 && board[nr][nc] < shark_size) {
                fish_q.push({nr, nc, curr.dist + 1});
            }
        }
    }

    // 물고기 없음 -> 종료
    if (fish_q.empty()) return false;

    // 물고기 있음 -> 가장 가까운 물고기 먹기
    Point target = fish_q.top();

    board[target.row][target.col] = 0;  // 먹음
    fish_cnt++;                         // 물고기 + 1
    total_second += target.dist;        // 거리+
    shark_pos = {target.row, target.col, 0};    // 상어 위치 업데이트

    if (shark_size == fish_cnt) {       // 상어 size 업
        shark_size++;
        fish_cnt = 0;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    // 물고기 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];

            if (board[i][j] == 9) {
                shark_pos = {i, j, 0};  // 상어 시작 위치
                board[i][j] = 0;
            }
        }
    }

    while (bfs());

    cout << total_second;

    return 0;
}