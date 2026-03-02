// https://www.acmicpc.net/problem/15683
// 감시 (골드 3)
// 2026-02-16 ~ 2026-02-20

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<vector<int>> board;
vector<vector<int>> temp_board;
vector<pii> cctv;
vector<vector<int>> selected;

void input()
{
	cin >> N >> M;
	board.resize(N, vector<int>(M, 0));
	temp_board.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] != 0 && board[i][j] != 6) {
				cctv.push_back({i, j});
			}
		}
	}
}

void backtracking(int start, vector<int>& temp)
{
	if (temp.size() == cctv.size()) {
		selected.push_back(temp);
		return;
	}

	for (int i = 1; i <= 4; i++) {
		temp.push_back(i);
		backtracking(i+1, temp);
		temp.pop_back();
	}
}

void processUp(pii curr)
{
	while (--curr.first >= 0) {
		if (temp_board[curr.first][curr.second] >= 1 && temp_board[curr.first][curr.second] <= 5) continue;
		if (temp_board[curr.first][curr.second] == 6) break;
		temp_board[curr.first][curr.second] = 7;
	}
}

void processDown(pii curr)
{
	while (++curr.first <= N-1) {
		if (temp_board[curr.first][curr.second] >= 1 && temp_board[curr.first][curr.second] <= 5) continue;
		if (temp_board[curr.first][curr.second] == 6) break;
		temp_board[curr.first][curr.second] = 7;
	}
}

void processLeft(pii curr)
{
	while (--curr.second >= 0) {
		if (temp_board[curr.first][curr.second] >= 1 && temp_board[curr.first][curr.second] <= 5) continue;
		if (temp_board[curr.first][curr.second] == 6) break;
		temp_board[curr.first][curr.second] = 7;
	}
}

void processRight(pii curr)
{
	while (++curr.second <= M-1) {
		if (temp_board[curr.first][curr.second] >= 1 && temp_board[curr.first][curr.second] <= 5) continue;
		if (temp_board[curr.first][curr.second] == 6) break;
		temp_board[curr.first][curr.second] = 7;
	}
}

void processCCTV(pii cctv, vector<int> sel, int idx)
{
	pii curr = cctv;
	
	if (board[cctv.first][cctv.second] == 1 && sel[idx] == 1) {
		// 1번 위
		processUp(curr);
	} else if (board[cctv.first][cctv.second] == 1 && sel[idx] == 2) {
		// 1번 아래
		processDown(curr);
	} else if (board[cctv.first][cctv.second] == 1 && sel[idx] == 3) {
		// 1번 왼쪽
		processLeft(curr);
	} else if (board[cctv.first][cctv.second] == 1 && sel[idx] == 4) {
		// 1번 오른쪽
		processRight(curr);
	} else if (board[cctv.first][cctv.second] == 2 && sel[idx] == 1) {
		// 2번 좌우
		processLeft(curr);
		processRight(curr);
	} else if (board[cctv.first][cctv.second] == 2 && sel[idx] == 2) {
		// 2번 상하
		processUp(curr);
		processDown(curr);
	} else if (board[cctv.first][cctv.second] == 3 && sel[idx] == 1) {
		// 3번 상우
		processUp(curr);
		processRight(curr);
	} else if (board[cctv.first][cctv.second] == 3 && sel[idx] == 2) {
		// 3번 상좌
		processUp(curr);
		processLeft(curr);
	} else if (board[cctv.first][cctv.second] == 3 && sel[idx] == 3) {
		// 3번 하좌
		processDown(curr);
		processLeft(curr);
	} else if (board[cctv.first][cctv.second] == 3 && sel[idx] == 4) {
		// 3번 하우
		processDown(curr);
		processRight(curr);
	} else if (board[cctv.first][cctv.second] == 4 && sel[idx] == 1) {
		// 4번 상 제외
		processDown(curr);
		processLeft(curr);
		processRight(curr);
	} else if (board[cctv.first][cctv.second] == 4 && sel[idx] == 2) {
		// 4번 하 제외
		processUp(curr);
		processLeft(curr);
		processRight(curr);
	} else if (board[cctv.first][cctv.second] == 4 && sel[idx] == 3) {
		// 4번 좌 제외
		processDown(curr);
		processUp(curr);
		processRight(curr);
	} else if (board[cctv.first][cctv.second] == 4 && sel[idx] == 4) {
		// 4번 우 제와
		// 4번 좌 제외
		processDown(curr);
		processUp(curr);
		processLeft(curr);
	} else if (board[cctv.first][cctv.second] == 5) {
		// 5번 전부
		processDown(curr);
		processUp(curr);
		processLeft(curr);
		processRight(curr);
	}
}

int calculateCCTV()
{
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp_board[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	vector<int> temp;
	backtracking(0, temp);

	int ans = 987654321;
	for (int i = 0; i < selected.size(); i++) {
		// 보드 카피
		int idx = 0;
		temp_board = board;
		
		// 사각지대 처리
		for (int j = 0; j < cctv.size(); j++) {
			processCCTV(cctv[j], selected[i], idx++);
		}

		// 사각지대 계산
		ans = min(ans, calculateCCTV());
	}

	cout << ans;

	return 0;
}