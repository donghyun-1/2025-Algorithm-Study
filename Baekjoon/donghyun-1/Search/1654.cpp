// https://www.acmicpc.net/problem/1654
// 랜선 자르기 (실버 2)
// 2025-07-22

/* 
    <접근 방법>
    [1] 
    arr에 랜선 길이 입력, 가장 긴 랜선 구하기 (max_length)

    [2]
    길이 1 ~ max_length 범위 이분 탐색 사용
    N개 이상 만들 수 있는 길이 중 가장 긴 길이 구하기
*/

#include <iostream>

#define MAX_K 10001

using namespace std;

int K, N;
unsigned arr[MAX_K];
unsigned int max_length = 0;

void input() {
    cin >> K >> N;
    
    // 랜선 입력
    for (int i = 0; i < K; i++) {
        cin >> arr[i];

        max_length = max(max_length, arr[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    // 이진 탐색
    unsigned int left = 1;
    unsigned int right = max_length;
    unsigned int mid;
    unsigned int ans = 0;

    while (left <= right) {
        int now = 0;
        mid = (left + right) / 2;

        // 랜선 개수 세기
        for (int i = 0; i < K; i++) {
            now += arr[i] / mid;
        }

        // 최대 길이 저장
        if (now >= N) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;

    return 0;
}