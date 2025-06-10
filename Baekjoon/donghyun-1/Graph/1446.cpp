// https://www.acmicpc.net/problem/1446
// 지름길 (실버 1)
// 2025-06-10

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

void solve() {
    dist[0] = 0;

    for (int i = 0; i < D; i++) {
        // 1씩 이동
        dist[i + 1] = min(dist[i + 1], dist[i] + 1);

        for (int j = 0; j < road.size(); j++) {
            if (i == road[j].first) {
                int end = road[j].second.first;
                int d = road[j].second.second;

                dist[end] = min(dist[end], dist[i] + d);
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

    sort(road.begin(), road.end());

    solve();

    cout << dist[D];

    return 0;
}