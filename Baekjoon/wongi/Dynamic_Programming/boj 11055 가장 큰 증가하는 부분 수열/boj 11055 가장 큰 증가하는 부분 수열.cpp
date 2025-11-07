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
int dp[1001];
//i번째 까지의 값을 포함했을 때 최대 값
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> input;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        input.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        dp[i] = input[i];//일단 먼저 자기 자신으로 dp 테이블을 초기화함.
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[j] < input[i])// 현재 값 i 가 더 커야함. 그래야 증가하는 수열 조건에 맞음
            {
                dp[i] = max(dp[i],dp[j]+input[i]);
                //dp 테이블 하고 이전값까지의 값 (dp[j]) 와 현재 자기 자신 값 (input[i])을 더한값을 비교해서
                // 더 큰게 있다면 그 값으로 갱신함
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer = max(answer, dp[i]);
    }
    cout << answer;
}