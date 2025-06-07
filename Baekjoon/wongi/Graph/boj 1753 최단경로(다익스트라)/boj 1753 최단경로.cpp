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
vector<pair<int, int>>graph[20001];
int minDist[20001];
int V, E;
//v : 노드 개수, e : 간선 개수, 시작점
void bfs(int startNode)
{
	priority_queue<pair<int, int>>pq;
	// pair<최단 경로 거리, 노드>
	/*우선 순위 큐 사용하는 이유
	 --> 아직 방문하지 않은 노드 중에서 현재까지 알려진 최단 거리 값이 가장 작은 노드를 선택해서
	 그 노드를 기준으로 거리를 갱신함
	 이때 가장 작은 노드를 선택할때 우선순위 큐를 사용을 한다면 빠르게 최소값을 뽑아낼 수 있다.
	 따라서 우선순위 큐를 사용한 최소 힙을 사용하여 빠르게 최소값을 꺼내도록 구현*/

	pq.push({ 0,startNode });
	//시작 노드로 가기위한 퇴단 거리는 0으로 설정 
	// --> 맨처음에 자기 자신으로 가는 최단 비용은 0이므로 
	minDist[startNode] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().second;//현재 노드 번호
		int dist = -pq.top().first;//현재 노드까지의 비용
		/*
		우선순위 큐는 기본적으로 최대 힙으로 구현이 되어있으므로
		거리값을 꺼낼때 -를 붙혀서 즉 부호를 바꿔서 넣어 최소 힙을 동작하도록함
		*/
		pq.pop();
		if (minDist[cur] < dist)continue;
		/*
		현재 노드가 이미 처리된 적 있는 노드라면 무시
		현재 노드까지의 비용이 즉  최단 거리 테이블의 값보다 크다면 이미 처리된 적 있는 노드이므로 무시
		이 부분 때문에 visited 배열을 안써도 되는 것
		*/
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int cost = dist + graph[cur][i].second;
			//현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
			
			if (cost < minDist[graph[cur][i].first])
			{
				minDist[graph[cur][i].first] = cost;
				// 최단거리 테이블 갱신
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
	int startNode;
	cin >> V >> E;
	cin >> startNode;

	for (int i = 0; i < E; i++)
	{
		int start, end, dist;
		cin >> start >> end >> dist;
		graph[start].push_back({end,dist});
	}
	fill(minDist, minDist + V + 1, 1e9);
	bfs(startNode);
	for (int i = 1; i <= V; i++)
	{
		if (minDist[i] == 1e9)
		{
			cout << "INF" << '\n';
		}
		else
			cout << minDist[i] << '\n';
	}
}