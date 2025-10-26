// https://www.acmicpc.net/problem/14284
// 간선 이어가기 2 (골드 5)
// 2025-10-26

#include <iostream>
#include <vector>
#include <queue>

#define MAX_DIST (~0U >> 2)

using namespace std;

typedef pair<int, int> pii;

int n, m, s, t;
vector<pii> graph[5001];
vector<int> dist;

void input()
{
	cin >> n >> m;

	dist.resize(n+1, MAX_DIST);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;

		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	cin >> s >> t;
}

void dijkstra(int start, int end) 
{
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<bool> visited(n+1, false);

	dist[start] = 0;
	pq.push({0, start});

	while (!pq.empty()) {
		pii curr = pq.top();
		pq.pop();

		if (visited[curr.second]) continue;
		visited[curr.second] = true;

		if (curr.second == end) {
			cout << dist[end];
			return;
		}

		for (int i = 0; i < graph[curr.second].size(); i++) {
			int next_node = graph[curr.second][i].first;
			int next_dist = graph[curr.second][i].second;

			if (dist[next_node] > dist[curr.second] + next_dist) {
				dist[next_node] = dist[curr.second] + next_dist;

				pq.push({dist[next_node], next_node});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	dijkstra(s, t);

	return 0;
}