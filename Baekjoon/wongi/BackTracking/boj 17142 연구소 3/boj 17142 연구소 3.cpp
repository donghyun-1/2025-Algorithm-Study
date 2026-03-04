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
#include <unordered_set>
#include<unordered_map>
#include<math.h>
#include<cstring>
using namespace std;
struct V
{
    int x, y;
};
int n, m;
int board[51][51];
int visit[51][51];
int dx[4] = { 0,0,-1,1 };
int  dy[4] = { 1,-1,0,0 };
vector<V> virusArr;
vector<V> curVirus;
int answer =1e9;
int emptyCnt=0;
/*
0 빈칸
1 벽
2 바이러스
m개의 바이러스를 활성화 한다 침
이때 모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간 구하기.
백트래킹으로 모든 활성화할 바이러스 조합 구한다음에
만약 활성화할 바이러스가 도달하면 그때 bfs로 칸을 돌면서 시간 갱신 하여 최소 시간 구해줌.
*/
void clear()
{
    memset(visit, -1, sizeof(visit));
}
void dfs(int choose, int start)
{
    if (choose == m)
    {
        /*
        여기에서 curvirus안에 있는 바이러스 조합 가지고 bfs돌려서
        answer 갱신
        */
        clear();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            V curV=curVirus[i];
            q.push({curV.y  ,curV.x });
            visit[curV.y][curV.x]=0;
        }
        int time = 0;
        int curEmptyCnt = emptyCnt;
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (curEmptyCnt == 0)
            {
                //감염 시킬 수 있는 곳은 다 감염 시켰다면 answer 과 time 중 작은 값으로 answer 갱신
                answer = min(answer, time);
                break;
            }
            for (int dir = 0; dir< 4; dir++)
            {
                int nextX = cur.second + dx[dir];
                int nextY = cur.first + dy[dir];
                if (nextX < 0 || nextY < 0 || nextX >= n || nextY >= n) continue;
                if (board[nextY][nextX] == 1) continue;
                if (visit[nextY][nextX]!=-1)continue;
                visit[nextY][nextX] =visit[cur.first][cur.second]+ 1;
                if (board[nextY][nextX] == 0)
                {
                    //거리 갱신을시키는데 이제 그 칸이 바이러스로 감염 시킬 우 있는 칸이면
                    // time 갱신
                    time = max(time, visit[nextY][nextX]);
                    curEmptyCnt--;
                }
                q.push({ nextY,nextX });
            }
        }
        return;
    }
    int virusSize = (int)virusArr.size();
    for (int i = start; i < virusSize; i++)
    // 여러 바이러스 조합을 찾아서 그 바이러스 조합에 따라서 bfs
    // 돌려서 answer 갱신
    {
        curVirus.push_back(virusArr[i]);
        dfs(choose + 1, i + 1);
        curVirus.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;
            board[i][j] = input;
            if (input == 2)
            {
                V vi;
                vi.x = j;
                vi.y = i;
                virusArr.push_back(vi);
            }
            else if (input == 0)
            {
                emptyCnt++;
                
            }
        }
    }
    dfs(0,0);
    if (answer == 1e9)//answer 갱신 안되면 바이러스 못퍼뜨림
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}