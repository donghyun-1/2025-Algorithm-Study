// 푸는 중

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int src, dst;
vector<vector<pair<int, int>>> graph;

void input() {
    cin >> N >> M;
    
    graph.resize(N+1);

    for (int i = 0; i < M; i++) {
        int a, b, weight;
        cin >> a >> b >> weight;

        graph[a].push_back({weight, b});  // weight, node
        graph[b].push_back({weight, a});
    }

    cin >> src >> dst;
}

void dijkstra(int src, int dst) {
    priority_queue<pii> pq;
    vector<bool> visited(N+1, false);

    pq.push({0x7fff, src});

    while(!pq.empty()) {
        int curr_weight = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        if (visited[curr_node]) continue;
        visited[curr_node] = true;

        if (curr_node == dst) {
            cout << curr_weight;
            return;
        }

        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_weight = graph[curr_node][i].first;
            int next_node = graph[curr_node][i].second;

            int w = min(next_weight, curr_weight);

            pq.push({w, next_node});
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