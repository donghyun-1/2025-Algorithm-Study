// https://www.acmicpc.net/problem/17835
// 면접보는 승범이네 (골드 2)
// 2025-06-09

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e18

using namespace std;

typedef pair<long long, int> plli;
typedef long long ll;

int N, M, K;
vector<vector<plli>> graph;
vector<int> place;
vector<ll> dist;

void input() {
    cin >> N >> M >> K;

    graph.resize(N+1);
    dist.resize(N+1, INF);

    for (int i = 0; i < M; i++) {
        int s, e, w;
        cin >> s >> e >> w;

        graph[e].push_back({w, s});
    }

    for (int i = 0; i < K; i++) {
        int k;
        cin >> k;

        place.push_back(k);
    }
}

// 가장 가까운 면접장 가야됨
void dijkstra() {
    priority_queue<plli, vector<plli>, greater<plli>> pq;

    for (int i = 0; i < place.size(); i++) {
        dist[place[i]] = 0;
        pq.push({0, place[i]});
    }

    while (!pq.empty()) {
        ll curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        // 이미 방문함
        if (dist[curr_node] < curr_dist) continue;

        for (int i = 0; i < graph[curr_node].size(); i++) {
            ll next_dist = graph[curr_node][i].first;
            int next_node = graph[curr_node][i].second;

            if (dist[next_node] > dist[curr_node] + next_dist) {
                dist[next_node] = dist[curr_node] + next_dist;

                pq.push({dist[next_node], next_node});
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

    dijkstra();

    ll max_v = *max_element(dist.begin() + 1, dist.end());
    int idx = max_element(dist.begin() + 1, dist.end()) - dist.begin();

    cout << idx << "\n" << max_v;

    return 0;
}