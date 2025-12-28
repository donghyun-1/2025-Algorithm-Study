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
int n, m;
int board[101][101];
int air[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
/*
각 칸에 외부공기에 노출된게 2개 이상이면 그 치즈는 다음 시간에 녹아없어지게됨.
이 외부공기를 어케 판단해야할까....
외부공기는 차피 테두리에는 치즈가 없다고 했으니 0 0부터 시작하여 먼저 외부 공기를 판단하고 그다음에 치즈에 관한 조건을 확인하자.
air열 -> 0은 아직 방문 x , 1은 외부공기임.
*/
void clearAirBoard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            air[i][j] = 0;
        }
    }
}
void airBfs()
{
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    air[0][0] = 1;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int curX = cur.second;
        int curY = cur.first;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)continue;
            if (board[ny][nx] != 0)continue;
            if (air[ny][nx] == 1)continue;
            air[ny][nx] = 1;
            q.push({ ny,nx });
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int cheeseCnt = 0;
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                cheeseCnt++;
            }
        }
    }
    while (cheeseCnt)
    {
        clearAirBoard();
        airBfs();
        vector<pair<int, int>> melt;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0)continue;
                int airCnt=0;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = j + dx[dir];
                    int ny = i + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)continue;
                    if (air[ny][nx] != 1)continue;
                    airCnt++;
                }
                if (airCnt >= 2)
                {
                    melt.push_back({ i,j });
                    cheeseCnt--;
                }
            }
        }
        for (int i = 0; i < melt.size(); i++)
        {
            board[melt[i].first][melt[i].second] = 0;
        }
        answer++;
       
    }
    cout << answer;



}