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
using namespace std;
int M, N, H;
int board[101][101][101];
int dist[101][101][101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dx[6] = { 1,0,-1,0,0,0 };
    int dy[6] = { 0,1,0,-1,0,0 };
    int dh[6] = { 0,0,0,0,1,-1 };

    cin >> M >> N >> H;
    queue<tuple<int, int, int>> Q;
    
   
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int a = 0; a < M; a++)
            {
                cin >> board[i][j][a];
                if (board[i][j][a] == 1)
                {
                    Q.push({ i,j,a });
                }
                if (board[i][j][a] == 0)
                {
                    dist[i][j][a] = -1;
                }
            }
        }
    }
    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = dx[i] + get<2>(cur);
            int ny = dy[i] + get<1>(cur);
            int nh = dh[i] + get<0>(cur);
            if (nx < 0 || nx >= M || ny < 0 || ny >= N||nh<0||nh>=H) continue;
            if (dist[nh][ny][nx] == -1)
            {
                dist[nh][ny][nx] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                Q.push({nh,ny,nx});
            }
        }
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int a = 0; a < M; a++)
            {
                if (dist[i][j][a] == -1)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    int max_dist = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            max_dist = max(max_dist, *max_element(dist[i][j], dist[i][j] + M));
        }
    }
    cout << max_dist;
}