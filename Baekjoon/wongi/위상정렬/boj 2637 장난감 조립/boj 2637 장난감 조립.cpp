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
#include<cstring>
using namespace std;
int n, m;
/*
* 
* n번이 완제품
* 
장난감 x 만드는데 필요한
부품 y가 k개 필요하다
일단 기본 부품은 indegree가 0인 부품
*/
vector<pair<int, int>> adj[101];
int indegree[101];
vector<int> defaultInfo;//기본 부품 노드번호 
int answer[101][101];
//i번 부품 만들때 j번 기본 부품이 몇개가 필요한지
//i를 만들기 위한 기본 부품의 리스트들이 저장이 되어있음
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        adj[y].push_back({ x,k });
        indegree[x]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            answer[i][i] = 1;
            //기본 부품은 자기 자신만 필요함 따라서 1로 초기화해줌.
            defaultInfo.push_back(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            pair<int, int>next = adj[cur][i];
            int nextNode = next.first;
            int nextNodeCnt = next.second;
            
            indegree[nextNode]--;
            for (int j = 1; j <= n; j++) //부품 번호
            {
                answer[nextNode][j] += answer[cur][j] * nextNodeCnt;// cur 을 만들 때 필요한 j번 기본 부품 갯수 
            }
            if (indegree[nextNode] == 0)
            {
                q.push(nextNode);
            }

        }
    }
    sort(defaultInfo.begin(), defaultInfo.end());
    for (int i = 0; i < defaultInfo.size(); i++)
    {
        cout << defaultInfo[i] << ' ' << answer[n][defaultInfo[i]]<<'\n';
    }
}