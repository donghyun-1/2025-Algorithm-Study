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
vector<vector<int>> graph;
vector<vector<int>>minDist;
int N, M;
//다익스트라 알고리즘 사용
void bfs()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			minDist[i][j] = 10000000;
		}
	}
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	priority_queue<pair<int,pair<int, int>>> pq;
	//<벽 부순 횟수,{좌표x,좌표 y} >
	pq.push({ 0,{0,0} });
	minDist[0][0] = 0;
	while (!pq.empty())
	{
		//현재 탐색할 위치 정보
		int dist = -pq.top().first;//벽부순 횟수 
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		//현재 좌표


		pq.pop();
		// 이미 방문한 위치의 최솟값이 현재 값보다 작다면 무시
		if (minDist[x][y] < dist)continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			// 다음 위치로 갈 때 벽을 부수는 횟수 계산 (벽이면 +1, 아니면 0)
			int nextDist = dist + graph[nx][ny];

			if (nextDist < minDist[nx][ny])
			{
				minDist[nx][ny] = nextDist;
				pq.push({ -nextDist,{nx,ny} });
			}
		}

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> M >>N ;
	graph.resize(N, vector<int>(M));
	minDist.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < M;j++)
		{
			graph[i][j] = input[j] - '0';
		}
	}
	

	bfs();
	cout << minDist[N - 1][M - 1];
	

	
}