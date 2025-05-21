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
int board[1001][1001];
int length[1001][1001];
bool visited[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int x, y;
	cin >> x >> y;
	int startX;
	int startY;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			int input;
			cin >> input;
			if (input == 2)
			{
				startX = i;
				startY = j;
			}
			board[i][j] = input;
		}
	}

	queue<pair<int, int>>Q;
	visited[startX][startY] = true;
	Q.push({ startX,startY });
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
			if (visited[nx][ny] || board[nx][ny] == 0) continue;
			visited[nx][ny] = true;
			length[nx][ny] = length[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (board[i][j] == 0)//==> 원래 갈 수 없는 땅
				cout << 0 << ' ';
			else if (!visited[i][j])//도달 못한거. ==> 방문이 안된거는 false로 남아 있으니 -1출력
				cout << -1 << ' ';
			else
				cout << length[i][j] << ' ';
		}
		cout << '\n';
	}
}
