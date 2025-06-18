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
int dp[101][100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num, kg;
    cin >> num >> kg;
    vector<int> weight(num+1);
    vector<int> price(num + 1);
   
    //dp[i][j] 테이블 정의
    //i개의 물건이 있고 무게 j만큼 배낭을 채울 수 있을 때
    // 가져갈 수 있는 물건들의 가치의 최댓값
    for (int i = 1; i <= num; i++)
    {
        int w, p;
        cin >> w >> p;
        weight[i] = w;
        price[i] = p;
    }
    for (int i = 1; i <= num; i++)
    {
        for(int j=1;j<=kg;j++)
        {
            if (j >= weight[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + price[i]);
                //                         ,남은 용량에서 이 물건의 무게를 빼고 그전까지의 최대값에 현재 물건의 가치를 더함
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[num][kg];
}