// https://www.acmicpc.net/problem/15989
// 1, 2, 3 더하기 4 (골드 5)
// 2025-05-16

#include <iostream>

#define MAX 10001

using namespace std;

int main()
{
    int T;
    cin >> T;

    int dp[MAX][4];
    dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;       
    dp[2][1] = 1; dp[2][2] = 1; dp[2][3] = 0;       
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;       

    for (int i = 4; i < MAX; i++) {
        dp[i][1] = 1;                                                   // i를 1로 만드는 경우 (무조건 1개)
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];                         // i를 1, 2로 만드는 경우 (뒤에 2을 붙힘)
        dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];          // i를 1, 2, 3으로 만드는 경우 (뒤에 3을 붙힘)
    }

    while (T--) {
        int n;
        cin >> n;

        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }

    return 0;
}