// https://www.acmicpc.net/problem/1865
// 웜홀 (골드 3)
// 2025-11-05

#include <iostream>
#include <vector>

#define INF (~0U >> 2)

using namespace std;

typedef pair<int, int> pii;

int N, M, W;
vector<pii> graph[501];
int dist[501];

void input()
{
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
	}

	int S, E, T;
	cin >> N >> M >> W;

	// 도로
	for (int i = 0; i < M; i++) {
		cin >> S >> E >> T;

		graph[S].push_back({E, T});
		graph[E].push_back({S, T});
	}

	// 웜홀
	for (int i = 0; i < W; i++) {	
		cin >> S >> E >> T;
		graph[S].push_back({E, -T});
	}
}


bool bellmanFord()
{
    for (int i = 1; i <= N; i++) dist[i] = INF;
    dist[0] = 0;

    // N번 반복
    for (int i = 0; i < N; i++) {
        for (int u = 0; u <= N; u++) {
            for (auto &edge : graph[u]) {
                int v = edge.first;
                int cost = edge.second;
                if (dist[u] != INF && dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                    if (i == N - 1) 
						return true; // 마지막에 갱신 → 음수 사이클
                }
            }
        }
    }


    return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;

    while (TC--) {
        input();

        for (int i = 1; i <= N; i++)
            graph[0].push_back({i, 0});

        cout << (bellmanFord() ? "YES\n" : "NO\n");
    }

	return 0;
}