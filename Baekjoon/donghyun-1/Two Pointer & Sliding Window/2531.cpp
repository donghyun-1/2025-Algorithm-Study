// https://www.acmicpc.net/problem/2531
// 회전 초밥 (실버 1)
// 2025-06-22

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, d, k, c;
int ans = 0;
int cnt = 0;
vector<int> arr;
unordered_map<int, int> sushi_map;

void input() {
    cin >> N >> d >> k >> c;

    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void coupon_check() {
    if (sushi_map[c] == 0) {
        ans = max(ans, cnt + 1);
    }
    else {
        ans = max(ans, cnt);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // 처음 k 개
    for (int i = 0; i < k; i++) {
        sushi_map[arr[i]]++;

        if (sushi_map[arr[i]] == 1) {
            cnt++;    
        }
    }
    coupon_check();

    for (int i = 1; i < N; i++) {
        // 왼쪽 제거
        sushi_map[arr[i - 1]]--;

        if (sushi_map[arr[i - 1]] == 0) {
            cnt--;
        }

        // 오른쪽 추가
        int idx = (i + k - 1) % N;

        sushi_map[arr[idx]]++;

        if (sushi_map[arr[idx]] == 1) {
            cnt++;    
        }

        coupon_check();
    }

    cout << ans;

    return 0;
}