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
#include<math.h>
using namespace std;
int dp[5001];//i 키로그램 설탕을 만들때 필요한 최소 봉지수
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int kg;
    cin >> kg;
    dp[0] = 0;
    dp[1] = -1;
    dp[2] = -1;
    dp[3] = 1;
    dp[4] = -1;
    dp[5] = 1;

    for (int i = 6; i <= kg; i++)
    {
        if (dp[i - 3] == -1 && dp[i - 5] == -1)// 3kg 5kg 짜리를 못 만드니 ikg 은 불가능한 경우
        {
            dp[i] = -1;
        }
        else if(dp[i-3]==-1)//3kg은 못만드니까 5kg로 만드는 방법을 ++
            //3kg짜리 봉지 하나를 더 넣는 경우가 안되면 5kg짜리를 넣는다
        {
            dp[i] = dp[i - 5] + 1;
        }
        else if (dp[i - 5] == -1)//이하 동일
            //5kg봉지 하나 더 넣는경우 안되니까 3kg 짜릴 넣는 경우에 수에서 +1
        {
            dp[i] = dp[i - 3] + 1;
        }
        else// 근데 이제 3kg 하고 5kg으로 둘다 만들수 있는 경우가 있다면 더 적은 봉지를 사용한 경우를 +1해주는거지.
        {
            dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
        }
    }
    cout << dp[kg];
}