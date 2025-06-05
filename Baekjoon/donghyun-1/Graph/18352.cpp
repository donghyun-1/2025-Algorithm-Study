// https://www.acmicpc.net/problem/18352
// 특정 거리의 도시 찾기 (실버 2)
// 2025-06-05

#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 300001

using namespace std;

int N, M, K, X;
vector<vector<int>> graph;
vector<int> dist;

void input() {
    cin >> N >> M >> K >> X;

    graph.resize(N+1);
    dist.resize(N+1, -1);

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;

        graph[s].push_back(e);
    }
}

void bfs(int start) {
    queue<int> q;
    bool visited[MAX_N] = { false };
    
    dist[start] = 0;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];
            if (visited[next]) continue;

            visited[next] = true;
            dist[next] = dist[curr] + 1;
            
            q.push(next);
        }
    }
}

void print() {
    bool found = false;

    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            cout << i << "\n";
            found = true;
        }
    }

    if (!found) 
        cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    
    bfs(X);

    print();
    
    return 0;
}