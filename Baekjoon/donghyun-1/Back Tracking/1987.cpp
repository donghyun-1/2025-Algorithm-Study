// https://www.acmicpc.net/problem/1987
// 알파벳 (골드 4)
// 2025-07-28

/* 
    <접근 방법>
    [1] 
    보드 입력

    [2]
    dfs로 방향 탐색 + count
    백트래킹 사용해서 탐색하는 동안 사용한 알파벳 처리

    [3]
    최대 거리 출력
*/

#include <iostream>

using namespace std;

int R, C;
char board[21][21];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool used[26];
int ans = 0;

void input() {
    cin >> R >> C;

    string s;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) {
            board[i][j] = s[j];
        }
    }
}

void dfs(int row, int col, int cnt) {
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++) {
        int nr = row + D[i][0], nc = col + D[i][1];
        if (nr < 0 || nr > R-1 || nc < 0 || nc > C-1) continue;

        int idx = board[nr][nc] - 'A';
        if (!used[idx]) {   // 없으면
            used[idx] = true;
            dfs(nr, nc, cnt+1);
            used[idx] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    used[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << ans; 

    return 0;
}