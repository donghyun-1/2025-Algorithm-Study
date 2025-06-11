// https://www.acmicpc.net/problem/1238
// 파티 (골드 3)
// 2025-06-11
// 풀이2 : 역방향 그래프 활용 (ex.백준 17835번: 면접보는 승범이네)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000001

using namespace std;

typedef pair<int, int> pii;

int N, M, X;
vector<int> city_to_party;
vector<int> party_to_city;
vector<int> total_time;
vector<vector<pii>> graph;                  // graph[출발][i] = {도착, 시간}
vector<vector<pii>> reverse_graph;          // graph[도착][i] = {출발, 시간}

void input() {
    cin >> N >> M >> X;

    total_time.resize(N+1);
    graph.resize(N+1);
    reverse_graph.resize(N+1);

    for (int i = 0; i < M; i++) {
        int s, e, t;
        cin >> s >> e >> t;

        graph[s].push_back({e, t});
        reverse_graph[e].push_back({s, t});
    }

}

vector<int> dijkstra(int start, vector<vector<pii>>& g) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> temp(N+1, INF);

    temp[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int curr_time = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        // longer path
        if (temp[curr_node] < curr_time) continue;

        for (int i = 0; i < g[curr_node].size(); i++) {
            int next_node = g[curr_node][i].first;
            int next_time = g[curr_node][i].second;

            if (temp[next_node] > curr_time + next_time) {
                temp[next_node] = curr_time + next_time;

                pq.push({temp[next_node], next_node});
            }
        }
    }
    
    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // 도시에서 파티까지 시간 저장
    city_to_party = dijkstra(X, reverse_graph);

    // 파티에서 도시까지 시간 저장
    party_to_city = dijkstra(X, graph);

    // 전체 왕복 시간
    for (int i = 1; i <= N; i++) {
        total_time[i] = city_to_party[i] + party_to_city[i];
    }

    // 최댓값
    int max_time = *max_element(total_time.begin() + 1, total_time.end());
    
    // 출력
    cout << max_time;

    return 0;
}