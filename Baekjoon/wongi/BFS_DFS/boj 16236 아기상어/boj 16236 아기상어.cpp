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
int board[21][21];
int dist[21][21];
int boardSize;
void clear()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            dist[i][j] = -1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    int initSize = 2;
    queue<pair<int, int>>q;
    cin >> boardSize;
    clear();
    int eatCnt = 0;//상어가 물고기 먹은 횟수
    int sharkX, sharkY;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                q.push({ i,j });
                sharkX = i; sharkY = j;
                dist[i][j] = 0;//처음 아기상어 찾기 + 방문처리
                board[i][j] = 0;//빈칸처리
            }
        }
    }

    int totalTime = 0;
    //상어가 더이상 먹을 수 있는 물고기가 없을때 까지 반복
    while (true)
    {
        clear();
        queue<pair<int, int>> q;
        q.push({ sharkX, sharkY });
        dist[sharkX][sharkY] = 0;

        int minDist = 1e9;
        int fx = -1, fy = -1;//먹을 물고기 좌표

        // BFS: dist 모두 갱신 & 먹을 수 있는 가장 가까운 물고기 찾기
        while (!q.empty())
        {
            q.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = q.front().first + dx[dir];
                int ny = q.front().second+ dy[dir];

                if (nx < 0 || ny < 0 || nx >= boardSize || ny >= boardSize) continue;
                if (dist[nx][ny] != -1) continue;
                if (board[nx][ny] > initSize) continue;//상어보다 작은 물고기만 먹을 수 있음.
                dist[nx][ny] = dist[q.front().first][q.front().second] + 1;

                // 먹을 수 있는 물고기 여러마리 일 때
                if (board[nx][ny] >= 1 && board[nx][ny] < initSize) 
                {
                    // 조건 1: 더 가까움
                    if (dist[nx][ny] < minDist) 
                    {
                        minDist = dist[nx][ny];
                        fx = nx;
                        fy = ny;
                    }
                    // 조건 2: 거리가 같으면 위,왼쪽 우선
                    else if (dist[nx][ny] == minDist) 
                    {
                        if (nx < fx || (nx == fx && ny < fy)) 
                        {
                            fx = nx;
                            fy = ny;
                        }
                    }
                }// --> 최소거리 위치의 물고기 위치를 갱신해줌
                q.push({ nx, ny });
            }
        }

        // 더 이상 먹을 수 있는 물고기가 없으면 끝
        if (fx == -1 && fy == -1) break;

        // 상어 위치, 크기, eatCnt, 시간 갱신
        sharkX = fx;
        sharkY = fy;
        board[fx][fy] = 0;//먹었으면 빈칸처리
        totalTime += minDist;
        eatCnt++;

        if (eatCnt == initSize)
        // 상어가 물고기 잡아먹은 횟수가 현재 사이즈랑 같아지면 상어 레벨업 --> 더 큰 크기의 물고기를 잡아먹기
        {
            initSize++;
            eatCnt = 0;
        }
    }
    cout << totalTime;
    return 0;
}