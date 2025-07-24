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
vector<pair<int, int>> tree[10001];
vector<int> dist;
/*
일단 먼저 제일 거리가 먼 노드를 찾아서 저장하고

그 노드 부터 다시 가장 먼 가중치를 가진 노드까지 길찾기를 하여 거리를 출력하면

트리의 지름 

*/
void bfs(int startNode)
{
    queue<pair<int, int>> q;
    q.push({ startNode,0 });
    dist[startNode] = 0;
    while (!q.empty())
    {
     
        int cur = q.front().first;
        int w = q.front().second;
        q.pop();
        for (int i = 0; i < tree[cur].size(); i++)
        {
            int next = tree[cur][i].first;
            int nextW = tree[cur][i].second;
            if (dist[next] == -1)
            {
                dist[next] = w + nextW;
                q.push({ next ,w + nextW });
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    for (int i = 0; i < count-1; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        tree[start].push_back({ end,weight });
        tree[end].push_back({ start,weight });
    }
    dist.resize(count + 1, -1);
    bfs(1);

    int firstNode = 1;//일단 제일 거리가 먼 노드
    int maxDist = -1;
    for (int i = 1; i <= count; i++) 
    {
        if (dist[i] > maxDist) 
        {
            maxDist = dist[i];
            firstNode = i;
        }
    }
    dist.assign(count + 1, -1); // -1로 다시 초기화
    bfs(firstNode);

    int answer = *max_element(dist.begin() + 1, dist.end());
    cout << answer;
}