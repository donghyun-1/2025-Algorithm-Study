// https://www.acmicpc.net/problem/15900
// 나무 탈출 (실버 1)
// 2025-07-25

/* 
    <접근 방법>
    [1] 
    양방향 그래프 입력

    [2]
    bfs 사용해서 루트 노드 1에서 모든 노드 거리 구하기 (dist[i]에 거리 저장)
    그 중 모든 리프 노드까지의 거리를 total 변수에 저장 (graph[i]의 size가 1이면 리프 노드)

    [3]
    만약 total 거리가 짝수면 상대방 차례에 끝나기 때문에 "No" 출력
    홀수면 "Yes" 출력
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> graph[500001];
int dist[500001];

void input() {
    cin >> N;

    int a, b;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;

        // 양방향 그래프 입력
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void bfs(int node) {
    queue<pair<int, int>> q;
    q.push({node, 0});

    while (!q.empty()) {
        int curr_node = q.front().first;
        int curr_dist = q.front().second;
        q.pop();

        for (int i = 0; i < graph[curr_node].size(); i++) {
            int next_node = graph[curr_node][i];
            if (dist[next_node] != 0) continue;

            dist[next_node] = curr_dist + 1;
            q.push({next_node, curr_dist+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // 루트 노드 1에서 모든 거리 구하기
    bfs(1);

    // 루트 노드에서 리프 노드까지 거리 합 구하기
    int total = 0;
    for (int i = 1; i <= N; i++) {
        if (graph[i].size() == 1) {
            total += dist[i];
        }
    }

    // 짝수면 No 홀수면 Yes
    if (total % 2 == 0) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }

    return 0;
}