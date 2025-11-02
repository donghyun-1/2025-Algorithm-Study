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
using namespace std;
int n, m;
bool isVisited[102][102];
/*
물건과의 비교 결과를 알수 없는 물건의 갯수 출력
간단하게 bfs돌려서 방문 
모든 정점에 대해 각각 거리(방문 여부)를 알 수 있기 때문에
플로이드 워셜이 적절해 보임
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                isVisited[i][j] =true;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        isVisited[start][end] = true;
    }
    for (int i = 1; i <= n; i++)// i 경유
    {
        for (int j = 1; j <= n; j++) // j 에서 시작
        {
            for (int k = 1; k <= n; k++)// k 까지.
            {
                if (isVisited[j][i] && isVisited[i][k])
                {
                    isVisited[j][k] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int count=0;
        for (int j = 1; j <= n; j++)
        {
            if (i != j && !isVisited[i][j] && !isVisited[j][i])
            {
                count++;
            }
        }
        cout << count<<'\n';
    }
}
