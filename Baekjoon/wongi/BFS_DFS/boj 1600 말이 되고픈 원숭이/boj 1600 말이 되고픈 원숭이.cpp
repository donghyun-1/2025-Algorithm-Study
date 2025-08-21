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
#include <string.h>
#include <vector>
#include <unordered_set>
#include<unordered_map>
using namespace std;
int arr[201][201];
int dist[201][201][31];// 그 위치에 나이트 이동횟수도 같이 저장해놓기위해 3차원배열선언
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dist, -1, sizeof(dist));//-1로 3차원 배열 초기화
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    int sx[8] = { -2,-1,1,2,2,1,-1,-2 };
    int sy[8] = { -1,-2,-2,-1,1,2,2,1 };

    int K, W, H;
    cin >> K;
    cin >> W >> H;


    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> arr[i][j];
        }
    }
    queue<tuple<int, int, int>> Q;
    Q.push({ 0,0,K });
    dist[0][0][K] = 0;
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front(); Q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int remainMove = get<2>(cur);

        if (x == H - 1 && y == W - 1) {
            cout << dist[x][y][remainMove];
            return 0;
        }

        // 말(나이트) 이동
        if (remainMove > 0)//말 이동방식 횟수가 남아있을때만 나이트 이동 ㄱㄱ 
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + sx[i];
                int ny = y + sy[i];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (arr[nx][ny] == 1|| dist[nx][ny][remainMove - 1] != -1) continue;
                dist[nx][ny][remainMove - 1] = dist[x][y][remainMove]+1;//거리 갱신. 과함께 그 위치로 말이동을 사용할수 있는 횟수를 감소시킴(이동했으니)
                Q.push({ nx, ny, remainMove - 1 });
            }
        }

        // 일반 4방향 이동
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (arr[nx][ny] == 1|| dist[nx][ny][remainMove] != -1) continue;
            dist[nx][ny][remainMove] = dist[x][y][remainMove] + 1;
            Q.push({ nx, ny, remainMove });
        }
    }

    cout << -1;
    return 0;
}