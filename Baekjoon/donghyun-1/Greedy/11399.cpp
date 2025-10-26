// https://www.acmicpc.net/problem/11399
// ATM (실버 4)
// 2025-10-18

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

    vector<int> v(N);
    vector<int> sum(N);
    int ans = 0;

    // 배열 입력
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    // 정렬
    sort(v.begin(), v.end());

    // 누적 합
    sum[0] = v[0];

    for (int i = 1; i < N; i++) {
        sum[i] = sum[i-1] + v[i];
    }

    for (int i = 0; i < N; i++) {
        ans += sum[i];
    }

    cout << ans;

    return 0;
}