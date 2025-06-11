// https://www.acmicpc.net/problem/1238
// 파티 (골드 3)
// 2025-06-11
// 풀이1 : 다익스트라 N번 실행 * 2

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000001

using namespace std;

typedef pair<int, int> pii;

int N, M, X;
vector<int> total_time;             // total_time[출발] = 시간;
vector<vector<pii>> graph;          // graph[출발][] = {도착, 시간}

void input() {
    cin >> N >> M >> X;

    total_time.resize(N+1);
    graph.resize(N+1);

    for (int i = 0; i < M; i++) {
        int s, e, t;
        cin >> s >> e >> t;

        graph[s].push_back({e, t});     
    }

}

int dijkstra(int start, int end) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> temp(N+1, INF);

    temp[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int curr_time = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();

        // 도착
        if (curr_node == end) return curr_time;

        // longer path
        if (temp[curr_node] < curr_time) continue;

        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_node = graph[curr_node][i].first;
            int next_time = graph[curr_node][i].second;

            if (temp[next_node] > curr_time + next_time) {
                temp[next_node] = curr_time + next_time;

                pq.push({temp[next_node], next_node});
            }
        }
    }
    
    return INF;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // student go
    for (int i = 1; i <= N; i++) {
        total_time[i] = dijkstra(i, X);
    }

    // student come-back
    for (int i = 1; i <= N; i++) {
        total_time[i] += dijkstra(X, i);
    }

    int max_time = *max_element(total_time.begin() + 1, total_time.end());
    
    cout << max_time;

    return 0;
}