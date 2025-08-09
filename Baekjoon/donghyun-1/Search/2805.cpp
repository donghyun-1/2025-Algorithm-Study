// https://www.acmicpc.net/problem/2805
// 나무 자르기 (실버 2)
// 2025-08-05

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;

void input() {
    cin >> N >> M;

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

    // 이분 탐색
    long long left = 0;
    long long right = *max_element(arr.begin(), arr.end());
    long long ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] > mid) {
                sum += (arr[i] - mid);
            }
        }

        if (sum >= M) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}