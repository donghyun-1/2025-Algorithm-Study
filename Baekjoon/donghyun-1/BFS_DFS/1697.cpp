// https://www.acmicpc.net/problem/1697
// 숨바꼭질 (실버 1)
// 2025-07-07

/* 
    <접근 방법>
    [1] 
    시작, 도착 위치 입력

    [2]
    bfs 사용하여 최단 거리 구하기
    현재 위치에서 -1, +1, *2 한 위치 push

    [3]
    도착 시 걸린 시간 출력
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100001

using namespace std;

struct Point {
    int node, dist;
};

int N;
int start, dst;
vector<int> arr;

void input() {
    cin >> start >> dst;

    arr.resize(MAX_N, -1);
}

void bfs(int start, int dst) {
    queue<Point> q;
    q.push({start, 0});
    arr[start] = 0;

    while(!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.node == dst) {
            return;
        }

        // x - 1
        if (curr.node-1 >= 0 && curr.node-1 < MAX_N && arr[curr.node-1] == -1) {
            arr[curr.node-1] = curr.dist + 1;

            q.push({curr.node-1, curr.dist+1});
        }

        // x + 1
        if (curr.node+1 < MAX_N && arr[curr.node+1] == -1) {
            arr[curr.node+1] = curr.dist + 1;

            q.push({curr.node+1, curr.dist+1});
        }

        // x * 2
        if (curr.node*2 < MAX_N && arr[curr.node*2] == -1) {
            arr[curr.node*2] = curr.dist + 1;

            q.push({curr.node*2, curr.dist+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    bfs(start, dst);

    cout << arr[dst];

    return 0;
}