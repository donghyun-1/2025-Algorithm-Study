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
int R, C;
char arr[21][21];
bool alphabet[26];
//각 알파벳 방문여부. 만약에 그 위치의 알파벳이 true라면 배열안에 있는 것이므로 
// dfs할때 그 방향으로는 방문 X
int answer = 0;
void func(int X,int Y,int depth)
{
    answer = max(answer, depth);//--> 백트래킹 할 때 마다 알파벳 갯수를 갱신시켜주자
    int dx[4] = { -1,0,1,0 };
    int dy[4] = { 0,-1,0,1 };
    for (int i = 0; i < 4; i++)
    {
        int nx = X + dx[i];
        int ny = Y + dy[i];
        if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
        int idx = arr[nx][ny] - 'A';
        if (!alphabet[idx])
        {
            alphabet[idx] = true;
            func(nx, ny, depth + 1);
            alphabet[idx] = false;//다시 돌아가기 백트래킹
        }

    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < C; j++)
        {
            arr[i][j] = input[j];
        }
    }
    alphabet[arr[0][0] - 'A'] = true; // 시작 알파벳 방문처리
    func(0, 0, 1);
    cout << answer;
}