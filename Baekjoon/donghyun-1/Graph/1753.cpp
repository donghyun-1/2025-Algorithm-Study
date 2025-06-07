// https://www.acmicpc.net/problem/1753
// 최단경로 (골드 4)
// 2025-06-06

#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int V, E, K;
vector<vector<pii>> graph;
vector<int> dist;

void input() {
    cin >> V >> E >> K;
    
    graph.resize(V+1);
    dist.resize(V+1, INF);

    for (int i = 0; i < E; i++) {
        int s, e, dist;
        cin >> s >> e >> dist;

        graph[s].push_back({e, dist});
    }
}

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(V+1, false);
    dist[start] = 0;

    pq.push({0, start});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;

        for (int v = 0; v < graph[u].size(); v++) {
            int next_node = graph[u][v].first;
            int next_dist = graph[u][v].second;

            if (dist[next_node] > dist[u] + next_dist) {
                dist[next_node] = dist[u] + next_dist;

                pq.push({dist[next_node], next_node});
            }
        }
    }
}

void print() {
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    dijkstra(K);

    print();
    
    return 0;
}