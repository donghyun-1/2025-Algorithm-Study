// https://www.acmicpc.net/problem/9466
// 텀 프로젝트 (골드 3)
// 2025-11-03

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
vector<int> student;
vector<bool> group;
bool visited[100001];
int cnt = 0;

void input()
{
	cin >> n;
	
	group.clear();
	group.resize(n+1);
	student.resize(n+1);
	memset(visited, false, sizeof(visited));

	for (int i = 1; i <= n; i++) {
		cin >> student[i];
	}
}

void dfs(int node) {
	visited[node] = true;
	int next = student[node];

	if (!visited[next]) {
		dfs(next);
	}
	else if (!group[next]) {
		for (int i = next; i != node; i = student[i]) {
			cnt++;
		}
		cnt++;
	}
	group[node] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		input();

		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				dfs(i);
		}

		cout << n-cnt << "\n";
		cnt = 0;
	}

	return 0;
}