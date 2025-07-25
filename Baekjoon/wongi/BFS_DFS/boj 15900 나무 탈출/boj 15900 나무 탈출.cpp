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
vector<bool> visited;
int leafNode;
/*
루트 노드에서 각 리프 노드까지 가는 거리가 짝수이면 NO
홀수 이면 YES
결국 dfs로 트리를 순회 하면서 총 거리를 더해 가면서 
거리의 총합이 홀 or 짝인지 판단하면된다
*/
void dfs(int node,int depth)
{
    visited[node] = true;
    if (linkedArr[node].size() == 1 && node != 1)
        //부모 노드가 1일때는 예외처리
        // 만약에 링크드 어레이에 하나만 저장 되어있을 경우가 이제 
        //리프 노드라는 뜻이므로 그에 따른 순회 거리를 더하자
    {
        leafNode += depth;
    }
    for (int i = 0; i < linkedArr[node].size(); i++)
    {
        int next = linkedArr[node][i];
        if (!visited[next])
        {
            dfs(next, depth + 1);
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int nodeCount;
    cin >> nodeCount;
    linkedArr.resize(nodeCount + 1);
    visited.resize(nodeCount + 1);
    for (int i = 0; i < nodeCount - 1; i++)
    {
        int start, end;
        cin >> start >> end;
        linkedArr[start].push_back(end);
        linkedArr[end].push_back(start);
    }
    dfs(1, 0);
    if (leafNode % 2 == 1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}