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
int board[51][51];
int dist[51][51];
int n, m;
int main()
{
	//모든 공간에 대해 안전거리를 구하는것
	//상어와 상어 사이의 안전거리를 구하는 것이 아님;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[8] = { 1,0,-1,0,-1,1,1,-1 };
	int dy[8] = { 0,1,0,-1,-1,-1,1,1 };
	vector<int>sharkX;
	vector<int>sharkY;
	cin >> n >> m;
	queue<pair<int, int>>Q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int input;
			cin >> input;
			board[i][j] = input;
			dist[i][j] = -1;
			if (input == 1)
			{
				dist[i][j] = 0;//거리 계산할 준비.
				Q.push({ i,j });
			}
		}
	}

	vector<int>answer;
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 8; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{

	//		cout << dist[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] > ans) {
				ans = dist[i][j];
			}
		}
	}
	cout << ans;
	
}