// https://www.acmicpc.net/problem/1517
// 버블 소트 (플레티넘 5)
// 2025-10-29

#include <iostream>

using namespace std;

int N;
int arr[500001];
int tmp[500001];
long long ans = 0;

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void merge(int start, int end)
{
	long long cnt = 0;
	int mid = (start + end) / 2;
	int left = start;
	int right = mid + 1;
	int idx = start;

	while (left <= mid && right <= end) {
		if (arr[left] <= arr[right]) {
			tmp[idx++] = arr[left++];
			ans += cnt;
		}
		else {
			tmp[idx++] = arr[right++];
			cnt++;
		}
	}

	if (left > mid) {
		int s = right;
		while (s <= end) {
			tmp[idx++] = arr[s++];
			cnt++;
		}
	}
	else {
		int s = left;
		while (s <= mid) {
			tmp[idx++] = arr[s++];
			ans += cnt;
		}
	}

	for (int t = start; t <= end; t++)
		arr[t] = tmp[t];
}

void merge_sort(int start, int end)
{
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, end);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	merge_sort(0, N-1);

	cout << ans;

	return 0;
}