// https://www.acmicpc.net/problem/1106
// 호텔 (골드 5)
// 2025-10-16

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int C, N, ans = 0;
vector<pii> city;
vector<int> dp;

void input() {
    int cost, people;

    cin >> C >> N;
    dp.resize(2000, 100001);	// 모은 사람 수
	dp[0] = 0;

    for (int i = 0; i < N; i++) {
        cin >> cost >> people;
        
        city.push_back({cost, people});
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    for (int i = 1; i < 2000; i++) {
		for (int j = 0; j < N; j++) {
			int cost = city[j].first;
			int people = city[j].second;

			if (i - people >= 0) {
				dp[i] = min(dp[i], dp[i-people] + cost);
			}
		}
    }

    cout << *min_element(dp.begin() + C, dp.end()) << "\n";
	// cout << dp[C];

    return 0;
}