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
vector<pair<int, int>> graph[100001];
long long minDist[100001];
vector<int> endNodes;
void bfs(vector<int> startNodes)
{
	priority_queue<pair<long long, int>> pq;
	
	for (int i = 0; i < startNodes.size(); i++)
	{
		pq.push({ 0,endNodes[i] });
		minDist[endNodes[i]] = 0;
	}
	while (!pq.empty())
	{
		int cur = pq.top().second;
		long long dist = -pq.top().first;
		pq.pop();
		if (minDist[cur] < dist)continue;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			long long cost = dist + graph[cur][i].second;
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
	/*
	* 오답 노트
	1.각 도시에서 면접장까지 각각 다익스트라를 사용하여 최단 거리를 구해서 
	- 정답을 추출하여 문제를 풀었으나 시간 초과로 실패
	2. 구글링 + gpt 에게 물어봄
	-> 면접장(목적지)에서 출발해서 역방향 그래프에서 다익스트라를 돌리면
	-> “도시에서 면접장까지”의 최단거리가 한 번에 다 구해짐
	따라서 면접장에서 각 도시들에 대한 최단 거리를 구하여 그중 제일 큰 값을 출력해주면 정답
	3. 그래서 처음에 각 면접 장소들로 시작점 정해서 다익스트라를 각각 돌리려 했지만 이것또한 시간초과
	4. 따라서 한번 다익스트라를 돌릴때 시작점을 모두 pq에 넣고 다익스트라를 돌림
	*/
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node, edge, answerNode;

	cin >> node >> edge >> answerNode;
	for (int i = 0; i < edge; i++)
	{
		int start, end, dist;
		cin >> start >> end >> dist;
		graph[end].push_back({ start,dist });
	}
	fill(minDist, minDist +node+1, 1e18);
	// 여기서도 충분이 큰 값을 넣어줘야함 --> 틀린이유 le9를 하면 10^5 * 10^5 =1e10까지 가서 1e9는 작다
	for (int i = 0; i < answerNode; i++)
	{
		int endNode;
		cin >> endNode;
		endNodes.push_back(endNode);
	}
	bfs(endNodes);
	int idx = max_element(minDist + 1, minDist + node + 1) - minDist;//최종적으로 가장 큰값을 출력
	long long maxDist = minDist[idx];

    cout << idx << "\n" << maxDist << "\n";
	
}