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
int dp[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 10001; i++)
	{
		dp[i] = 1;
		// 1만쓸때는 항상 1가지 방법이 디폴트로 들어가 있으니 1로 일단 초기화
	}
	for (int i = 2; i < 10001; i++)
	{
		dp[i] += dp[i - 2];
		//2를 하나 이상 포함하는 경우
		//"합이 i가 되도록 마지막에 2를 붙이는" 경우 = dp[i-2]
	}
	for (int i = 3; i < 10001; i++)
	{
		dp[i] += dp[i - 3];
		// 3을 하나 이상 포함하는 경우 추가
		// "합이 i가 되도록 마지막에 3을 붙이는" 경우 = dp[i-3]
	}
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		int input;
		cin >> input;
		cout << dp[input] << '\n';
	}
}