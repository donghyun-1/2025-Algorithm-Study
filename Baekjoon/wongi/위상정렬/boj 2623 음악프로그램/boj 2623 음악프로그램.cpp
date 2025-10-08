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
#include <unordered_map>
using namespace std;
vector<int> linkedList[1001];
queue<int> q;
int inDegreeCnt[1001];
vector<int> result;
int n, m;
/*
위상정렬에서 사이클 판단 하는 조건이 하나 생김.
위상정렬 알고리즘을 다 돌린 후에 
indegree갯수 배열에서 만약에 0이 아닌 정점이 있다면 이 그래프는 사이클이 있는 그래프 이므로
0을 출력함
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int count;
        cin >> count;
        vector<int> inputArr(count);

        for (int j = 0; j < count; j++)
        {
            cin >> inputArr[j];
        }
        for (int k = 0; k < count - 1; k++)
        {
            int start = inputArr[k];
            int end = inputArr[k + 1];
            linkedList[start].push_back(end);
            inDegreeCnt[end]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (inDegreeCnt[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for (int i = 0; i < linkedList[cur].size(); i++)
        {
            int next = linkedList[cur][i];
            inDegreeCnt[next]--;
            if (inDegreeCnt[next] == 0)
            {
                q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (inDegreeCnt[i] != 0)
        {
            cout << 0;
            return 0;
        }
    }
    for (int i = 0; i <result.size(); i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}