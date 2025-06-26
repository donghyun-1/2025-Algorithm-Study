// https://www.acmicpc.net/problem/1325
// 효율적인 해킹 (실버 1)
// 2025-06-27

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> cnt;

void input() {
    cin >> N >> M;

    graph.resize(N+1);
    cnt.resize(N+1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[b].push_back(a);
    }
}

void dfs(int node, int start) {
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int next_node = graph[node][i];

        if (visited[next_node]) continue;

        cnt[start]++;
        dfs(next_node, start);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 1; i <= N; i++) {
        visited.assign(N+1, false);
        dfs(i, i);
    }

    // 최댓값 출력
    int max_v = *max_element(cnt.begin(), cnt.end());

    for (int i = 1; i <= N; i++) {
        if (cnt[i] == max_v) {
            cout << i << " ";
        }
    }

    return 0;
}