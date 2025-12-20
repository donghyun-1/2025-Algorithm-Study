// https://www.acmicpc.net/problem/2473
// 세 용액 (골드 3)
// 2025-12-15 ~ 2025-12-19

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int arr[5001];

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr+N);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	int ans[3];
	long long sum = 0;
	long long min_num = 4000000000;

	for (int i = 0; i < N-2; i++) {
		int num1 = arr[i];

		int left = i+1;
		int right = N-1;

		while (left < right) {
			int num2 = arr[left];
			int num3 = arr[right];

			sum = (long long)num1 + num2 + num3;
			if (sum == 0) {
				ans[0] = num1;
				ans[1] = num2;
				ans[2] = num3;
				
				sort(ans, ans+3);
				cout << ans[0] << " " << ans[1] << " " << ans[2];
				return 0;
			} 
			
			if (llabs(sum) < llabs(min_num)) {
				min_num = llabs(sum);
				ans[0] = num1;
				ans[1] = num2;
				ans[2] = num3;
			}

			if (sum > 0) {
				right--;
			}
			else {
				left++;
			}
		}
	}

	sort(ans, ans+3);
	cout << ans[0] << " " << ans[1] << " " << ans[2]; 

	return 0;
}