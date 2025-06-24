// https://www.acmicpc.net/problem/2075
// N번째 큰 수 (실버 3)
// 2025-05-26
// 정렬까지는 떠올림

#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 1501

using namespace std;

struct Compare {
    bool operator()(int a, int b) { // false면 a가 top, true면 b가 top
        return a > b;
    }
};

int board[MAX_N][MAX_N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    priority_queue<int, vector<int>, Compare> pq;   // minHeap

    cin >> N;

    // 보드 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // 우선순위 큐 (N개 먼저 넣기)
    for (int i = 0; i < N; i++) {
        pq.push(board[N-1][i]);
    }


    // 전부 탐색
    for (int i = N-2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] > pq.top()) {
                pq.pop();
                pq.push(board[i][j]);
            }
        }
    }

    cout << pq.top();

    return 0;
}