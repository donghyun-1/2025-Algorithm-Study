// https://www.acmicpc.net/problem/1446
// 지름길 (실버 1)
// 2025-06-10
// 풀이2 : 다익스트라

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 10001

using namespace std;

typedef pair<int, int> pii;

int N, D;
vector<int> dist;
vector<vector<pii>> road;     // v[시작] = {도착, 거리}

void input() {
    cin >> N >> D;

    road.resize(D + 1);
    dist.resize(D + 1, INF);

    // 지름길 입력
    for (int i = 0; i < N; i++) {
        int start, end, dist;
        cin >> start >> end >> dist;

        // 지름길 아님
        if (end - start <= dist) continue;
        if (end > D) continue;

        road[start].push_back({end, dist});
    }

    // 1씩 이동
    for (int i = 0; i < D; i++) {
        road[i].push_back({i + 1, 1});
    }
}

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});  // 거리, 위치

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        int curr_pos = pq.top().second;
        pq.pop();

        // 이미 방문
        if (dist[curr_pos] < curr_dist) continue;

        for (int i = 0; i < road[curr_pos].size(); i++) {
            int next_pos = road[curr_pos][i].first;
            int next_dist = road[curr_pos][i].second;

            if (dist[next_pos] > curr_dist + next_dist) {
                dist[next_pos] = curr_dist + next_dist;

                // 갱신 될 때만 push
                pq.push({dist[next_pos], next_pos});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    dijkstra(0);

    cout << dist[D];

    return 0;
}