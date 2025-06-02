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
vector<vector<int>> linkedArr;
vector<int>visited;
int answer = 0;
void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = 0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < linkedArr[cur].size(); i++)
		{
			int next = linkedArr[cur][i];
			if (visited[next] == -1)
			{
				visited[next] = visited[cur] + 1;
				if (visited[next] <= 2)//친구와 친구의 친구까지가 거리가 2이다
				{
					answer++;
					q.push(next);
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	linkedArr.resize(n + 1);
	visited.resize(n + 1, -1);
	for (int i = 1; i <= m; i++)
	{
		int start, end;
		cin >> start >> end;
		linkedArr[start].push_back(end);
		linkedArr[end].push_back(start);
	}
	bfs(1);
	cout << answer;
	
}