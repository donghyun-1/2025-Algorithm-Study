// https://www.acmicpc.net/problem/14226
// 이모티콘 (골드 4)
// 2025-11-10

#include <iostream>
#include <queue>

using namespace std;

struct Point {
	int screen, clip, time;
};

int S;
bool visited[2001][2001];	// 화면, 클립보드

void input()
{
	cin >> S;
}

int bfs()
{
	queue<Point> q;
	q.push({1, 0, 0});
	visited[1][0] = true;

	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		if (curr.screen == S) return curr.time;

		if (curr.screen > 0) {
			// 클립보드에 저장
			if (!visited[curr.screen][curr.screen]) {
				visited[curr.screen][curr.screen] = true;
				q.push({curr.screen, curr.screen, curr.time+1});
			}

			
			// 이모티콘 하나 제거
			if (!visited[curr.screen-1][curr.clip]) {
				visited[curr.screen-1][curr.clip] = true;
				q.push({curr.screen-1, curr.clip, curr.time+1});
			}
		}

		// 화면에 붙혀넣기
		if (curr.clip > 0 && curr.screen + curr.clip < 2000) {
			if (!visited[curr.screen+curr.clip][curr.clip]) {
				visited[curr.screen+curr.clip][curr.clip] = true;
				q.push({curr.screen+curr.clip, curr.clip, curr.time+1});
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	cout << bfs();

	return 0;
}