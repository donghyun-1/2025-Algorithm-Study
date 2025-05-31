// https://www.acmicpc.net/problem/5567
// 결혼식 (실버 2)
// 2025-05-31

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1);
    vector<bool> visited(n+1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < graph[1].size(); i++) {
        // 친구
        int f = graph[1][i];

        visited[f] = true;
        
        for (int j = 0; j < graph[f].size(); j++) {
            // 친구의 친구
            int ff = graph[f][j];

            visited[ff] = true;
        }
    }

    int ans = 0;
    for (int i = 2; i < visited.size(); i++) {
        if (visited[i]) ans++;
    }

    cout << ans;

    return 0;
}