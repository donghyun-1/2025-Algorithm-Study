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
#include <cstring>
using namespace std;
/*
////////입력
1. N(격자 크기) M(상어 마리수) K (냄새가 사라지는 시간.)
2. N개의 줄에 걸쳐 격자의 모습 주어짐

0은 빈칸, 나머지는 X번 상어가 들어가 있는 칸.
3. 각 상어 방향 입력
1  2    3    4
위 아래 왼쪽 오른쪽

4.0 상어 방향 우선순위가 각 상어당 4개씩 주어짐
4.1 상어위 아래 왼쪽 오른쪽순서대로 우선순위가 주어짐
    이동하기전에 우선순위에 따라서 갈수 있는지 없는지 확인하고 그 우선순위에 따라서 상어를 이동시킴


////////출력
1번상어만 남았을때 걸리는 시간.
만약에 1000초가 넘었을때 다른 상어가 격자에 있으면 -1출력
*/
struct Shark
{
    int x, y;// 현재 상어가 있는 방향
    int dir;//현재 바라보고 있는 방향
    bool isDead;//상어 생사
    int priority[4][4];//각 방향마다 우선순위
};
pair<int, int> smell[21][21];
//좌표
//.first -> 냄새 주인 번호
//.second -> 냄새 남은 시간
Shark shark[401];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n, m, k;
int answer = 0;
int checkBoard[21][21];
void updateTime()// 테이블 시간 업데이트
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (smell[i][j].second != 0)
            {

                smell[i][j].second--;
                if (smell[i][j].second == 0)
                {
                    smell[i][j].first = 0;
                }
            }
        }
    }
}
void updateSmell()
{
    for (int i = 1; i <= m; i++)
    {
        if (shark[i].isDead) continue;
        smell[shark[i].y][shark[i].x] = { i,k };
    }
}
void moveShark(int sharkIdx)
{
    bool cantMove = false;
    int x = shark[sharkIdx].x;
    int y = shark[sharkIdx].y;
    int curDir = shark[sharkIdx].dir;

    int nextDir = -1;
    int nextX = -1;
    int nextY = -1;
    for (int i = 0; i < 4; i++)
    {
        int dir = shark[sharkIdx].priority[curDir][i];
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (smell[ny][nx].first == 0)//한번에 빈칸 찾으면 
        {
            nextDir = dir;
            nextX = nx;
            nextY = ny;
            cantMove = true;
            break; // 우선순위 높은 곳을 찾았으니 즉시 종료
        }

    }
    if (!cantMove)//4방향다 못가는 곳이면 그중에서 내 냄새를 찾아서 이동
    {
        for (int i = 0; i < 4; i++)
        {
            int dir = shark[sharkIdx].priority[curDir][i];
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (smell[ny][nx].first == sharkIdx)//내 냄새를 찾으면 이제 그 위치로 다시 갱신.
            {
                nextDir = dir;
                nextX = nx;
                nextY = ny;
                break;
            }
        }
    }
    shark[sharkIdx].x = nextX;
    shark[sharkIdx].y = nextY;
    shark[sharkIdx].dir = nextDir;
    if (checkBoard[nextY][nextX] == 0)
    {
        checkBoard[nextY][nextX] = sharkIdx;
    }
    else
    {
        shark[sharkIdx].isDead = true;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            if (input != 0)
            {
                shark[input].y = i;
                shark[input].x = j;
                smell[i][j] = { input,k };
                shark[input].isDead = false;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int dir;
        cin >> dir;
        shark[i].dir = dir - 1;
    }//시작하기전 맨처음에 상어가 보고 있는 방향 init

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int dirP;
                cin >> dirP;
                shark[i].priority[j][k] = dirP - 1;
            }
        }
    }

    while (answer < 1000)
    {
        memset(checkBoard, 0, sizeof(checkBoard));
        for (int i = 1; i <= m; i++)
        {
            if (shark[i].isDead) continue;
            moveShark(i);
        }


        updateTime();
        updateSmell();
        answer++;
        int check=false;
        for (int i = 2; i <= m; i++)//1번상어 제외 살아있는거 있으면 -1
        {
            if (shark[i].isDead == false)
            {
                check = true;
                break;
            }
        }

        if (!check)
        {
            cout << answer<<'\n';
            return 0;
        }
       
    }
    cout << -1<< '\n';
    return 0;
}