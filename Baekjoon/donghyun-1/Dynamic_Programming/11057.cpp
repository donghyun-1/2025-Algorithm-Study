// https://www.acmicpc.net/problem/11057
// 오르막 수 (실버 1)
// 2025-05-15

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> dp(N+1, vector<int>(10));

    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] = 1;
        for (int j = 0; j <= 9; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 10007;
        }
    }

    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i]) % 10007;
    }

    cout << ans % 10007;

    return 0;
}