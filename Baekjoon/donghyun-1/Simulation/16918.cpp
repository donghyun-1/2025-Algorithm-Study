// https://www.acmicpc.net/problem/16918
// 봄버맨 (실버 1)
// 2025-06-30

/* 
    <접근 방법>
    [1] 입력
    벡터 board에 pair<int, char> 형태로 {현재 second, 폭탄 여부}를 입력
    
    [2] 1초 추가 + 빈칸에 폭탄 놓기 (3번 과정)
    addSecond(): board 순회하면서 폭탄 time 1초 씩 늘리고
    addBomb(): '.' -> 'O'로 변경
    
    [3] 1초 추가 + 3초 된 폭탄 터트리기 (4번 과정)
    addSecond(): board 순회하면서 폭탄 time 1초 씩 늘리고 
    selectBomb(): 3초 됐을 시 queue에 폭탄 위치 push
    explosion(): queue 전부 비울 때까지 폭탄 터트리기

    [4] 출력
    N초 됐을 시 출력
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int row, col;
};

int R, C, N;
vector<vector<pair<int, char>>> board;
queue<Point> bomb;             // 터트릴 폭탄
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void input() {
    cin >> R >> C >> N;

    board.resize(R, vector<pair<int, char>>(C));

    char c;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> c;

            if (c == 'O')
                board[i][j] = {1, c};
            else if (c == '.')
                board[i][j] = {0, c};
        }
    }
}

// 폭탄 전부 1초 +
void addSecond() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j].second == 'O')
                board[i][j].first++;
        }
    }
}

// 빈칸에 폭탄 설치
void addBomb() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j].second == '.') {
                board[i][j].first = 0;
                board[i][j].second = 'O';
            }
        }
    }
}

// 3초 된 폭탄 선택
void selectBomb() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j].first == 3 && board[i][j].second == 'O')
                bomb.push({i, j});
        }
    }
}

// 폭탄 터트리기
void explosion() {
    while (!bomb.empty()) {
        Point curr_bomb = bomb.front();
        bomb.pop();

        // 현재 위치 터트리기
        board[curr_bomb.row][curr_bomb.col].first = 0;
        board[curr_bomb.row][curr_bomb.col].second = '.';

        for (int i = 0; i < 4; i++) {
            int nr = curr_bomb.row + D[i][0], nc = curr_bomb.col + D[i][1];
            if (nr < 0 || nr > R-1 || nc < 0 || nc > C-1) continue;

            board[nr][nc].first = 0;
            board[nr][nc].second = '.';
        }
    }
}

void simulation() {
    int curr_time = 1;

    while (curr_time != N) {
        // + 1초, 빈칸에 폭탄 설치
        curr_time++;
        addSecond();
        addBomb();

        if (curr_time == N) break;
        
        // + 1초, 3초 된 폭탄 터트리기
        curr_time++;
        addSecond();
        selectBomb();
        explosion();
    }
}

void print_result() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << board[i][j].second;
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    simulation();

    print_result();

    return 0;
}