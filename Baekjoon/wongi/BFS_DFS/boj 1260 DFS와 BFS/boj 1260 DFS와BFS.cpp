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
vector<bool> visited;
void DFS(vector<vector<int>>& arr, int node)
{
	if (visited[node] == 1)
	{
		return;
	}
	visited[node] = 1;
	cout << node << ' ';
	for (int i = 0; i < arr[node].size(); i++)
	{
		int start = arr[node][i];
		if (visited[start] != 1)
		{
			DFS(arr, start);
		}
	}
}
void BFS(int start)
{
	queue<int>q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		cout << cur<<' ';
		for (int i = 0; i < linkedArr[cur].size(); i++)
		{
			int next = linkedArr[cur][i];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
			}
		}

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, V;

	cin >> N >> M >> V;
	linkedArr.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 1; i <= M; i++)
	{
		int start, end;
		cin >> start >> end;
		linkedArr[start].push_back(end);
		linkedArr[end].push_back(start);
	}
	for (int i = 1; i <= N; i++) {
		sort(linkedArr[i].begin(), linkedArr[i].end());
	}//정점 번호가 작은것을 먼저 방문한다 하였으므로 오름차순 정렬
	DFS(linkedArr, V);
	fill(visited.begin(), visited.end(), false);
	cout << "\n";
	BFS(V);
}