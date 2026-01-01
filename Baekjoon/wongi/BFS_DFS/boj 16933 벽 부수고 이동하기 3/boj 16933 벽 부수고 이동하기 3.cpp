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
int n, m, k;
/*
밤 낮이 바뀜.
벽은 낮에만 부술 수 있음.
벽을 k개까지 부수고 이동 가능
이동을 안하고 같은 칸에 머물러 있는것 즉 이것도 거리 +1
*/
int board[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int Dist[1001][1001][11][2];
/*
 [y][x][벽 부순 개수][낮:0 밤:1]
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int answer = 0;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        string input;
        cin >> input;
        for (int j = 1; j <= m; j++)
        {
            board[i][j] = input[j - 1] - '0';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int a = 0; a <= k; a++)
            {
                for (int d = 0; d < 2; d++)
                {
                    Dist[i][j][a][d] = -1;
                }
            }
        }
    }

    queue<tuple<int, int, int, int>> q;
    Dist[1][1][0][0] = 1;
    q.push({ 1,1,0,0 });
    while (!q.empty())
    {
        tuple<int, int, int, int> cur = q.front();
        q.pop();
        int curY = get<0>(cur);
        int curX = get<1>(cur);
        int breakRoom = get<2>(cur);
        int isDay = get<3>(cur);
        if (curY == n && curX == m)
        {
            answer = Dist[n][m][breakRoom][isDay];
            break;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx<1 || ny<1 || nx>m || ny>n) continue;
            if (Dist[ny][nx][breakRoom][1-isDay] != -1) continue;//0이 낮, 1이 밤.낮 또는 밤에 첫 방문이 아니라면
            if (board[ny][nx] == 0 && Dist[ny][nx][breakRoom][1 - isDay] == -1)//그냥 단순히 이동 가능한 위치 일 때
            {
                Dist[ny][nx][breakRoom][1 - isDay] = Dist[curY][curX][breakRoom][isDay] + 1;
                q.push({ ny,nx,breakRoom,1 - isDay });
            }
            if (board[ny][nx] == 1 && isDay == 0 && breakRoom < k)//다음게 벽이고 / 낮이고, 벽 부술수 있는 횟수 남아 잇을때.
            {
                if (Dist[ny][nx][breakRoom + 1][1] == -1)
                {
                    Dist[ny][nx][breakRoom + 1][1] = Dist[curY][curX][breakRoom][0] + 1;// 낮 다음에 밤이므로 밤 거리 갱신
                    q.push({ ny,nx,breakRoom + 1,1 });//밤으로 이동
                }
            }
            if (board[ny][nx] == 1 && isDay == 1)//밤이고 다음칸이 벽일때
            {
                if (Dist[ny][nx][breakRoom][0] == -1)//같은 위치 아직 방문 안했다면. 
                {
                    Dist[curY][curX][breakRoom][0] = Dist[curY][curX][breakRoom][1] + 1;
                    //이동 시키지 않고 그냥 그대로 그자리에서 이동 거리만 갱신시켜주고
                    //낮으로 이동한거를 Q에 삽입
                    q.push({ curY,curX,breakRoom,0 });
                }
            }
        }
      
    }
    if (answer == 0)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}