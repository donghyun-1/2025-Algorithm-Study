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
일단 필요한 dp 테이블
1. 값을 제거하지 않고 더했을 때의 그 지점까지의 연속합 배열
2. 값을 하나 제거하고 더했을 때의 그 지점까지의 연속합 배열
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> inputArr(n+1);
    vector<int>dp(n+1);
    vector<int>dpExclude(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> inputArr[i];
    }
    dp[1] = inputArr[1];
    dpExclude[1] = inputArr[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1] + inputArr[i], inputArr[i]);
        /*
        만약 누적합 배열과 inputarr의 합이 그냥 inputarr보다 작으면 그곳부터 시작해야함
        따라서 그 인덱스의 dp테이블 즉 누적합 배열을 그 inputarr로 갱신시켜줌
        */        
        dpExclude[i] = max(dpExclude[i - 1] + inputArr[i], dp[i - 1]);
        /*
            dpExclude[i - 1] + inputArr[i]--> 이미 한번 제거해서 쭉 온경우 + 이번 원소
            dp[i - 1] --> 이번 인덱스의 원소를 제거 시키고(안더하고) i-1까지 제거안한 최대합 dp테이블 즉 현재 인덱스를 안 더했으므로
            i까지 한번 제거한 최대합
        */
    }
    int exclude=inputArr[1], noExclude = inputArr[1];
    for (int i = 1; i <= n; i++)
    {
        exclude = max(exclude, dp[i]);
        noExclude = max(noExclude, dpExclude[i]);
    }
    cout << max(exclude, noExclude);
}