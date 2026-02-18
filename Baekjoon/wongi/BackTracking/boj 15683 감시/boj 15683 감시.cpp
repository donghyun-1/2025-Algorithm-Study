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
0 : 빈칸
1 : 그냥 한 방향만
2 : 두 방향
3 : 90도 두방향
4 : 3방향
5 : 모든 방향
6 : 벽
사각지대의 최소 크기 출력
*/
struct CCTV
{
    int x, y, type;
};
int n, m;
int board[9][9];
int cctvCnt = 0;
int answer = 1e9;
vector<CCTV>cctvs;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//상 하 좌 우
void direct(int y, int x, int dir, int temp[9][9])
{
    dir %= 4;
    while (true)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        if (nx < 0 || ny < 0 || nx >= m || ny >= n) break;
        if (temp[ny][nx] == 6) break;//벽만나면 끝
        if (temp[ny][nx] != 0) continue;
        temp[ny][nx] = -1;
    }
}
void dfs(int count)
{
    if (count == cctvCnt)
    {
        int answerArea = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0)
                {
                    answerArea++;
                }
            }
        }
        answer = min(answer, answerArea);
        return;
    }
    int temp[9][9];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[i][j] = board[i][j];
        }
    }
    //백트래킹 할때 다시 복구해야할때 
    //한 cctv에 대해서 모든 방향의 경우를 돌아보기 위해 . 
    //돌리전에 board의 상태를 저장해 놓고 
    //백트래킹이 끝나면 board상태 복구
    CCTV cur = cctvs[count];
    for (int i = 0; i < 4; i++)
    {
        switch (cur.type)
        {
            case 1:
                direct(cur.y, cur.x, i, board);
                break;
            case 2:
                direct(cur.y, cur.x, i, board);
                direct(cur.y, cur.x, i + 2, board);
                break;
            case 3:
                direct(cur.y, cur.x, i, board);
                direct(cur.y, cur.x, i + 3, board);
                break;
            case 4:
                direct(cur.y, cur.x, i, board);
                direct(cur.y, cur.x, i + 2, board);
                direct(cur.y, cur.x, i + 3, board);
                break;
            case 5:
                direct(cur.y, cur.x, i, board);
                direct(cur.y, cur.x, i + 1, board);
                direct(cur.y, cur.x, i + 2, board);
                direct(cur.y, cur.x, i + 3, board);
                break;
        }
        dfs(count + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = temp[i][j];
            }
        }//백트래킹 끝나서 복구
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int input;
            cin >> input;
            board[i][j] = input;
            if (input != 0 && input != 6)
            {
                cctvCnt++;
                CCTV curinfo;
                curinfo.type = input;
                curinfo.x = j;
                curinfo.y = i;
                cctvs.push_back(curinfo);
            }
        }
    }
    dfs(0);
    cout << answer;
}