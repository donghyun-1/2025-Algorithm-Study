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
/*
주요 조건 : 먼저 몸길이를 늘리고
머리를 다음칸에 위치 시키기.
그 이후에 사과 있는지 없는지 확인.

*/
int n, k, l;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
//위, 우, 아래, 좌
int board[101][101];
deque<pair<int, int>> snake;
queue<pair<int, string>> timeDir; //방향 정보
int answerTime;
int dir = 1;// 방향. 
//1-> 사과 있는 곳.
void func(char command)
{
    switch (command)
    {
    case 'D':
        dir = (dir + 1) % 4;
        break;
    case 'L':
        dir = (dir + 3) % 4;
        break;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    int l;
    cin >> l;

    for (int i = 0; i < l; i++)
    {
        int time;
        string dir;
        cin >> time >> dir;
        timeDir.push({ time,dir });
    }

    snake.push_front({ 1,1 });//1,1부터 시작 
    board[1][1] = 2;
    while (true)
    {
        answerTime++;
        pair<int, int> cur = snake.front(); 
        int nx = cur.second + dx[dir];
        int ny = cur.first + dy[dir];
        if ((nx < 1 || ny < 1 || ny > n || nx > n)||board[ny][nx] == 2)//범위 밖에 나가면 break 후 정답 출력
        {
            break;
        }
        snake.push_front({ ny,nx }); //먼저 머리 부분 위치 옮기고
        if (board[ny][nx] == 1)// 사과 있으면
        {
            board[ny][nx] = 2;//뱀 몸통으로 표시하고
            //그냥 꼬리 부분은 남게
        }
        else// 사과 없으면 꼬리 부분 0으로 처리해줘야함.
        {
            board[ny][nx] = 2;
            pair<int, int> tail = snake.back();// 뱀 현재 위치들에서 뒤에 즉 꼬리 부분을 가져와서
            board[tail.first][tail.second] = 0;//꼬리 위치를 0으로 초기화
            snake.pop_back();
        }
     
        if (!timeDir.empty() && timeDir.front().first == answerTime)
        {
            char command = timeDir.front().second[0];
            func(command);
            timeDir.pop();
        }
    }
    cout << answerTime;
}