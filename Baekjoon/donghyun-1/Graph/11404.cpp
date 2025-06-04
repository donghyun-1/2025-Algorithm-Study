// https://www.acmicpc.net/problem/11404
// 플로이드 (골드 4)
// 2025-06-04

#include <iostream>

#define MAX 9900001

using namespace std;

int n, m;               // 도시의 개수, 버스의 개수
int dist[101][101];     // dist[S][E] = 거리

// 초기 설정, 입력
void init() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = MAX;
        }
    }

    // 거리 입력
    for (int i = 0; i < m; i++) {
        int s, e, dst;
        cin >> s >> e >> dst;

        dist[s][e] = min(dist[s][e], dst);
    }
}

// 플로이드 워셜
void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

// 출력
void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == MAX)      // 못 가는 도시
                cout << "0 ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    // 초기 설정, 입력
    init();

    // 플로이드 워셜
    floyd_warshall();

    // 출력
    print();

    return 0;
}