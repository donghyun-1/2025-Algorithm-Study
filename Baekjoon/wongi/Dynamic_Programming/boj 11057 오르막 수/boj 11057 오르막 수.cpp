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
long long dp[1001][10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	for (int i = 0; i <= 9; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 0; i < count; i++)
	{
		dp[i][9] = 1;
	}
	for (int i = 1; i < count; i++)
	{
		for (int j = 8; j >= 0; j--)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j + 1])%10007;
		}
	}
	long result = 0;
	for (int i = 0; i <= 9; i++)
	{
		result += dp[count - 1][i];
	}
	int answer = result % 10007;
	cout << answer;
}