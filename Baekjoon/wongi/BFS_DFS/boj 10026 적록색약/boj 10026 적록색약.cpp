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
char board[100][100];
int visit[100][100];
int visit2[100][100];
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char input;
			cin >> input;
			board[i][j] = input;
		}
	}
	int person = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] != 1)
			{
				queue<pair<int, int>>Q;
				Q.push({ i,j });
				visit[i][j] = 1;
				person++;
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int curX = cur.first + dx[dir];
						int curY = cur.second + dy[dir];
						if (curX < 0 || curX >= n || curY < 0 || curY >= n) continue;
						if (visit[curX][curY] == 1 || board[i][j] != board[curX][curY]) continue;
						visit[curX][curY] = 1;
						Q.push({ curX,curY });
					}
				}
			}
		}
	}
	//--> 색약 용 보드로 변경
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'R')
			{
				board[i][j] = 'G';
			}
		}
	}
	int person2 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit2[i][j] != 1)
			{
				queue<pair<int, int>>Q2;
				Q2.push({ i,j });
				visit2[i][j] = 1;
				person2++;
				while (!Q2.empty())
				{
					pair<int, int> cur = Q2.front(); Q2.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int curX = cur.first + dx[dir];
						int curY = cur.second + dy[dir];
						if (curX < 0 || curX >= n || curY < 0 || curY >= n) continue;
						if (visit2[curX][curY] == 1 || board[i][j] != board[curX][curY]) continue;
						visit2[curX][curY] = 1;
						Q2.push({ curX,curY });
					}
				}
			}
		}
	}
	cout << person<< " " << person2;
}