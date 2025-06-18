// https://www.acmicpc.net/problem/2512
// 예산 (실버 2)
// 2025-06-18

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, budget;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cin >> budget;

    sort(v.begin(), v.end());

    int start = 0;
    int end = v[N-1];
    int ans, sum;
    
    while (start <= end) {
        sum = 0;
        int mid = (start + end) / 2;

        for(int i = 0; i < N; i++) {
            sum += min(v[i], mid);
        }

        // 더 큰 mid 시도
        if (budget >= sum) {
            ans = mid;
            start = mid + 1;
        }
        // 더 작은 mid 시도
        else {
            end = mid-1;
        }
    }

    cout << ans;

    return 0;
}