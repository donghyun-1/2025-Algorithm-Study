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
    vector<int> dp;
    vector<int> arr;
    dp.resize(count);// i번째 까지의 arr[i]를 포함할때 의 최대 연속 부분합 테이블
    arr.resize(count);
   
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    for (int i = 0; i < count; i++)
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);//새로운 구간시작 (이전 합들이 더 작아서 무시) , 이전 구간에 이어서 현재 arr[i]값을 더함 
    }
    int answer = *max_element(dp.begin(), dp.end());
    cout << answer;
}