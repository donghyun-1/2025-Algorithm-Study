// https://www.acmicpc.net/problem/5014
// 스타트링크 (실버 1)
// 2025-07-31

#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
bool visited[1000001];

void bfs() {
    queue<pair<int, int>> q;
    q.push({S, 0});     // {현재 층, cnt}
    visited[S] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr.first == G) {
            cout << curr.second;
            return;
        }

        int nextUp = curr.first + U;
        int nextDown = curr.first - D;
    
        if (nextUp <= F && !visited[nextUp]) {
            visited[nextUp] = true;
            q.push({nextUp, curr.second+1});
        }
        if (nextDown > 0 && !visited[nextDown]) {
            visited[nextDown] = true;
            q.push({nextDown, curr.second+1});
        }
    }

    // 엘리베이터로 이동할 수 없을 때
    cout << "use the stairs";
    
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> F >> S >> G >> U >> D;

    bfs();

    return 0;
}