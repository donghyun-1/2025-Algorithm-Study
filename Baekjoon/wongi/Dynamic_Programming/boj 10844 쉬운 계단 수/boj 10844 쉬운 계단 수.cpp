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
long dp[101][11];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	dp[1][0] = 0;
	//dp[i][n] ==> i -> 계단개수 n으로 끝나는 계단수일때 경우의 수들
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;//일단 계단 1일땐 다 1개임
	}
	for (int i = 2; i <= count; i++) {
		// 끝자리가 0인 경우==> 바로 앞자리는 1만 가능
		dp[i][0] = dp[i - 1][1];
		// 끝자리가 1~8인 경우--> 앞자리가 d-1 또는 d+1
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		// 끝자리가 9인 경우--> 바로 앞자리는 8만 가능
		dp[i][9] = dp[i - 1][8];
	}
	long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += dp[count][i];
	}
	cout << ans % 1000000000 << "\n";
	return 0;

}