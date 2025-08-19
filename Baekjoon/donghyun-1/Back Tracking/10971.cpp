// https://www.acmicpc.net/problem/10971
// 외판원 순회 2 (실버 2)
// 2025-08-07

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

int N;
int W[11][11];
bool visited[17];
int ans = INF;

void solve(int start_node, int curr_node, int count, int curr_cost) {
    // --- 가지치기 (Pruning) ---
    // 현재 비용이 이미 이전에 찾은 최소 비용보다 크면 더 이상 탐색할 필요가 없음
    if (curr_cost >= ans) {
        return;
    }

    if (count == N) {
        if (W[curr_node][start_node] != 0) {
            curr_cost += W[curr_node][start_node];
            ans = min(ans, curr_cost);
        }
        return;
    }

    for (int next_node = 1; next_node <= N; next_node++) {
        if (!visited[next_node] && W[curr_node][next_node] > 0) { 
            visited[next_node] = true;
            solve(start_node, next_node, count + 1, curr_cost + W[curr_node][next_node]);         
            visited[next_node] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> W[i][j];
        }
    }

    // 1번 도시부터 시작한다고 가정 (어떤 도시에서 시작해도 순회 비용은 동일)
    visited[1] = true;
    solve(1, 1, 1, 0);

    cout << ans;

    return 0;
}