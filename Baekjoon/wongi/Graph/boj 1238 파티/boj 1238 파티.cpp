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
vector<pair<int, int>> graph[1001];
vector<int> minDist;
int node, edge, endNode;
void bfs(int startNode)
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,startNode });
    minDist[startNode] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if (dist > minDist[cur]) continue;
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

    cin >> node >> edge >> endNode;

    for (int i = 0; i < edge; i++)
    {
        int start, end, dist;
        cin >> start >> end >> dist;
        graph[start].push_back({ end,dist });
    }
    //1. 일단 먼저 파티 장소부터 다른 도시들의 최단 경로를 구해줌
    minDist.resize(node + 1, 1e9);

    bfs(endNode);
    // 따로 벡터에 저장
    vector<int> partyMinDist = minDist;
    //2. 파티하는 도시 제외 나머지 도시의 최단거리를 구해줌
    vector<int> cityToPartyMinDist(node + 1, 1e9);
    
    for (int i = 1; i <= node; i++) 
    {
        if (i != endNode)
        {
            fill(minDist.begin(), minDist.end(), 1e9);
            bfs(i);
            cityToPartyMinDist[i] = minDist[endNode]; //그리고 저장할때는 각 노드에서 파티하는 도시까지의 최단거리를 저장해줌.
        }

    }

    // 3. 왕복 시간 최댓값 찾기
    int answer = -1;
    for (int i = 1; i <= node; i++) 
    {
        if (cityToPartyMinDist[i] < 1e9 && partyMinDist[i] < 1e9)
        {
            int dist = cityToPartyMinDist[i] + partyMinDist[i];
            answer = max(answer, dist);//최종으로 왕복시간 더해서 가장 큰 값을 answer에 저장 및 출력
        }
    }
    cout << answer << '\n';
    
  
}