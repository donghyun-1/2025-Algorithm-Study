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
/*
3차원 bfs문을 이용해서 시작 지점에서 끝지점 까지 최소 거리 출력
시작 지점 찾으면 큐에 넣고 
조건에 알맞게 bfs문을 돌리는데
만약에 돌리다가 도착점을 만나면 bfs멈추고 시간 출력
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dx[6] = { 1,0,-1,0,0,0 };
    int dy[6] = { 0,1,0,-1,0,0 };
    int dh[6] = { 0,0,0,0,1,-1 };//위,아래층

    while (true)
    {
        int L, R, C;
        cin >> L >> R >> C;

        if (L == 0 && R == 0 && C == 0) break;
        char arr[31][31][31];
        int dist[31][31][31] = {0};
        queue<tuple<int, int, int>> Q;
        bool isOver = false;

        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int a = 0; a < C; a++)
                {
                    cin >> arr[i][j][a];
                    if (arr[i][j][a]=='S')
                    {
                        Q.push({ i,j,a });
                        dist[i][j][a] = 0;//시작 지점 거리 초기화
                    }
                    else if (arr[i][j][a]=='.')
                    {
                        dist[i][j][a] = -1;
                    }
                }
            }
        }
        while (!Q.empty())
        {
            if (isOver) break;
            tuple<int, int, int> cur = Q.front(); Q.pop();
            for (int i = 0; i < 6; i++)
            {
                int nx = dx[i] + get<1>(cur);
                int ny = dy[i] + get<2>(cur);
                int nh = dh[i] + get<0>(cur);
                if (nx < 0 || nx >= R || ny < 0 || ny >= C || nh < 0 || nh >= L) continue;
                if (arr[nh][nx][ny] == '#' || dist[nh][nx][ny] > 0)continue;
                dist[nh][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;//목표 지점까지 각각 거리를 갱신시켜줌
                if (arr[nh][nx][ny] =='E')
                //거리를 갱신시키다가 끝지점을 만나면 이제 정답 출력 및 다시 BFS못돌리게 BREAK할수 있게
                // isOver을 true로 바꾸고 끝내버림
                {
                    cout << "Escaped in "<< dist[nh][nx][ny] << " minute(s).\n";
                    isOver = true;
                    break;
                }
                Q.push({ nh,nx,ny });
            }
        }
        if (!isOver)//bfs를 돌려도 e를 못만나면 trapped출력
        {
            cout << "Trapped!\n";
        }
        
    }
}