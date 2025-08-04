// https://www.acmicpc.net/problem/11053
// 가장 긴 증가하는 부분 수열 (실버 2)
// 2025-08-02

#include <iostream>

using namespace std;

int num[1001];
int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 수열 입력
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    // dp 초기화
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            // i 이전 숫자 비교하기
            if (num[i] > num[j]) {
                // 이전 길이 + 1
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    // 최댓값 구하기
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}