// https://www.acmicpc.net/problem/1389
// 케빈 베이컨의 6단계 법칙 (실버 1)
// 2025-07-01

/* 
    <접근 방법>
    [1]
    양방향 graph 입력
    
    [2]
    BFS 사용하여 시작 노드에서 다른 노드까지 최단 거리 구하기
    
    [3]
    최솟값 인덱스 출력
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<vector<int>> graph;
vector<int> ans;

void input() {
    cin >> N >> M;

    graph.resize(N+1);
    ans.resize(N+1, 500000);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

// 최단 거리 구하기
void bfs(int start) {
    int total_dist = 0;
    vector<bool> visited(N+1, false);
    queue<pii> q;    // node, dist
    q.push({start, 1});

    visited[start] = true;

    while (!q.empty()) {
        pii curr = q.front();
        q.pop();

        for (int i = 0; i < graph[curr.first].size(); i++) {
            int next_node = graph[curr.first][i];
            if (visited[next_node]) continue;

            visited[next_node] = true;
            total_dist += curr.second;

            q.push({next_node, curr.second+1});
        }
    }
    ans[start] = total_dist;
}

int main()
{
    input();

    for (int i = 1; i <= N; i++) {
        bfs(i);
    }

    int min_idx = min_element(ans.begin(), ans.end()) - ans.begin();

    cout << min_idx;

    return 0;
}