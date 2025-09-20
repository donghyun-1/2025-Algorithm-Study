// https://www.acmicpc.net/problem/2230
// 수 고르기 (골드 5)
// 2025-09-16

#include <iostream>
#include <vector>
#include <algorithm>

#define INF (~0U >> 2)

using namespace std;

int N, M;
vector<int> arr;

void input() {
	cin >> N >> M;

	int num;
	arr.resize(N);
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

	sort(arr.begin(), arr.end());

	int left = 0;
	int right = 0;
	int ans = INF;

	while (left <= right && right < N) {
		int sub = arr[right] - arr[left];

		if (sub >= M) {
			ans = min(ans, sub);
			left++;
		}
		else {
			right++;
		}
	}

	cout << ans;

	return 0;
}