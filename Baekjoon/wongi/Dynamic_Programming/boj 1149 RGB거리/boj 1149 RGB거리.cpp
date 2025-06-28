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
int dp[1001][3]; 
// i번째 집까지 칠할 때 비용의 최솟값. 단 [i][0] 집은 빨강
//                  "                  [i][1] 집은 초록
//                  "                  [i][2] 집은 파랑
int R[1001];
int G[1001];
int B[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	for (int i = 1; i <= count; i++)
	{
		int r, g, b;
		cin >> r >> g >> b;
		R[i] = r;
		G[i] = g;
		B[i] = b;
	}
	dp[1][0] = R[1];
	dp[1][1] = G[1];
	dp[1][2] = B[1];
	for (int i = 2; i <= count; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + R[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + G[i];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + B[i];
	}
	cout << *min_element(dp[count], dp[count] + 3);
}