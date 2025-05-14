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
long dp[91];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= count; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	cout << dp[count];
}