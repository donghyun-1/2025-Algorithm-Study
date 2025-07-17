#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
/*
문제가 저에겐 많이 어려워 구글링 + gpt + 유튜브 강의를 보면서 풀었습니다.
/
잘못 생각 한 것.
(N,M) 까지 할때 딱 한번만 벽을 부술 수 있는 것이 아니라
한칸 한칸 이동할 때 동서남북중에서 한번만 벽을 부술 수 있는 것
/
1. 벽을 부수지 않고 도달하는 경우와 벽을 부수고 도달하는 경우를 둘다 bfs를 돌려 거릴 구한후 더 적은 거리가 정답
2.  같은 좌표라도 벽을 한번도 부수지 않고 도착한상태 와 벽을 한번 부수고 도착한 상태를 각각 다른 경로로 처리를 해야합니다.
3. 따라서 dist배열을 3차원으로 선언하여 0일때 -> 벽부수지 않고 갈때 거리 // 1일때 -> 벽을 부수고 갈때 거리를 구분해줍니다.
*/
using namespace std;
int board[1001][1001];
int dist[1001][1001][2];
// [][][0]벽 부수지 않고 갈때 거리
// [][][1] 벽 부술때 거리
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < M; j++)
        {
            int temp = input[j] - '0';
            board[i][j] = temp;
        }
    }
    queue<tuple<int, int, int>> Q;
    dist[0][0][0] = 1;
    Q.push({ 0, 0, 0 });
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front(); 
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int ny = get<0>(cur) + dy[dir];
            int nx = get<1>(cur) + dx[dir];
            int broke = get<2>(cur);

            // 범위를 벗어나면 넘어감
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            // 다음칸이 빈칸(벽이 아닌 칸)일 경우
            if (board[ny][nx] == 0 && dist[ny][nx][broke] == 0)
            {
                // 이전 거리+1로 갱신
                dist[ny][nx][broke] = dist[get<0>(cur)][get<1>(cur)][broke] + 1;
                Q.push({ ny, nx, broke });
            }

            // 다음칸이 벽이고, 아직 벽을 부수지 않았다면 부수고 이동 가능
            if (board[ny][nx] == 1 && broke == 0 && dist[ny][nx][1] == 0)
            {
                // 벽을 부수고 이동하므로, broke=1 로 갱신하여 큐에 넣음
                dist[ny][nx][1] = dist[get<0>(cur)][get<1>(cur)][0] + 1;
                Q.push({ ny, nx, 1 });
            }
        }
    }
    int normalDist=dist[N-1][M-1][0];
    int brokeDist=dist[N-1][M-1][1];
    if (normalDist == 0 && brokeDist == 0)
    {
        cout << -1;
    }
    else if (normalDist == 0)
    {
        cout << brokeDist << "\n"; // 한쪽만 도착했다면 도착한 값 출력
    }
    else if (brokeDist == 0)
    {
        cout << normalDist << "\n";
    }
    else
    {
        cout << min(normalDist, brokeDist) << "\n";
        // 둘 다 도착했다면 최소값 출력
    }
}