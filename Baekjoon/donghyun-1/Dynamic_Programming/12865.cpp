// https://www.acmicpc.net/problem/12865
// 평범한 배낭 (골드 5)
// 2025-06-17

/*
    첫 번째 물건까지 고려했을 때 & 배낭 용량 0 ~ K 일 때
    두 번째 물건까지 고려했을 때 & 배낭 용량 0 ~ K 일 때
    ...
*/

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, K;
vector<pii> stuff;
vector<vector<int>> dp;

void input() {
    int W, V;

    cin >> N >> K;
    dp.resize(N+1, vector<int>(K+1, 0));    // dp[i번 째 물건][허용무게]

    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        
        stuff.push_back({W, V});
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 1; i <= N; i++) {
        int w = stuff[i-1].first;
        int v = stuff[i-1].second;

        for (int j = 1; j <= K; j++) {
            if (j >= w) {   // 물건 넣을 수 있을 때
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);   // 물건 넣기 전 vs 물건 넣은 후 비교
            }
            else {  // 물건 못 넣음
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N][K];

    return 0;
}