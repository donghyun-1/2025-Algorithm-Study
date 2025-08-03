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
/*
dp[i] 테이블 --> i번째 input을 마지막으로 한 가장 긴 증가하는 부분 수열의 길이.

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    int input[1001];
    int dp[1001] = {1};
    for (int i = 0; i < count; i++)
    {
        cin >> input[i];
    }
    fill(dp, dp + 1001, 1); // 모든 값을 1로 초기화 why? --> 자기 자신하나만 쓸 수도 있으므로
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < i; j++)//i앞 즉 이전 수들(j)
        {
            if (input[j] < input[i])//증가할때 즉 앞쪽수(j)가 지금 수(i)보다 작을때만 이을 수 있으므로
            {
                dp[i] = max(dp[i], dp[j] + 1);
                //지금까지 i번째 인덱스까지 최장 증가 수열 
                //j에서 i로 이어 붙혔을때의 길이를 비교해서 큰걸로 갱신

            }
        }
    }
    int answer = *max_element(dp, dp + count);
    cout << answer;
}
