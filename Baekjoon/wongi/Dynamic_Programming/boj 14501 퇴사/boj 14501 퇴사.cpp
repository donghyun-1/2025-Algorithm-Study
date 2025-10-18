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
#include <unordered_set>
#include<unordered_map>
using namespace std;
int N;
int T[17];
int P[17];
int dp[17];
// dp테이블 정의 -> i번째 부터 시작해서 n까지 상담했을때 받을 수 있는 최대 돈
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> T[i] >> P[i];
    }
    for (int i = N; i > 0; i--)
    {
        if (i + T[i] > N + 1)//만약에 i번째부터 시작했는데 퇴사일 까지 안끝날때
        {
            dp[i] = dp[i + 1];
            /*
            i일부터 t[i]일 걸리는 상담을 시작하면,
            종료일이 i + t[i] - 1이므로, 그 다음 날은 i + t[i]
            퇴사일은 n+1일이기 때문에, i + t[i] > n+1 이면 불가능
            */
        }
        else//퇴사일 안에 끝날때
        {

            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
            /*
             1) 상담을 건너뛰고 다음 날부터 얻는 수익: d[i+1]
             2) 오늘 상담을 하고, 끝나는 날 다음날부터 얻는 수익: p[i] + d[i + t[i]]
             둘 중 큰 값을 선택*/
        }
    }
    cout << *max_element(dp + 1, dp + N + 1);


}