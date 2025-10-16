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
int INF = 1e9; //max Int
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    12(적어도 몇명을 늘려야하는지) 2 (도시 수)
    3(비용) 5(얻는 고객수)
    1(비용) 1(얻는 고객수)

    answer =8
    */
    int c, n;
    cin >> c >> n;
    vector<int> cost;
    cost.resize(n);
    vector<int> person;
    person.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i] >> person[i];
    }
    vector<int> dp(c+101, INF);//문제에서 person은 100이하랬으니 충분히 더 크게 만들어줘야함.
    /*
    * DP테이블
    i명을 얻기 위해 투자해야하는 돈의 최소비용 
    */
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = person[i]; j< c + 101; j++)
        {
            dp[j] = min(dp[j], dp[j - person[i]] + cost[i]);
            //이전에 확보한 최소 비용
            //이전에 j-person[i]명 확보 + i번째 도시의 코스트
            // 둘중 최솟값으로 갱신
        }
    }

    int answer = *min_element(dp.begin() + c, dp.end());
    //적어도 c명 확보 
    // 즉 dp테이블 c번째 부터 끝까지 보면서 가장 작은 값을 찾아야함
    cout << answer;


}