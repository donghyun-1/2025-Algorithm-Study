// https://www.acmicpc.net/problem/13335
// 트럭 (실버 1)
// 2025-10-05

#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int arr[1001];
int n, w, L;

void input() {
	cin >> n >> w >> L;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	int time = 0;
	int weight = 0;

	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {
				weight -= q.front();
				q.pop();
			}

			// 여러 대 올릴 수 있는지 check
			if (weight + arr[i] <= L)
				break;

			// 빈칸 넣기
			q.push(0);
			time++;
		}

		q.push(arr[i]);
		weight += arr[i];
		time++;
	}

	// 마지막 트럭까지 +w
	cout << time + w;

	return 0;
}