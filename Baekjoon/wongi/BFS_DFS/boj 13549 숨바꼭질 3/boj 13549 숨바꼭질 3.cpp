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
vector<int> dist;
/*

오답노트 
기본적인 bfs문제
그러나 맨처음에는 bfs를 돌릴때 +1,-1, 순간이동 이렇게 해서 문제를 풀었더니
7%에서 자꾸 오답이 나옴.

다시 생각해보니. 
애초에 순간이동이 +1,-1 보다 더 빠르게 이동할 수 있으니
일단 먼저 되든 안되든 순간이동 부터 먼저 하고 그 이후에 +1,-1을 해야 최단거리를 갱신하여
정답을 찾을 수 있음

+1,-1로 먼저 시작하면 순간이동으로 더 빨리 이동할 수 있음에도 불구하고 
먼저 방문처리를 해버리므로 일단 먼저 순간이동을 사용해 더 빠른 경로를 탐색하자

*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    dist.resize(100001, -1);
    queue<int> q;
    q.push(N);
    dist[N] = 0;
    while (!q.empty())
    {
        int now = q.front(); q.pop();
        // 2*x (순간이동: 0초)
        if (now * 2 <= 100000 && dist[now * 2] == -1)
        {
            dist[now * 2] = dist[now];
            q.push(now * 2);
        }
        // x-1
        if (now - 1 >= 0 && dist[now - 1] == -1) 
        {
            dist[now - 1] = dist[now] + 1;
            q.push(now - 1);
        }
        // x+1
        if (now + 1 <= 100000 && dist[now + 1] == -1) 
        {
            dist[now + 1] = dist[now] + 1;
            q.push(now + 1);
        }
     
    }
    cout << dist[K];

}