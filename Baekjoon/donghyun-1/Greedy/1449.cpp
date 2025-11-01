// https://www.acmicpc.net/problem/1449
// 수리공 항승 (실버 3)
// 2025-10-31

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L;
vector<int> arr;

void input()
{
	cin >> N >> L;

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

	// 오름차순 정렬
	sort(arr.begin(), arr.end());


	int cnt = 1;
	float tape = arr[0] - 0.5;
	for (int i = 0; i < N; i++) {
		if (arr[i] + 0.5 <= tape + L) {
			continue;
		}
		else {
			tape = arr[i] - 0.5;
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}