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
int board[9][9];
bool visited[9][9];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int n, m;
void clear()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }
}
int safeZone()
{
   
    clear();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 2)
            {
                q.push({ i,j });
            }
        }
    }
    while (!q.empty())
    {
        pair<int, int>cur = q.front(); q.pop();
        int x = cur.second;
        int y = cur.first;
        for (int d = 0; d < 4; d++)
        {
            int nextX = x + dx[d];
            int nextY = y + dy[d];
            if (nextY < 0 || nextX < 0 || nextY >= n || nextX >= m) continue;
            if (visited[nextY][nextX]) continue;
            if (board[nextY][nextX] != 0) continue;
            visited[nextY][nextX] = true;
            q.push({nextY,nextX});
        }
    }
    int safeZoneCnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0 && !visited[i][j])
                safeZoneCnt++;
        }
    }
    return safeZoneCnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    /*
    0 - 빈칸
    1 - 벽
    2 - 바이러스
    --> 보드에서 벽을 3개 세운뒤 바이러스가 퍼질 수 없는 곳을 안전 영역이라함.
    --> 안전영역 크기의 최댓값을 구하자.
    예제 입력 2
    0 0 0 0 x 0
    1 0 0 x 0 2
    1 1 1 0 0 2
    0 0 0 x 0 2
    --> 이렇게 세워야 최대 영역이 나옴    
    그냥 하드로 다가 나올 수 있는 모든 3개의 벽 위치를 해놓고 max값을 갱신시키는 걸로 해야할 듯함.
    생각나는건 그것 밖에 없음
    */


    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int boardSize = n * m;
    int answer = 0;
    for (int i = 0; i < boardSize; i++)
    {
        int y1 = i / m;//y
        int x1 = i % m;//x
        if (board[y1][x1] != 0) continue;
        for (int j = i + 1; j < boardSize; j++)
        {
            int y2 = j / m;
            int x2 = j % m;
            if (board[y2][x2] != 0) continue;
            for (int k = j + 1; k < boardSize; k++)
            {
                int y3 = k / m;
                int x3 = k % m;
                if (board[y3][x3] != 0) continue;
           
                
                board[y1][x1] = 1;
                board[y2][x2] = 1;
                board[y3][x3] = 1;
                answer = max(answer, safeZone());
                board[y1][x1] = 0;
                board[y2][x2] = 0;
                board[y3][x3] = 0;


            }
        }

    }
    cout << answer;
}