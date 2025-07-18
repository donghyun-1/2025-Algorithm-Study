// https://www.acmicpc.net/problem/2206
// 벽 부수고 이동하기 (골드 3)
// 2025-07-16

/* 
    <접근 방법>
    [1] 
    board 입력

    [2]
    bfs 사용해서 최단거리 구하기
    이때, visited를 3차원으로 사용해서 벽 부수고 이동한 경로와 벽 안 부수고 이동한 경로를 구분해 줘야 함
    그리고 벽 부쉈는지를 나타내는 변수도 queue에 담아서 함께 push

    [3]
    거리 출력

    *추가 = vector를 사용하면 실행 속도가 느려지고 메모리 사용량도 많아지는 것을 확인함 (특히 3차원).
    정적 선언 사용하는 것이 더 효율적임
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row, col, dist, br;     // br == 0이면 벽 부순적 없다는 뜻
};

int N, M;
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[1001][1001][2];
int board[1001][1001];

void input() {
    cin >> N >> M;

    string s;

    // 보드 입력
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';
        }
    }
}

int bfs(int srcRow, int srcCol, int dstRow, int dstCol) {
    queue<Point> q;
    q.push({srcRow, srcCol, 1, 0});

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        // 도착
        if (curr.row == dstRow && curr.col == dstCol) {
            return curr.dist;
        }

        for (int i = 0; i < 4; i++) {
            int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
            if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;

            if (board[nr][nc] == 0 && !visited[nr][nc][curr.br]) {              // 벽이 아닐 경우
                visited[nr][nc][curr.br] = true;
                q.push({nr, nc, curr.dist + 1, curr.br});
            }
            else if (board[nr][nc] == 1 && !curr.br && !visited[nr][nc][1]) {   // 벽인데 아직 안 부쉈을 경우
                visited[nr][nc][1] = true;
                q.push({nr, nc, curr.dist + 1, 1});
            }
        }
    }

    return -1;  // 도착 불가
}


int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    cout << bfs(0, 0, N-1, M-1);

    return 0;
}