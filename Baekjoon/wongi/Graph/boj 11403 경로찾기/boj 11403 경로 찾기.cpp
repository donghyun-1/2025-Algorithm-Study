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
int arr[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	//플로이드 워셜 알고리즘
	// 3중 for문을 사용하여 시작점에서 도착점 사이에 거치는 모든 노드를 탐색
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][k] == 1 && arr[k][j] == 1)
				// ==> k를 거치는 모든 경로중 하나라도 연결된 경로가 있으면 i j는 연결된 노드로 취급
				{
					arr[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j]<<' ';
		}
		cout << '\n';
	}
}