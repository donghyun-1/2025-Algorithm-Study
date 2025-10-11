// https://www.acmicpc.net/problem/2251
// 물통 (골드 4)
// 2025-10-06

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int A, B, C;
};

int a, b, c;
bool visited[201][201][201];
vector<int> ans;

void bfs() {
	queue<Point> q;
	q.push({0, 0, c});
	
	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		// 방문 체크 & 처리
		if (visited[curr.A][curr.B][curr.C]) continue;
		visited[curr.A][curr.B][curr.C] = true;

		// 정답 조건
		if (curr.A == 0) {
			ans.push_back(curr.C);
		}
		
		// 물통 C에서 A로 옮길 때
		if (curr.A + curr.C > a) { // 넘침
			q.push({a, curr.B, curr.A+curr.C-a});
		}
		else {
			q.push({curr.A+curr.C, curr.B, 0});
		}

		// 물통 C에서 B로 옮길 때
		if (curr.B + curr.C > b) { // 넘침
			q.push({curr.A, b, curr.B+curr.C-b});
		}
		else {
			q.push({curr.A, curr.B+curr.C, 0});
		}

		// 물통 B에서 C로 옮길 때
		if (curr.B + curr.C > c) { // 넘침
			q.push({curr.A, curr.B+curr.C-c, c});
		}
		else {
			q.push({curr.A, 0, curr.B+curr.C});
		}

		// 물통 B에서 A로 옮길 때
		if (curr.B + curr.A > a) { // 넘침
			q.push({a, curr.B+curr.A-a, curr.C});
		}
		else {
			q.push({curr.A+curr.B, 0, curr.C});
		}

		// 물통 A에서 B로 옮길 때
		if (curr.B + curr.A > b) { // 넘침
			q.push({curr.B+curr.A-b, b, curr.C});
		}
		else {
			q.push({0, curr.A+curr.B, curr.C});
		}

		// 물통 A에서 C로 옮길 때
		if (curr.C + curr.A > c) { // 넘침
			q.push({curr.C+curr.A-c, curr.B, c});
		}
		else {
			q.push({0, curr.B, curr.A+curr.C});
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	bfs();

	// 정렬 후 중복 제거
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	// 정답 출력
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	return 0;
}