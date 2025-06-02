// https://www.acmicpc.net/problem/2660
// 회장뽑기 (골드 5)
// 2025-06-02

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int node, level;
};

vector<vector<int>> graph;
vector<bool> visited;
vector<Point> score;

// 방문 배열 초기화
void init() {
    visited.assign(visited.size(), false);
}

// bfs
void bfs(int node) {
    queue<Point> q;
    q.push({node, 0});

    visited[node] = true;

    int total_level = 0;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        total_level = max(total_level, curr.level);

        for (int i = 0; i < graph[curr.node].size(); i++) {
            int next = graph[curr.node][i];
            if (visited[next]) continue;

            visited[next] = true;
            q.push({next, curr.level+1});
        }
    }

    score.push_back({node, total_level});   // 시작 노드, 가장 멀리 있는 거리
}

// 후보 비교
bool compare(Point& p1, Point& p2) {
    if (p1.level == p2.level) {
        return p1.node < p2.node;
    }

    return p1.level < p2.level;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int N;
    cin >> N;
    graph.resize(N+1);
    visited.resize(N+1);

    while (1) {
        int a, b;
        cin >> a >> b;

        if (a == -1 && b == -1) break;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 가장 멀리 있는 노드 구하기
    for (int i = 1; i <= N; i++) {
        init();
        bfs(i);
    }

    // 후보 정렬
    sort(score.begin(), score.end(), compare);

    int cnt = 1;
    for (int i = 1; i <= score.size(); i++) {
        if (score[0].level == score[i].level) {
            cnt++;
        }
        else break;
    }

    // 출력
    cout << score[0].level << " " << cnt << "\n";

    for (int i = 0; i < cnt; i++) {
        cout << score[i].node << " ";
    }

    return 0;
}