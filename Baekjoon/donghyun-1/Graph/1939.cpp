// https://www.acmicpc.net/problem/1939
// 중량제한 (골드 3)
// 2025-06-08

#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000001

using namespace std;

typedef pair<int, int> pii;

int N, M;
int d1, d2;
vector<vector<pii>> graph;
vector<int> dist;

void input() {
    cin >> N >> M;

    graph.resize(N+1);
    dist.resize(N+1, -1);       // 최대 무게

    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    cin >> d1 >> d2;
}

void dijkstra(int src, int dst) {
    priority_queue<pii> pq;
    pq.push({INF, src});

    dist[src] = INF;

    while (!pq.empty()) {
        int curr_w = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        // 이미 더 큰 값 찾음
        if (dist[curr_node] > curr_w) continue;

        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_w = graph[curr_node][i].first;
            int next_node = graph[curr_node][i].second;

            int w = min(curr_w, next_w);

            if (dist[next_node] < w) {
                dist[next_node] = w;

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

    dijkstra(d1, d2);

    cout << dist[d2];

    return 0;
}