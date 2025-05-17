// https://www.acmicpc.net/problem/15486
// 퇴사 2 (골드 5)
// 2025-05-17

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> dp(N+1, 0);

    int ans = 0;
    int curr_max = 0;

    // dp[n]는 n일차까지 일했을 때 받을 금액
    for (int i = 0; i < N; i++) {
        int day, price;
        cin >> day >> price;

        curr_max = max(curr_max, dp[i]);

        if (i + day <= N) {
            dp[i + day] = max(curr_max + price, dp[i + day]);   // ex) dp[3] = 10
            ans = max(ans, dp[i + day]);
        }
    }

    cout << ans;

    return 0;
}