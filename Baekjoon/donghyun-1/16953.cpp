// https://www.acmicpc.net/problem/16953
// A → B (실버 2)
// 2025-09-06

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Point {
	long long num;
	int cnt;
};

int A, B;

void input() {
	cin >> A >> B;
}

void bfs() {
	queue<Point> q;
	q.push({A, 1});

	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		if (curr.num > B) continue;
		
		if (curr.num == B) {
			cout << curr.cnt;
			return;
		}

		long long next1 = curr.num * 2;
		long long next2 = curr.num * 10 + 1;

		if (next1 <= B) q.push({next1, curr.cnt+1});
		if (next2 <= B) q.push({next2, curr.cnt+1});
	}
	cout << -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	bfs();

	return 0;
}