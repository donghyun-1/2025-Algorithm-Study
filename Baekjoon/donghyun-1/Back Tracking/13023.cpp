// https://www.acmicpc.net/problem/13023
// ABCDE (골드 5)
// 2025-07-11

/* 
    <접근 방법>
    [1] 
    양방향 그래프 입력

    [2]
    각 노드에서 DFS 돌면서 깊이가 5가 되는지 check
    깊이가 5면 check = 1; 아니면 0;
    return 할 때는 다음 경우의 수 check를 위해 다시 visited[node] = false 처리
    
    [3]
    check 출력
*/

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int check = 0;
vector<vector<int>> graph;
vector<bool> visited;

void input() {
    cin >> N >> M;

    graph.resize(N);
    visited.resize(N);

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        // 양방향 그래프
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void dfs(int node, int depth) {
    visited[node] = true;

    if (depth == 5) {
        check = 1;
        return;
    }

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (visited[next]) continue;

        dfs(next, depth+1);
    }

    visited[node] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 0; i < N; i++) {
        dfs(i, 1);

        if (check) break;
    }

    cout << check;

    return 0;
}