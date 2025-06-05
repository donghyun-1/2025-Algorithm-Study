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
vector<vector<long>> arr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, bus;
	cin >> n;
	cin >> bus;
	arr.resize(n + 1, vector<long>(n + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 100000000;
				//맨처음에 1000001로 했었는데 더 큰수로 해줘야함
				/*
				//입력
				3
				2
				1 2 100000
				2 3 100000
				//1에서 3으로 가는데 20만 필요
				//출력
				0 100000 200000
				0 0 100000
				0 0 0
				//오답
				0 100000 0
				0 0 100000
				0 0 0
				*/
			}
		}
	}
	for (int i = 0; i < bus; i++)
	{
		int start, end, dist;
		cin >> start >> end >> dist;
		if (arr[start][end] > dist)
		{
			arr[start][end] = dist;
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				arr[s][e] = min(arr[s][e], arr[s][k] + arr[k][e]);//플로이드 워셜 알고리즘사용
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 100000000)// 갈수 없는 곳은 0으로 출력
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << arr[i][j] << ' ';
			}
		}
		cout << '\n';
	}
}