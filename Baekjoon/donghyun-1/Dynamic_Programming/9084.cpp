// https://www.acmicpc.net/problem/9084
// 동전 (골드 5)
// 2025-06-19

#include <iostream>
#include <vector>

using namespace std;

vector<int> coin;
vector<int> dp;         // dp[i] = i 금액을 만들 수 있는 경우의 수
int N, M;

void input() {
    cin >> N;

    coin.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    cin >> M;

    dp.assign(M+1, 0);
}

int main()
{
    int T;

    cin >> T;

    for (int t = 0; t < T; t++) {
        input();

        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= M; j++) {
                if (j - coin[i] >= 0)
                    // dp[금액] += dp[금액 - 동전(금액)]
                    dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[M] << "\n";
    }

    return 0;
}