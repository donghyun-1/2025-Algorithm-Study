// https://www.acmicpc.net/problem/2343
// 기타 레슨 (실버 1)
// 2025-08-06

#include <iostream>
#include <vector>

using namespace std;

int N, M;
int maxLen = 0;
int sumLen = 0;
vector<int> arr;

void input() {
    cin >> N >> M;

    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        maxLen = max(maxLen, arr[i]);
        sumLen += arr[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // 이분 탐색
    long long low = maxLen;             // 최소 크기
    long long high = sumLen;            // 전체 크기
    int ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;

        int total = 0;                  // 전체 길이
        int count = 1;                  // 블루레이 카운트
        
        for (int i = 0; i < N; i++) {
            if (arr[i] + total > mid) {
                count++;
                total = 0;
            }

            total += arr[i];
        }

        if (count <= M) {
            ans = mid;
            high = mid - 1;         // M개를 넘지 않는 선에서 더 줄이기
        }
        else {
            low = mid + 1;
        }
    }

    cout << ans;

    return 0;
}