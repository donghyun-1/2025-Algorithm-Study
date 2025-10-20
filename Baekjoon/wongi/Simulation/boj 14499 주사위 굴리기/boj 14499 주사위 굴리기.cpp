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
int n, m, x, y, k;
int board[21][21];
int dice[6];//0->위 1->아래 2-> 북 3-> 동 4-> 서 5-> 남
void rollDice(int command)//주사위를 굴릴때 각 면들이 바뀔때 배열에서도 바꿔줘야함.
{
    int temp = dice[0];
    switch (command)
    {
    case 1:// 동
        dice[0] = dice[4];//윗면 -> 서
        dice[4] = dice[1];//서 -> 아래면
        dice[1] = dice[3];//아래면 -> 동
        dice[3] = temp;   //동 -> 윗면
        break;
    case 2://서
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
        break;
    case 3://북
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
        break;
    case 4://남
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
        break;

    }
}
int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
       1 동 -> 오른쪽
       2 서 -> 왼쪽
       3 북 -> 위
       4 남 -> 아래
    */
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    cin >> n >> m >> x >> y >> k;
    //지도 세로 / 가로 / 주사위 놓은 곳 좌표 / 명령 횟수
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int command;
        cin >> command;
        int nx = x + dx[command - 1];
        int ny = y + dy[command - 1];
        //번호에 따라 이동
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        //만약 범위 넘어가면 이동 , 주사위 굴리기 x
        x = nx;
        y = ny;//이동
        rollDice(command);
        
        if (board[x][y] == 0)//주사위의 바닥면에 쓰여있는 수가 칸에 복사됨.
        {
            board[x][y] = dice[1];
        }
        else//칸에 쓰여있는 수가 주사위의 바닥면으로 복사됨
        {
            dice[1] = board[x][y];
            board[x][y] = 0;
        }
        cout << dice[0] << '\n';
    }


}