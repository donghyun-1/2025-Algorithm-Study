// https://www.acmicpc.net/problem/16235
// 나무 재테크 (골드 3)
// 2025-12-15 ~ 2025-12-19

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct Point {
	int age;
	bool life;
};

int N, M, K;
int A[11][11];		// 양분
deque<Point> tree[11][11];
vector<vector<int>> food;
int D[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void input()
{
	cin >> N >> M >> K;
	
	food.resize(N+1, vector<int>(N+1, 5));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	int row, col, age;
	for (int i = 0; i < M; i++) {
		cin >> row >> col >> age;
		tree[row][col].push_back({age, true});
	}
}

bool Compare(Point &A, Point &B) {
	return A.age < B.age;
}

void spring()
{
	// 어린 순으로 정렬
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// 양분 먹기
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (!tree[i][j][k].life) continue;

				if (food[i][j] >= tree[i][j][k].age) {
					// 나이 증가
					food[i][j] -= tree[i][j][k].age;
					tree[i][j][k].age++;
				} else {
					// 전부 죽이기
					tree[i][j][k].life = false;
				}
			}
		}
	}
}

void summer()
{
	// 양분 추가 (+= 죽은 나무 나이 / 2)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = tree[i][j].size()-1; k >= 0; k--) {
				if (!tree[i][j][k].life) {
					food[i][j] += (tree[i][j][k].age / 2);
					tree[i][j].pop_back();
				}
			}
		}
	}
}

void fall()
{
	// 나무 번식 (주변 1칸)
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k].age % 5 == 0 && tree[i][j][k].life) {
					for (int l = 0; l < 8; l++) {
						int nr = i + D[l][0], nc = j + D[l][1];
						if (nr <= 0 || nr > N || nc <= 0 || nc > N) continue;
						tree[nr][nc].push_front({1, true});
					}
				}
			}
		}
	}
}

void winter()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			food[i][j] += A[i][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	// 처음 1번 정렬
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sort(tree[i][j].begin(), tree[i][j].end(), Compare);
		}
	}

	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k].life) ans++;
			}
		}
	}

	cout << ans;

	return 0;
}