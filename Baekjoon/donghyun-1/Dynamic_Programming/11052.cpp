// https://www.acmicpc.net/problem/11052
// 카드 구매하기 (실버 1)
// 2025-05-27

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> card;
    card.push_back(0);

    // 카드 금액
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        card.push_back(a);
    }

    vector<int> DP(N+1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            DP[i] = max(DP[i], DP[i-j] + card[j]);
        }
    }

    cout << DP[N];

    return 0;
}