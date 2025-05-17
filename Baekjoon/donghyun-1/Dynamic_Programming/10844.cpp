// https://www.acmicpc.net/problem/10844
// 쉬운 계단 수 (실버 1)
// 2025-05-18

#include <iostream>

#define M 1000000000

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long long dp[101][10];    // dp[N][i]는 길이가 N 일 때 i로 시작하는 숫자 개수 (i = 0 ~ 9)
    
    // N = 1 일 때
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];

        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % M;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp[N][i];
    }

    cout << ans % M;

    return 0;
}