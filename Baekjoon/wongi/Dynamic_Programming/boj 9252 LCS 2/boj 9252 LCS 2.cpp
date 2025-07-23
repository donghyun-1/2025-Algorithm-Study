#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    cin >> s1;
    cin >> s2;
   
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])//비교하는 문자가 둘이 같을때
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                //왼쪽 대각선dp 테이블에다가+1 
            }
            else//비교하는 문자가 둘이 다를때
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                //왼쪽 위쪽 둘중 비교해서 큰값 테이블에 삽입
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << '\n';
    if (dp[s1.size()][s2.size()] != 0)
    {

        string answer = "";
        int s1Size = s1.size();
        int s2Size = s2.size();
        while (s1Size > 0 && s2Size > 0)// 마지막 부터 
        {
            if (s1[s1Size - 1] == s2[s2Size - 1])// ==> 문자 열이 같을때
            {
                answer += s1[s1Size - 1];
                s1Size--; s2Size--;
            }
            else//만약 다를때
            {
                if (dp[s1Size - 1][s2Size] > dp[s1Size][s2Size - 1])//위쪽이 더 클시에 위로 이동
                {
                    s1Size--;
                }
                else//왼쪽이 더 클시에 왼쪽으로 이동
                {
                    s2Size--;
                }
            }
        }
        reverse(answer.begin(), answer.end());
        cout << answer;
    }
}