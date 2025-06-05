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
int targetDist;
vector<vector<int>> linkedArr;
vector<int> dist;
void bfs(int startNode)
{
	queue<int> q;
	q.push(startNode);
	dist[startNode]=0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < linkedArr[cur].size(); i++)
		{
			int next = linkedArr[cur][i];
			if (dist[next]==-1)
			{
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node, edge, startNode;

	cin >> node >> edge >> targetDist >> startNode;
	linkedArr.resize(node + 1);
	dist.resize(node + 1, -1);
	for (int i = 0; i < edge; i++)
	{
		int start, end;
		cin >> start>>end;
		linkedArr[start].push_back(end);
	}
	bfs(startNode);
	vector<int> answer;
	for (int i = 0; i < dist.size(); i++)
	{
		if (dist[i] == targetDist)
		{
			answer.push_back(i);
		}
	}
	sort(answer.begin(), answer.end());
	if (answer.empty())
	{
		cout << -1;
	}
	else
	{
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << '\n';
		}
	}
}