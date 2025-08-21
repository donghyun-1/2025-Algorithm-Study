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
vector<pair<int,int>> board;//x축 y축 거리
vector<int>dist;
/*
오답노트 
1. 일단 맨처음에 풀었을 때 
if (abs(bx - 0) <= 2 && abs(by - 0) <= 2)
        {
            dist[i] = 1;
            q.push(i);
        }
이런식으로 비슷하게 전체 탐색을 하게 했음.
즉 x축과 y축 둘다 저 조건에 맞았을때 탐색을 하게 해서 
둘중 하나 조건에 맞아도 다른 하나 때문에 이미 이동이 불가능한 상태에서도 탐색을 해야했음
따라서 시간초과가 계속 남
2. 따라서 x축 기준으로 오른쪽 왼쪽 둘다 bfs를 돌려 조건에 맞으면 큐에 넣고 길찾기를 실행해서 
불필요한 경로를 탐색하지 않게함


*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    cin >> n >> t;

    dist.assign(n, -1);
    board.resize(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        board[i] = { x, y }; // x 먼저 저장
    }

    // x 기준 정렬
    sort(board.begin(), board.end());

    queue<int> q;

    // 시작점에서 바로 갈 수 있는 발판
    for (int i = 0; i < n; i++)
    {
        int bx = board[i].first;
        int by = board[i].second;
        if (abs(bx - 0) <= 2 && abs(by - 0) <= 2)
        {
            dist[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int x = board[cur].first;
        int y = board[cur].second;
        int d = dist[cur];

        if (y >= t) // 목표 도달
        {
            cout << d;
            return 0;
        }

        // 오른쪽 탐색 (x 증가 방향)
        for (int i = cur + 1; i < n; i++)
        {
            int nx = board[i].first;
            if (nx - x > 2) break; // x차이가 2 초과하면 중단 --> 전체탐색 하지 않게 하기위함.
            if (dist[i] != -1) continue;
            int ny = board[i].second;
            if (abs(y - ny) <= 2)
            {
                dist[i] = d + 1;
                q.push(i);
            }
        }

        // 왼쪽 탐색 (x 감소 방향)
        for (int i = cur - 1; i >= 0; i--)
        {
            int nx = board[i].first;
            if (x - nx > 2) break;
            if (dist[i] != -1) continue;
            int ny = board[i].second;
            if (abs(y - ny) <= 2)
            {
                dist[i] = d + 1;
                q.push(i);
            }
        }
    }
    cout << -1;
    return 0;
}