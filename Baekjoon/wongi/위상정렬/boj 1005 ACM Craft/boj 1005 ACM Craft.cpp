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
/*
위상정렬
--> 선행 건물이 다 지어질 때까지 기다려야함.
순서 선택할때
위상정렬로 돌리면서 
값을 더하는데 이제 이거는 선행 건물들이
다 지어졌을때 그 건물이 다 완료 될수있기(다음 건물로 넘어감) 때문에
사실상 최소 값을 구하는게 아니라
그 건물까지 가는데 최대 값을 구해야함.
///
아무리 빨리 짓고 싶어도 내 앞단계에서 가장 늦게 끝나는 건물이 완성될때까지 기다려야함.
////
*/
int t;
int indegree[1001];
int cost[1001];//각 빌딩 생성 시간
int buildingCost[1001];//현재 건물까지 올때 최대 건물 생성시간
vector<int> adj[100001];
void clear(int n)
{
    fill(indegree, indegree + n + 1, 0);
    fill(cost, cost + n + 1, 0);
    fill(buildingCost, buildingCost + n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    int answer=0;
    while (t--)
    {
      
        int n, k;
        queue<int> q;
        cin >> n >> k;
        clear(n);
        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i];
        }
        
        for (int i = 0; i < k; i++)
        {
            int start ,end;
            cin >> start >> end;
            adj[start].push_back(end);
            indegree[end]++;
        }
        int answerNode;
        cin >> answerNode;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                buildingCost[i] = cost[i];//자기 자신 코스트 저장
            }
        }
        while (!q.empty())
        {
            int cur = q.front(); q.pop();
           
            for (int i = 0; i < adj[cur].size(); i++)
            {
                int next = adj[cur][i];
                indegree[next]--;
                buildingCost[next] = max(buildingCost[next], buildingCost[cur] + cost[next]);
                //이전 건물완료 시간 + 내 건설 시간
                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
        cout << buildingCost[answerNode]<<'\n';
    }
}