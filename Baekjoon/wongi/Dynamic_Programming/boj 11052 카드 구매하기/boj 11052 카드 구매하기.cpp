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
int card[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*
	dp테이블 : 카드 i개를 사는데 내는 최대 비용
	점화식 유도 방법
	카드 i개를 살 때 마지막에 산 카트팩은 몇개짜리일까?
	카드팩의 크기는 1~i까지.
	if 카드j 개짜리 팩을 샀다면 나머지 dp[i-j] 만큼의 최대 비용으로 샀다 할수 있음
	ex)
	i가 3일때 
	마지막에 산 카드팩 크기 j는 1 또는 2 가능

	j = 1 : dp[2] = dp[2-1] + P1 = dp[1] + 1 = 1 + 1 = 2

	j = 2 : dp[2] = dp[2-2] + P2 = dp[0] + 5 = 0 + 5 = 5

	최대값 선택 → dp[2] = 5
	
	i가 4일 때
	j = 1, 2, 3, 4

	j=1 : dp[4] = dp[3] + P1 = 6 + 1 = 7

	j=2 : dp[4] = dp[2] + P2 = 5 + 5 = 10

	j=3 : dp[4] = dp[1] + P3 = 1 + 6 = 7

	j=4 : dp[4] = dp[0] + P4 = 0 + 7 = 7

	최대값 → dp[4] = 10
	이런 식으로 최대값 갱신해가면서 구한다
	*/
	int cardCount;
	cin >> cardCount;
	for (int i = 1; i <= cardCount; i++)
	{
		cin >> card[i];
	}
	card[0] = 0;
	dp[0] = 0;
	for (int i = 1; i <= cardCount; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + card[j]);
		}
	}
	cout << dp[cardCount];
}