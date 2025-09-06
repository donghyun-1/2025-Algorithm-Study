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
int dist[301][301];
void clear()
{
    for (int i = 0; i < 301; i++)
    {
        for (int j = 0; j < 301; j++)
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
    int dx[8] = { -1,1,2,2,1,-1,-2,-2 };
    int dy[8] = { -2,-2,-1,1,2,2,1,-1 };
    int count;
    cin >> count;
    while (count--)
    {
        clear();
        int boardSize, startX,startY,endX,endY;
        cin >> boardSize;
        cin >> startX >> startY;
        cin >> endX >> endY;
        queue<pair<int, int>> q;
        q.push({ startX,startY });
        dist[startX][startY] = 0;
        while (!q.empty())
        {
            pair<int, int> cur = q.front(); q.pop();
            if (cur.first == endX && cur.second == endY)
            {
                cout << dist[endX][endY] << '\n';
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx < 0 || nx >= boardSize || ny < 0 || ny >= boardSize)continue;
                if (dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push({ nx, ny });
            }

        }
        
    }

}