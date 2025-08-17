// https://www.acmicpc.net/problem/1912
// 연속합 (실버 2)
// 2025-08-08

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<long long> dp(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        dp[i] = arr[i];     // 자기 자신만 추가한 경우
    }

    for (int i = 1; i < N; i++) {
        dp[i] = max(dp[i], dp[i-1] + arr[i]);
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}