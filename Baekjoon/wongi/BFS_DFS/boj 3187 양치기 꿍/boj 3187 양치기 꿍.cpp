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
char board[251][251];
bool visited[251][251];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    int R, C;
    cin >> R >> C;
    
    int sheep = 0;
    int wolf = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j]!='#' && visited[i][j] == false)
            {
                int curSheep = 0;
                int curWolf = 0;
                queue<pair<int, int>>Q;
                visited[i][j] = true;
                Q.push({ i,j });

                if (board[i][j] == 'k')
                {
                    curSheep++;
                }
                if (board[i][j] == 'v')
                {
                    curWolf++;
                }
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int curY = cur.first + dy[dir];
                        int curX = cur.second + dx[dir];
                        if (curX < 0 || curX >= C || curY < 0 || curY >= R) continue;
                        if (visited[curY][curX] || board[curY][curX] == '#')continue;
                        if (board[curY][curX] == 'k')
                        {
                            curSheep++;
                        }
                        else if (board[curY][curX] == 'v')
                        {
                            curWolf++;
                        }
                        visited[curY][curX] = true;
                        Q.push({ curY,curX });
                    }
                }
                if (curSheep > curWolf)
                {
                    sheep += curSheep;
                }
                else
                {
                    wolf += curWolf;
                }
            }
        }
    }
    cout << sheep << ' ' << wolf;

}