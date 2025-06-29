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
vector<bool>visited;
vector<int>visitCount;
void bfs(int startNode)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty())
    {
        int cur = q.front();  q.pop();
        for (int i = 0; i < linkedArr[cur].size(); i++)
        {
            int next = linkedArr[cur][i];
            if (!visited[next])
            {
                q.push(next);
                visitCount[next]++;// 방문할 때 마다 그 방문한 노드의 visit횟수를 늘려줌
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
    int N, M;
    cin >> N >> M;
    linkedArr.resize(N + 1);
    visitCount.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;
        linkedArr[start].push_back(end);
    }
    for (int i = 0; i <= N; i++)
    {
        fill(visited.begin(), visited.end(), false);
        bfs(i);
    }
    int maxValue = *max_element(visitCount.begin(), visitCount.end());
    for (int i = 0; i <= N; i++)
    {
        if (visitCount[i] == maxValue)
        {
            cout << i << ' ';
        }
    }
}