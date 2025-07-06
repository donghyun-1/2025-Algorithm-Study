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
vector<vector<int>>linkedArr;
vector<int>dist;
//일반 적인 그래프 탐색 문제.
void bfs(int startNode)
{
    queue<int> q;
    q.push(startNode);
    dist[startNode] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < linkedArr[cur].size(); i++)
        {
            int next = linkedArr[cur][i];
            if (dist[next] == -1)
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
    int N, M;
    cin >> N >> M;
    linkedArr.resize(N + 1);
    dist.resize(N + 1, -1);
    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;
        linkedArr[start].push_back(end);
        linkedArr[end].push_back(start);
    }
    bfs(1);
    int answerDist = *max_element(dist.begin() + 1, dist.end());
    int minIdx = -1, count = 0;
    for (int i = 1; i <= N; i++) 
    {
        if (dist[i] == answerDist)
        {
            if (minIdx == -1)
            {
                minIdx = i;
            }
            count++;
        }
    }
    cout << minIdx << " " << answerDist << " " << count << "\n";
}