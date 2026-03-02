// https://www.acmicpc.net/problem/17142
// 연구소 3 (골드 3)
// 2026-02-16 ~ 2026-02-20

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

struct Point {
	int row, col, cnt;
};

int N, M;
int board[51][51];
vector<pii> virus;
vector<vector<pii>> selected;
bool visited[51][51];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int space;

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];

			if (board[i][j] == 2) {
				virus.push_back({i, j});
			} else if (board[i][j] == 0) {
				space++;
			}
		}
	}
}

void backtracking(int start, vector<pii>& temp) {
	if (temp.size() == M) {
		selected.push_back(temp);
		return;
	}

	for (int i = start; i < virus.size(); i++) {
		temp.push_back(virus[i]);
		backtracking(i+1, temp);
		temp.pop_back();
	}
}

int bfs(queue<Point> q)
{
	int count = 0;
	int max_cnt = 0;

	while (!q.empty()) {
		Point curr = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = curr.row + D[i][0], nc = curr.col + D[i][1];
			if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
			if (visited[nr][nc]) continue;
			if (board[nr][nc] == 1) continue;

			visited[nr][nc] = true;

			if (board[nr][nc] == 2) {
				q.push({nr, nc, curr.cnt+1});
			} else if (board[nr][nc] == 0) {
				q.push({nr, nc, curr.cnt+1});
				count++;
				max_cnt = max(max_cnt, curr.cnt+1);
			}
		}
	}
	
	if (count == space) {
		return max_cnt;
	} else {
		return -1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	vector<pii> temp;
	backtracking(0, temp);

	// for (int i = 0; i < selected.size(); i++) {
	// 	for (int j = 0; j < M; j++) {
	// 		cout << "{" << selected[i][j].first << ", " <<  selected[i][j].second << "} ";
	// 	}
	// 	cout << "\n";
	// }

	int ans = 987654321;
	int time;
	for (int i = 0; i < selected.size(); i++) {
		queue<Point> q;
		memset(visited, 0, sizeof(visited));
		
		for (int j = 0; j < M; j++) {
			q.push({selected[i][j].first, selected[i][j].second, 0});
			visited[selected[i][j].first][selected[i][j].second] = true;
		}

		time = bfs(q);

		if (time != -1) {
			ans = min(ans, time);
		}
	}

	if (ans == 987654321) {
		cout << "-1";
	} else {
		cout << ans;
	}

	return 0;
}