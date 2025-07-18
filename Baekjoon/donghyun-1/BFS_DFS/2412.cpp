// https://www.acmicpc.net/problem/2412
// 암벽 등반 (골드 4)
// 2025-07-14

/* 
    <접근 방법>
    [1] 
    n, T 입력,
    (x, y) 좌표 set<pii> visited에 insert (방문 확인 용도)

    [2]
    BFS 사용해서 시작 지점 (0, 0)부터 갈 수 있는 좌표 확인
    갈 수 있으면 그 좌표 erase(방문 처리)하고 queue에 push(거리+1)
    
    [3]
    걸린 시간 출력

    설명: set 말고 vector를 사용해서 다음 좌표를 탐색하면 최악의 경우 벡터 처음부터
    끝까지 탐색해야 해서 비효율적임 O(n), 따라서 set으로 빠르게 탐색 하는게 포인트 O(log n)
*/

#include <iostream>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;

struct Point {
    int x, y, dist;
};

int x, y;
int n, T;
set<pii> visited;

void input() {
    cin >> n >> T;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        visited.insert({x, y});
    }
}

int bfs(int srcX, int srcY) {
    queue<Point> q;
    q.push({srcX, srcY, 0});

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.y == T) {
            return curr.dist;
        }

        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                int nx = curr.x + i;
                int ny = curr.y + j;
                
                if (visited.count({nx, ny})) {  // 갈 수 있으면
                    visited.erase({nx, ny});

                    q.push({nx, ny, curr.dist+1});
                }
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

    cout << bfs(0, 0);

    return 0;
}