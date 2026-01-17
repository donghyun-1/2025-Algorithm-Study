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
#include<cstring>
using namespace std;
int n, m;
/*
파란색은 구멍에 들어가면 안됨
동시에 구멍에 들어가도 안됨
*/
char board[11][11];
int visited[11][11][11][11];
/*
빨간, 파랑 구슬 각각의 방문을 한번에 관리 해야하므로 4차원으로 방문처리 관리
현재의 구슬들이 위치에 있을때 기울임 횟수로 정의함
*/

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
struct curPos
{
    int ry;
    int rx;
    int by;
    int bx;
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int rX, rY, bX, bY, endX, endY;
    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            if (input[j] == 'R')
            {
                rX = j;
                rY = i;
            }
            if (input[j] == 'B')
            {
                bX = j;
                bY = i;
            }
            if (input[j] == 'O')
            {
                endX = j;
                endY = i;
            }
            board[i][j] = input[j];
        }
    }

    queue<curPos> q;
    curPos start;
    start.rx = rX;
    start.ry = rY;
    start.bx = bX;
    start.by = bY;
    visited[rY][rX][bY][bX] = 0;
    q.push(start);
    int answer = 0;
    while (!q.empty())
    {
        curPos cur = q.front();
        q.pop();
        int curRY = cur.ry;
        int curRX = cur.rx;
        int curBY = cur.by;
        int curBX = cur.bx;
        int count = visited[curRY][curRX][curBY][curBX];
        if (count == 10)continue;// 기울인 횟수가 10번 이면 끝

        for (int i = 0; i < 4; i++)
        {
            int nrY = curRY;
            int nrX = curRX;
            int nbY = curBY;
            int nbX = curBX;
            while (true)
            {
                if (board[nrY][nrX] != '#' && board[nrY][nrX] != 'O')
                {
                    nrY += dy[i];
                    nrX += dx[i];
                }
                else
                {
                    if (board[nrY][nrX] == '#')
                    {
                        nrY -= dy[i];
                        nrX -= dx[i];
                        //벽만났으니 이전 위치로 이동
                    }
                    break;
                }
            }
            //파란색 이동
            while (true)
            {
                if (board[nbY][nbX] != '#' && board[nbY][nbX] != 'O')
                {
                    nbY += dy[i];
                    nbX += dx[i];
                }
                else
                {
                    if (board[nbY][nbX] == '#')
                    {
                        nbY -= dy[i];
                        nbX -= dx[i];
                    }
                    //벽만났으니 이전 위치로 이동
                    break;
                }
            }
            if (board[nbY][nbX] == 'O') continue;//파란구슬 빠지면 실패
            if (board[nrY][nrX] == 'O')//빨간 구슬만 빠지면 성공
            {
                cout << count + 1 << "\n";
                return 0;
            }


            if (nrY == nbY && nrX == nbX)//빨 파 구슬이 겹칠경우 왼쪽 또는 오른쪽으로 구슬을 겹치지 않게 올바르게 이동시켜줘야함
            {
                if (board[nrY][nrX] != 'O')
                {
                    int redDist = abs(nrY - curRY) + abs(nrX - curRX);
                    int blueDist = abs(nbY - curBY) + abs(nbX - curBX);
                    if (blueDist > redDist)// 파란 구슬이 더 멀리에서 왔다면
                    {
                        nbY -= dy[i];
                        nbX -= dx[i];//그 이전 위치로 위치 보정
                    }
                    else
                    {
                        nrY -= dy[i];
                        nrX -= dx[i];
                    }
                }
            }
            if (visited[nrY][nrX][nbY][nbX] == -1)
            {
                visited[nrY][nrX][nbY][nbX] = count + 1;
                curPos start;
                start.rx = nrX;
                start.ry = nrY;
                start.bx = nbX;
                start.by = nbY;

                q.push(start);
            }
        }
    }
    cout << -1;
}