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
/*
다익스트라를 사용하여 
N노드까지의 최소거리를 계산하여 출력
시작 노드는 1 부터
*/
vector<pair<int, int>>  linkedarr[50001];
long long minDist[50001];
int N, M;
void func(int startnode)
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

        for (int i = 0; i < linkedarr[cur].size(); i++)
        {
            int nextNode = linkedarr[cur][i].first;
            int curCost = linkedarr[cur][i].second;
            long long cost = dist + curCost;
            if (cost < minDist[nextNode])
            {
                minDist[nextNode] = cost;
                pq.push(make_pair(-cost, nextNode));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        linkedarr[start].push_back({ end,cost });
        linkedarr[end].push_back({ start,cost });
    }
    fill(minDist, minDist + N + 1, 1e18);
    func(1);
    cout << minDist[N];
}