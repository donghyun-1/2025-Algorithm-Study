// https://www.acmicpc.net/problem/9252
// LCS 2 (골드 4)
// 2025-07-23

/* 
    <접근 방법>
    [1] 
    문자열 str1, str2 입력

    [2]
    dp[i][j]로 LCS 표 만들기 (dp[i][j]: 문자열 A의 앞 i글자와 문자열 B의 앞 j글자의 LCS 길이)
    str1[i-1] == str2[j-1] 이면 dp[i][j] = dp[i-1][j-1] + 1;
    str1[i-1] != str2[j-1] 이면 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    
    [3]
    LCS 문자열 구하기
    dp[str1.size()][str2.size()] 값이
    위 값과 같으면 행--
    왼쪽 값과 같으면 열--
    둘 다 아니면 LCS 라는 뜻

    [4]
    LCS 출력
*/

#include <iostream>

using namespace std;

string str1, str2;
int dp[1001][1001]; // dp[i][j]는 문자열 A의 앞 i글자와 문자열 B의 앞 j글자의 LCS 길이

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str1 >> str2;

    // LCS 표 만들기
    for (int i = 1; i <= str1.size(); i++) {
        for (int j = 1; j <= str2.size(); j++) {
            if (str1[i-1] == str2[j-1]) {   // 같으면 왼쪽 대각선 값 + 1
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {  // 다르면 왼쪽, 위 값 중 큰 값으로
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    // 최장 길이 출력
    cout << dp[str1.size()][str2.size()] << "\n";

    // 문자열 구하기
    string ans = "";
    int idx = str2.size();
    for (int i = str1.size(); i >= 1; i--) {
        for (int j = idx; j >= 1; j--) {
            if (dp[i][j] == dp[i-1][j]) {   // 위 값과 같으면 위로 이동 (행--)
                idx = j;
                break;
            }
            else if (dp[i][j] == dp[i][j-1]) {  // 왼쪽 값과 같으면 왼쪽으로 이동 (열--)
                continue;
            }
            else {
                ans = str1[i-1] + ans;
            }
        }
    }

    cout << ans;

    return 0;
}