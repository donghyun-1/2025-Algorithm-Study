// https://www.acmicpc.net/problem/1005
// ACM Craft (골드 3)
// 2025-11-12

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K, W;
vector<int> build_time;
vector<int> graph[1001];
vector<int> indegree;
vector<int> dp;

void input()
{
	int x, y;
	cin >> N >> K;

	build_time.assign(N+1, 0);
	indegree.resize(N+1);
	dp.resize(N+1);

	// graph 초기화
	for (int i = 1; i <= N; i++) {
		graph[i].clear();
	}

	// 건설 시간
	for (int i = 1; i <= N; i++) {
		cin >> build_time[i];
	}

	// 건설 순서
	for (int i = 0; i < K; i++) {
		cin >> x >> y;

		graph[x].push_back(y);
		indegree[y]++;
	}

	// 승리 조건
	cin >> W;
}

void BFS()
{
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			dp[i] = build_time[i];
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];
			dp[next] = max(dp[next], dp[curr] + build_time[next]);
			if (--indegree[next] == 0) {
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

	int T = 0;
	cin >> T;

	for (int t = 0; t < T; t++) {
		input();

		BFS();

		cout << dp[W] << "\n";

		indegree.clear();
		dp.clear();
	}

	return 0;
}