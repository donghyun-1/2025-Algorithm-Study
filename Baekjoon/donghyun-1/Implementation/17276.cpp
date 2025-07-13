// https://www.acmicpc.net/problem/17276
// 배열 돌리기 (실버 1)
// 2025-07-12

/* 
    <접근 방법>
    [0]
    테스트 횟수 입력 받은 만큼 반복

    [1] 
    board 입력, 45도씩 몇 번 돌아야 하는지 구하기 (time)

    [2]
    board 크기와 같은 n*n 임시 보드(v) 생성
    주 대각선 -> 가운대 열로 옮기기
    가운대 열 -> 부 대각선으로 옮기기
    부 대각선 -> 가운대 행으로 옮기기
    가운대 행 -> 주 대각선으로 옮기기
    board에 임시 보드(v) copy 후 time만큼 반복
    
    [3]
    board 출력
*/

#include <iostream>
#include <vector>

using namespace std;

int T;
int n, rotation;
vector<vector<int>> board;

void input() {
    cin >> n >> rotation;

    board.clear();
    board.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
}

// 횟수 구하기
int rotation_time() {
    // 0도 이상 만들기
    while (rotation < 0) {
        rotation += 360;
    }

    // 360도 미만으로 만들기
    while (rotation >= 360) {
        rotation -= 360;
    }

    int time = rotation / 45;

    return time;
}

// 주 대각선 -> 가운대 열
void move_cross1(vector<vector<int>>& v) {
    for (int i = 0; i < n; i++) {
        v[i][n/2] = board[i][i];
    }
}

// 가운데 열 -> 부 대각선
void move_center1(vector<vector<int>>& v) {
    for (int i = 0; i < n; i++) {
        v[i][n-1-i] = board[i][n/2];
    }
}

// 부 대각선 -> 가운대 행
void move_cross2(vector<vector<int>>& v) {
    for (int i = 0; i < n; i++) {
        v[n/2][n-1-i] = board[i][n-1-i];
    }
}

// 가운대 행 -> 주 대각선
void move_center2(vector<vector<int>>& v) {
    for (int i = 0; i < n; i++) {
        v[i][i] = board[n/2][i];
    }
}

// 나머지 처리
void move_remainder(vector<vector<int>>& v) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0) {
                v[i][j] = board[i][j];
            }
        }
    }
}

void rotate45() {
    vector<vector<int>> v(n, vector<int>(n, 0));

    move_cross1(v);         // 주 대각선 -> 가운대 열
    move_center1(v);        // 가운데 열 -> 부 대각선
    move_cross2(v);         // 부 대각선 -> 가운대 행
    move_center2(v);        // 가운데 행 -> 주 대각선
    move_remainder(v);      // 나머지 처리

    board = v;
}

void print(vector<vector<int>> v) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int t = 0; t < T; t++) {
        input();

        // 횟수 구하기
        int time = rotation_time();

        // 45도씩 time번 돌기
        for (int i = 0; i < time; i++) {
            rotate45();
        }

        print(board);
    }

    return 0;
}