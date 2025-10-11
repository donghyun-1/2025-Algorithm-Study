// https://www.acmicpc.net/problem/2623
// 음악프로그램 (골드 3)
// 2025-10-08

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int pr[1001];
vector<int> graph[1001];
vector<int> ans;

void input() {
	cin >> N >> M;

	int t;
	for (int i = 0; i < M; i++) {
		cin >> t;

		int prev = 0;
		int curr = 0;
		for (int j = 0; j < t; j++) {
			if (j == 0) {
				cin >> prev;
				continue;
			}
			else {
				cin >> curr;
				pr[curr]++;		// pr[curr] = pr[prev] + 1;
				graph[prev].push_back(curr);

				prev = curr;
			}
		}
	}
}

void solve() {
	queue<int> q;

	// 초반 가수 push
	for (int i = 1; i <= N; i++) {
		if (pr[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (pr[curr] == 0) {
			ans.push_back(curr);
		}

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			pr[next]--;

			if (pr[next] == 0) {
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

	if (ans.size() != N) 
		cout << "0";
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}

	return 0;
}