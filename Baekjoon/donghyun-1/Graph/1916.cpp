// https://www.acmicpc.net/problem/1916
// 최소비용 구하기 (골드 5)
// 2025-09-02

#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;

typedef pair<int, int> pii;

int N, M, src, dst;
vector<vector<pii>> graph;
vector<int> dist;
bool visited[1001];

void input() {
    cin >> N >> M;

    graph.resize(N+1);
    dist.resize(N+1, INF);

    int start, end, w;
    for (int i = 0; i < M; i++) {
        cin >> start >> end >> w;
        
        graph[start].push_back({w, end});
    }

    cin >> src >> dst;
}

void dijkstra(int src, int dst) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int curr_node = pq.top().second;
        pq.pop();

        if (curr_node == dst) {
            cout << dist[curr_node];
            return;
        }

        if (visited[curr_node]) continue;

        visited[curr_node] = true;

        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_node = graph[curr_node][i].second;
            int next_w = graph[curr_node][i].first;

            if (dist[next_node] > dist[curr_node] + next_w) {
                dist[next_node] = dist[curr_node] + next_w;

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

    dijkstra(src, dst);

    return 0;
}