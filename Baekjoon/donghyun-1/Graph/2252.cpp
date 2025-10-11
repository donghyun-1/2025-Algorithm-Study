// https://www.acmicpc.net/problem/2252
// 줄 세우기 (골드 3)
// 2025-10-03

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[32001];
int priority[32001];

void input() {
	cin >> N >> M;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;

		graph[a].push_back(b);
		priority[b]++;
	}
}

void solve() {
	queue<int> q;

	// 앞에 있는 애들 먼저 push
	for (int i = 1; i <= N; i++) {
		if (priority[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		// 출력
		if (priority[curr] == 0) {
			cout << curr << " ";
		}

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			priority[next]--;

			if (priority[next] == 0) {
				q.push(next);
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
	
	solve();

	return 0;
}