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
int board[101][101];
bool visited[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	for (int i = 0; i <count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			cin >> board[i][j];
		}
	}
	int maxHeight = board[0][0];
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (board[i][j] > maxHeight)
				maxHeight = board[i][j];
		}
	}//제일 높은 높이의 수 찾기

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	vector<int>answer;
	for (int height = 0; height <= maxHeight; height++)//제일 높은 높이 수 만큼 bfs돌리기
	{
		int count1 = 0;
		for (int i= 0; i< count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				if (board[i][j] > height && !visited[i][j])//그래서 만약에 지금 현재 높이 수보다 크면 안전영역으로 카운트
				{
					count1++;
					queue<pair<int, int>>Q;
					visited[i][j] =true;
					Q.push({ i,j});
					while (!Q.empty())
					{
						pair<int, int> cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= count || ny < 0 || ny >= count) continue;
							if (visited[nx][ny] || board[nx][ny]<= height) continue;
							visited[nx][ny] = true;
							Q.push({ nx,ny });
						}
					}
				}
			}
		}
		answer.push_back(count1);
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				visited[i][j] = 0;
			}
		}
	}
	cout<<*max_element(answer.begin(),answer.end());
}