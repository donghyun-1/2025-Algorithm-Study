// https://www.acmicpc.net/problem/13398
// 연속합 2 (골드 5)
// 2025-07-21

/* 
    <접근 방법>
    [1] 
    arr에 수열 입력

    [2]
    (풀이를 못 떠올려서 인터넷 참고)
    dp[i][0] 일 때는 제거 안하는 경우: 현재 값 vs 이전 값 + 현재 값 비교
    dp[i][1] 일 때는 제거 하는 경우: 이번 값 제외하고 누적 최대 합(제거 사용) vs 이전 누적 합 + 이번 값(제거 사용 x)

    ans = ans, dp[i][0], dp[i][1] 중에 더 큰 값 매번 갱신
    
    [3]
    ans 출력
*/

#include <iostream>

using namespace std;

int arr[100001];
int dp[100001][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = arr[0];
    dp[0][0] = dp[0][1] = arr[0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(arr[i], dp[i-1][0] + arr[i]);        // 제거 안하기: max(현재 값 vs 이전 값 + 현재 값)
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);    // 제거 하기: max(이번 값 빼기 vs 이전 값 + 현재 값)

        // 최댓값 갱신
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    cout << ans;
    
    return 0;
}