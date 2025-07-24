// https://www.acmicpc.net/problem/1967
// 트리의 지름 (골드 4)
// 2025-07-24

/* 
    <접근 방법>
    [1] 
    양방향 그래프 입력

    [2]
    dfs 사용해서 노드 1에서 가장 먼 노드 A 구하기
    다시 dfs 사용해서 노드 A에서 가장 먼 노드 B 구하기

    A와 B의 거리가 곧 모든 경로들 중에서 가장 긴 것의 길이가 된다.
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> graph[10001];
bool visited[10001];
int maxNode, maxDist = 0;

void input() {
    cin >> n;

    int a, b, dist;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b >> dist;
        
        // 양방향 그래프 입력
        graph[a].push_back({dist, b});
        graph[b].push_back({dist, a});
    }
}

void dfs(int node, int dist) {
    visited[node] = true;

    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }

    for (int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i].second;
        int next_dist = graph[node][i].first;
        if (visited[next_node]) continue;

        dfs(next_node, dist+next_dist);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // 가장 먼 노드 구하기
    dfs(1, 0);

    // 가장 먼 노드에서 가장 먼 노드 구하기
    maxDist = 0;
    memset(visited, false, sizeof(visited));
    dfs(maxNode, 0);

    cout << maxDist;

    return 0;
}