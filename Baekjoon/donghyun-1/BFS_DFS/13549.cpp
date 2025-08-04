// https://www.acmicpc.net/problem/13549
// 숨바꼭질 3 (골드 5)
// 2025-08-03

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K;
vector<int> dist(100001, -1);

void bfs() {
    deque<int> dq;
    dq.push_back(N);     // 현재 위치

    dist[N] = 0;

    while (!dq.empty()) {
        int curr = dq.front();
        dq.pop_front();

        // X * 2
        if (curr*2 <= 100000 && dist[curr*2] == -1) {
            dist[curr*2] = dist[curr];
            dq.push_front(curr*2);          // 앞에 넣기
        }

        // X - 1
        if (curr-1 >= 0 && dist[curr-1] == -1) {
            dist[curr-1] = dist[curr]+1;
            dq.push_back(curr-1);
        }

        // X + 1
        if (curr+1 <= 100000 && dist[curr+1] == -1) {
            dist[curr+1] = dist[curr]+1;
            dq.push_back(curr+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    bfs();

    cout << dist[K];

    return 0;
}