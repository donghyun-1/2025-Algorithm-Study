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
vector<pair<int, int>> graph[10000];
vector<int>minDist;
void bfs(int startnode)
{
	priority_queue<pair<int, int>>pq;
	pq.push({ 0,startnode });
	minDist[startnode] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().second;//현재 노드 번호
		int dist = -pq.top().first;//현재 노드까지의 비용
		
		pq.pop();
		if (minDist[cur] < dist)continue;
		
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int cost = dist + graph[cur][i].second;
			if (cost < minDist[graph[cur][i].first])
			{
				minDist[graph[cur][i].first] = cost;
				pq.push(make_pair(-cost, graph[cur][i].first));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int shortRoadCnt, roadLength;
	cin >> shortRoadCnt >> roadLength;
	for (int i = 0; i < roadLength; ++i) {
		// 일반 도로: i → i+1 (비용 1)
		graph[i].push_back({ i + 1, 1 });
	}
	for (int i = 0; i < shortRoadCnt; i++)
	{
		int start, end, dist;
		cin >> start >> end >> dist;

		if (end <= roadLength)//지름길의 도착점이 도로 길이보다 크면 걍 안넣어버림
		{
			graph[start].push_back({ end,dist });
		}
	}
	minDist.resize(roadLength + 1, 1e9);
	bfs(0);
	cout << minDist[roadLength];

}