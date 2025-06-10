// https://www.acmicpc.net/problem/1446
// 지름길 (실버 1)
// 2025-06-10
// 풀이2 : 다익스트라 (수정 중)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 10001

using namespace std;

typedef pair<int, pair<int, int>> pipii;
typedef pair<int, int> pii;

int N, D;
vector<int> dist;
vector<pipii> road;     // v[i] = {시작, {도착, 거리}}

void input() {
    cin >> N >> D;

    dist.resize(D+1, INF);

    for (int i = 0; i < N; i++) {
        int start, end, dist;
        cin >> start >> end >> dist;

        if (end - start <= dist) continue;      // 지름길 아님
        if (end > D) continue;

        road.push_back({start, {end, dist}});
    }
}

int dijkstra(int start, int end) {
    int curr_pos;
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 0});  // 거리, 위치

    while (!pq.empty()) {
        int curr_dist = pq.top().first;
        curr_pos = pq.top().second;
        pq.pop();

        if (dist[curr_pos] < curr_dist) continue;

        for (int i = 0; i < road.size(); i++) {
            if (road[i].first < curr_pos) continue;

            int next_pos = road[i].second.first;
            int next_dist = road[i].second.second + (road[i].first - curr_pos);

            if (dist[next_pos] > curr_dist + next_dist) {
                dist[next_pos] = curr_dist + next_dist;
            }

            pq.push({dist[next_pos], next_pos});
        }
    }

    return curr_pos;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    sort(road.begin(), road.end());

    int curr_pos = dijkstra(0, D);

    if (curr_pos == D) {
        cout << dist[curr_pos];
    }
    else {
        cout << D - curr_pos + dist[curr_pos];
    }

    return 0;
}