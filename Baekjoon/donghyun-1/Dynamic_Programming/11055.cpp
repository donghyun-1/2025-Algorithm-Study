// https://www.acmicpc.net/problem/11055
// 가장 큰 증가하는 부분 수열 (실버 2)
// 2025-11-07

#include <iostream>

using namespace std;

int N;
int arr[1001];
int dp[1001];

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	int max = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = arr[i];

		for (int j = 0; j < N; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) {
				dp[i] = dp[j] + arr[i];
			} 
		}
		if (max < dp[i]) max = dp[i];
	}

	cout << max;

	return 0;
}