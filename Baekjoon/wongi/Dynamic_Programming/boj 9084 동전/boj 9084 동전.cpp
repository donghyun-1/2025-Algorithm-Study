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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int count;
    cin >> count;
    vector<int>answer;
    for (int i = 0; i < count; i++)
    {
        vector<int> dp;
     
        int typeCount;
        cin >> typeCount;
        vector<int>coinArr;
        for (int j = 0; j < typeCount; j++)
        {
            int coin;
            cin >> coin;
            coinArr.push_back(coin);
        }
        int targetCoin;
        cin >> targetCoin;
        dp.resize(targetCoin+1);
        dp[0] = 1;// 0원을 만드는 경우의 수는 아무것도 안넣기 이거 하나임
        //dp[i] 테이블 : i원까지의 coinarr의 수들을 가지고 만들수 있는 경우의 수
        for(int i=0;i<typeCount;i++)//각 동전 종류 갯수 가지고 반복
        {
            for (int a =coinArr[i] ; a <= targetCoin; a++)
            {
                dp[a] += dp[a - coinArr[i]];
                //a원을 만들기 위해 coinArr[i]원을 마지막에 딱 한번만 추가해서 a원을 만드는 방법을 모두 더해줌
            }
        }
        answer.push_back(dp[targetCoin]);
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }
}