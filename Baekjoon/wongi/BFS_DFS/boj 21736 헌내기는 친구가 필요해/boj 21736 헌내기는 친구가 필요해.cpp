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
char board[601][601];
bool isVisited[601][601];
int N, M;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int startX, startY;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = input[j];
            if (input[j] == 'I')
            {
                startX = j;
                startY = i;
            }
        }
    }
    queue<pair<int, int>>  Q;
    Q.push({ startY,startX });
    isVisited[startY][startX] = true;
    int answerCnt = 0;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.second + dx[i];
            int ny = cur.first + dy[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if (board[ny][nx] == 'X') continue;
            if (isVisited[ny][nx]) continue;
            isVisited[ny][nx] = true;
            if (board[ny][nx] == 'P')
            {
                answerCnt++;
            }
            Q.push({ ny, nx });
        }
    }
    if (answerCnt == 0)
    {
        cout << "TT";
    }
    else
    {
        cout << answerCnt;
    }

}