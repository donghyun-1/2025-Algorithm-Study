// https://www.acmicpc.net/problem/5972
// 택배 배송 (골드 5)
// 2025-07-18

/* 
    <접근 방법>
    [1] 그래프, 가중치 입력

    [2] 다익스트라 사용해서 최소 비용 구하기, 출력
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<pii> graph[50001];
bool visited[50001];

void input() {
    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
}

int dijkstra(int src, int dst) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, src});   // 비용, 노드 순으로 저장

    while (!q.empty()) {
        pii curr = q.top();
        q.pop();

        if (visited[curr.second]) continue;
        visited[curr.second] = true;

        if (curr.second == dst) {
            return curr.first;
        }

        for (int i = 0; i < graph[curr.second].size(); i++) {
            pii next = graph[curr.second][i];
            if (visited[next.second]) continue;

            q.push({curr.first + next.first, next.second});
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    cout << dijkstra(1, N);

    return 0;
}