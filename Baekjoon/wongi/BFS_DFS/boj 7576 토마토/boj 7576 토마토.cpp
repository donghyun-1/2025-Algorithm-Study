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
int arr[1001][1001];
int minDist[1001][1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { 1,-1,0,0 };
    int M, N;
    cin >> M >> N;
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                q.push({ i,j });
            }
            if (arr[i][j] == 0)
            {
                minDist[i][j] = -1;
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = cur.first + dx[i];
            int nextY = cur.second + dy[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
            if (minDist[nextX][nextY] != -1) continue;;
            minDist[nextX][nextY] = minDist[cur.first][cur.second] + 1;
            q.push({ nextX,nextY });
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (minDist[i][j] == -1)
                //mindist배열에서 -1이 하나라도 있으면 토마토가 있는 부분을 방문 못했다는 의미로 안익은 토마토가 있다라는 의미
            {
                cout << -1;
                return 0;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (answer < minDist[i][j])
            {
                answer = minDist[i][j];
            }
        }
    }
    cout << answer << '\n';

}