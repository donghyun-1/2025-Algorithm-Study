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
bool visited[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int m, n, k;
	cin>>m>>n>>k;
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				visited[i][j] = true;
			}
		}//사각형범위를 방문상태로 변환
	}
	vector<int> answerArr;
	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			int area=1;//한 영역당 넓이
			if (!visited[i][j])
			{
				answer++;// 영역 갯수
				queue<pair<int, int>>Q;
				visited[i][j] = true;
				Q.push({ i,j });
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (visited[nx][ny]) continue;
						visited[nx][ny] = true;
						Q.push({ nx,ny });
						area++;
					}
				}
				answerArr.push_back(area);
			}
			
		}
	}
	cout << answer<<'\n';
	sort(answerArr.begin(), answerArr.end());
	for (int i = 0; i < answer; i++)
	{
		cout << answerArr[i] << " ";
	}

}