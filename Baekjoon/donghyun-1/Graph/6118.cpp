// https://www.acmicpc.net/problem/6118
// 숨바꼭질 (실버 1)
// 2025-07-03

/* 
    <접근 방법>
    [1]
    양방향 graph 입력
    
    [2]
    BFS 사용하여 시작 노드 1에서 다른 노드까지의 거리 구하기
    
    [3]
    가장 멀리 있는 노드 찾기
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<vector<int>> graph;
vector<int> dist;

void input() {
    cin >> N >> M;

    graph.resize(N+1);
    dist.resize(N+1, -1);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void bfs(int start) {
    queue<pii> q;
    q.push({start, 0});     // 노드, 거리

    vector<bool> visited(N+1, false);
    visited[start] = true;

    while (!q.empty()) {
        pii curr = q.front();
        q.pop();

        for (int i = 0; i < graph[curr.first].size(); i++) {
            int next_node = graph[curr.first][i];
            if (visited[next_node]) continue;

            visited[next_node] = true;
            dist[next_node] = curr.second+1;

            q.push({next_node, curr.second+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 양방향 graph 입력
    input();

    // 시작 노드 1에서 다른 노드까지의 거리 구하기
    bfs(1);
    
    // 가장 멀리 있는 노드 찾기
    int max_node = max_element(dist.begin(), dist.end()) - dist.begin();
    int max_dist = *max_element(dist.begin(), dist.end());

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == max_dist) cnt++;
    }

    cout << max_node << " " << max_dist << " " << cnt;

    return 0;
}