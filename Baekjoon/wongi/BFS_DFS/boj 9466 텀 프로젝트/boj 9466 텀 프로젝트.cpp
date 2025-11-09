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
int t, n;
vector<int> arr;
vector<int> visited;
vector<bool> inCycle;
/*
각각 연결된 그래프가 한 사이클을 이루면 그 사이클에 있는 노드는 
짝을 이룬것.
자기 자신을 선택해도 그것또한 짝을 이룬것
visited[]의 상태
0 -> 아직 방문 안함
1 -> 방문 중에 있음 (사이클 판단중에 있음)
2 -> 사이클 판단 끝.
*/
void dfs(int node)
{
    visited[node] = 1;// 현재 노드를 사이클 판단 상태로 변경.
    int next = arr[node];// 현재 노드가 선택한 다음 노드
    if (visited[next] == 0)
    {
        dfs(next);
    }
    else if (visited[next] == 1)//
    {
        for (int i = next; i != node; i = arr[i])//i 가 자기 자신이 될때 까지 반복.
        {
            inCycle[i] = true;//사이클 포함된 모든 노드를 true처리
        }
        inCycle[node] = true; // 맨 마지막에 자기 자신도 포함 
    }
    visited[node] = 2;//현재 노드 탐색 완.
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while (t--)
    {
        cin >> n;
        arr.assign(n + 1,0);
        visited.assign(n + 1, 0);
        inCycle.assign(n + 1, false);

        for (int i = 1; i <= n; i++)
        {
            int input;
            cin >> input;
            arr[i] = input;
        }

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }
        int answer = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!inCycle[i])// 이 값이 false면 현재 팀을 이루지 못한 인원임
            {
                answer++;
            }
        }
        cout << answer<<'\n';
    }
    
}