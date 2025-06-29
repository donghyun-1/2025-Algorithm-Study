// https://www.acmicpc.net/problem/1149
// RGB거리 (실버 1)
// 2025-06-28

/* 
    <접근 방법>

    1.
    cost[i][3]에 i번째 집을 칠하는 RGB 비용을 저장
    dp[i][3]에는 i번째 집을 R/G/B로 칠했을 때 드는 누적 비용 저장

    2.
    첫 번째 집부터 N 번째 집까지 계산
    ex) dp[i][0]은 i번째 집을 R로 칠할 때 드는 비용이므로 i-1번째 집을 G 또는 B로 칠해야 함
    
    따라서, dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0]

    3.
    N번 째 집을 R/G/B로 칠했을 때 가장 최소 비용 출력
    min(dp[N][0], min(dp[N][1], dp[N][2]));
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> cost;
vector<vector<int>> dp;

void input() {
    cin >> N;

    cost.resize(N+1, vector<int>(3));       // 칠하는 비용
    dp.resize(N+1, vector<int>(3));         // dp[i][0] = i번 째 집을 빨간색으로 dp[i][1] = 초록색 dp[i][2] = 파란색

    for (int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    for (int i = 2; i <= N; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
    }

    cout << min(dp[N][0], min(dp[N][1], dp[N][2]));

    return 0;
}