// https://www.acmicpc.net/problem/22945
// 팀 빌딩 (골드 4)
// 2025-10-25

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> arr;

void input()
{
	cin >> N;

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

	int left = 0;
	int right = N-1;
	int ans = 0;

	while (left <= right) {
		int ability = min(arr[left], arr[right]) * (right - left - 1);
		ans = max(ans, ability);

		if (arr[left] < arr[right]) {
			left++;
		}
		else if (arr[left] >= arr[right]) {
			right--;
		}
	}

	cout << ans;

	return 0;
}