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
using namespace std;
int N, M;
vector<int> linkedArr[32001];// 그래프 저장할 배열
int inDegreeCnt[32001];// indgree수 저장해 놓을 배열
queue<int> q;//indgree횟수가 0인 정점을 저장해 놓을 큐
vector<int> result;// 결과 배열
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;
        linkedArr[start].push_back(end);
        inDegreeCnt[end]++;
    }
    for (int i = 1; i <= N; i++)
    {
        if (inDegreeCnt[i] == 0)//indgree가 0인 정점을 큐에 삽입
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        result.push_back(cur);// 위상 정렬 배열에다가 삽입
        for (int i = 0; i < linkedArr[cur].size(); i++)
        {
            //이후 현재 정점에서 연결된 모든 정점의 indegreecnt값을 1 감소 시킴 
            int next = linkedArr[cur][i];
            inDegreeCnt[next]--;
            if (inDegreeCnt[next] == 0)
            {
                //그리고 만약에 indegreecnt가 0이 되었다면 그 정점을 큐에다가 삽입
                q.push(next);
            }
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
}