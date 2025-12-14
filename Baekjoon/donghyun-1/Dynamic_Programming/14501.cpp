// https://www.acmicpc.net/problem/14501
// 퇴사 (실버 3)
// 2025-10-12

#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[20];
vector<pair<int, int>> v;

void input()
{
	cin >> N;

	v.resize(N+2);

	int a, b;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b;
		v[i] = {a, b};
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	for (int i = 1; i <= N; i++) {
		if (i + v[i].first <= N+1) {
			dp[i + v[i].first] = max(dp[i + v[i].first], dp[i] + v[i].second);
		}
		dp[i + 1] = max(dp[i+1], dp[i]); 
	}

	cout << dp[N+1];

	return 0;
}