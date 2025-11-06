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
/*
도로-> 양방향
웜홀 -> 단방향.
input
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
테스트 케이스 tc
각 테스트 케이스 시작할때
지점 수, 도로개수, 웜홀개수 ?
ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
2
3 3 1 -- 노드수, 도로개수, 웜홀개수
1 2 2
1 3 4
2 3 1 -- 여기까지 도로
3 1 3 -- 웜홀 입력 -> 근데 웜홀은 시간이 줄어드므로 -3으로 입력을 받기.

3 2 1 --
1 2 3
2 3 4
3 1 8

ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ


tc개의 줄에 걸쳐 시간이 줄어들면서 출발위치로 오는게 가능하면?
yes  --> 즉 음수 사이클이 존재 할 때
불가능 하면? no -->  음수 사이클이 존재 하지 않을때
문제 풀이

*/


void init()
{
    //minDist.assign()
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> minDist;
        vector<pair<int,int>> graph[501];
        int n, m, w;
        cin >> n >> m >> w;

        for (int i = 0; i < m; i++)// 도로 입력 -> 양방향
        {
            int start, end, cost;
            cin >> start >> end >> cost;

            graph[start].push_back({ end,cost });
            graph[end].push_back({ start,cost });

        }
        for (int i = 0; i < w; i++)//웜홀 입력 -> 단방향
        {
            int start, end, cost;
            cin >> start >> end >> cost;
            graph[start].push_back({ end,-cost }); // 웜홀은 단방향, 시간이 줄어든다 했으므로 음수 값으로 저장
        }
        minDist.assign(n + 1, 0); // 출발점은 모든 노드가 될수 있으므로 모든 노드를 시작점으로 둠
        /*여기서 왜 모든 정점을 0으로 초기화 및 아래에 주석 해놓은 if (minDist[i] == 1e9) continue; 이거를 빼야하는가
            --> 일반적인 mindist[1]=0 으로 시작하면 나중에 갱신 해놓은 
            mindist배열에서 1e9 인 경우는 1부터 시작해서 도달 할 수 없는 즉 1정점에서 갈 수 없는걸 나타내는데
            이 문제는 시작점이 정해지지 않았음 모든 정점에서 부터 시작할 때 음수 사이클의 유무를 판단하는 것이기 때문에
            minDist를 모두 0으로 초기화 해줘서 모든 노드에 대해 검사 하도록한다.
        */
        //minDist[1] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                //if (minDist[i] == 1e9) continue;
                
                for (int k = 0; k < graph[j].size(); k++)
                {
                    int end = graph[j][k].first;
                    int cost = graph[j][k].second;
                    if (minDist[end] > minDist[j] + cost)
                    {
                        minDist[end] = minDist[j] + cost;
                    }
                }
            }
        }

        bool isCycle = false;
        for (int i = 1; i <= n; i++)
        {
            //if (minDist[i] == 1e9) continue;
            for (int j = 0; j < graph[i].size(); j++)
            {
                int end = graph[i][j].first;
                int cost = graph[i][j].second;
                if (minDist[end] > minDist[i] + cost)
                // 만약에 이 최단거리 배열이 갱신이 되면 음수 사이클이므로 즉시 for문 끊고 결과 출력
                {
                    isCycle = true;
                    break;
                }
            }
        }
        if (isCycle)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << '\n';

    }
}