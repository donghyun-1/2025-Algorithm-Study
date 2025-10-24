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
#include <unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;
vector<pair<int,int>> linkedList[5001];
vector<int> minDist;
int n, m,s,t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    minDist.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        linkedList[start].push_back({ end,cost });
        linkedList[end].push_back({ start,cost });
        //무방향 -> 양방향
    }
    cin >> s >> t;
    fill(minDist.begin(), minDist.end(), 100000001);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,s });//거리 순으로 최대 힙.
    minDist[s] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;//위치
        int cost = pq.top().first;//현재 노드 까지의 비용
        pq.pop();
        if (minDist[cur] < cost) continue;// 더 짧은 거리 있으면 pass

        for (int i = 0; i < linkedList[cur].size(); i++)
        {
            int nextNode = linkedList[cur][i].first;
            int curCost = linkedList[cur][i].second;
            int dist = cost + curCost;
            if (dist < minDist[nextNode])
            {
                minDist[nextNode] = dist;
                pq.push(make_pair(dist, nextNode));
            }
        }
    }
    cout << minDist[t];
}