// https://www.acmicpc.net/problem/2839
// 설탕 배달 (실버 4)
// 2025-11-01

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int ans = 5000;
	for (int i = 0; i <= N/5; i++) {
		int temp = N - (5 * i);
		int cnt = i;
		
		if (temp % 3 == 0) {
			cnt += temp / 3;
			ans = min(ans, cnt);
		}
	}

	cout << (ans == 5000 ? -1 : ans);

	return 0;
}