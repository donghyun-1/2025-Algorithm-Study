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
using namespace std;
int w[11][11];
bool visited[11];
int answer = 1e9f;
int N;
void dfs(int cur, int count, int dist)
//count --> 전체 도시를 다 돌아야 하므로
//현재 돌고있는 도시 개수
{
    if (dist >= answer)//더 짧은 거리 있으면 return
    {
        return;
    }
    if (count == N)//결국 count==N이면 모든 도시를 다 돌았음
    {
        if (w[cur][0] > 0)//시작 도시로 돌아갈 수 있는가? 를 체크함.
        {
            answer = min(answer, dist+ w[cur][0]);//최소값 갱신
        }
        return;
    }
    for (int next = 0; next < N; next++)//백트래킹으로 다음 방문안한도시 방문하자
    {
        if (!visited[next] && w[cur][next] > 0)
        {
            visited[next] = true;
            dfs(next, count + 1, dist + w[cur][next]);
            visited[next] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //int count;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> w[i][j];
        }
    }
    visited[0] = true;
    dfs(0, 1, 0);
    cout << answer;
}
 