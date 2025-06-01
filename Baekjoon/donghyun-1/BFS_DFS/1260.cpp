// https://www.acmicpc.net/problem/1260
// DFS와 BFS (실버 2)
// 2025-06-01

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int v) {
    if (visited[v]) {
        return;
    }

    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < graph[v].size(); i++) {
        dfs(graph[v][i]);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);

    visited[v] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for (int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];

            if (visited[next]) continue;

            visited[next] = true;
            q.push(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, V;
    cin >> N >> M >> V;

    graph.resize(N+1);
    visited.resize(N+1, false);

    // 그래프 입력
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 정렬
    for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

    dfs(V);

    cout << "\n";
    visited.assign(N+1, false);

    bfs(V);

    return 0;
}