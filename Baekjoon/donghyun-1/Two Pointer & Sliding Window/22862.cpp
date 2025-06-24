// https://www.acmicpc.net/problem/22862
// 가장 긴 짝수 연속한 부분 수열 (large) (골드 5)
// 2025-06-15

#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> S;

void input() {
    cin >> N >> K;

    S.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
}

int two_pointer() {
    int left = 0;
    int right = 0;
    int odd_cnt = 0;
    int max_length = 0;

    while (right < N) {
        // 홀수
        if (S[right] % 2 == 1) {
            odd_cnt++;
        }

        while (odd_cnt > K) {
            // 홀수
            if (S[left] % 2 == 1) {
                odd_cnt--;
            }

            left++;
        }

        // 짝수 길이
        int length = (right - left + 1) - odd_cnt;
        max_length = max(max_length, length);

        right++;
    }

    return max_length;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    cout << two_pointer();

    return 0;
}