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
/*
첫번재로 풀때는 그냥 각 노드에서 bfs돌려서 최단 거리 구해서 
다른 배열에 더한 값들을 추가하여 작은 값을 출력하는 식으로 풀었음
but 알고리즘 분류를 열어보니 플로이드 워셜로 풀수 있다하여
플로이드 워셜을 사용하여 문제 다시 풀었음
*/
vector<vector<int>> linkedArr; 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    linkedArr.resize(N + 1,vector<int>(N+1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                linkedArr[i][j] = 0;
            }
            else
            {
                linkedArr[i][j] = 1000000;
            }
        }
    }
    for (int i = 0; i < M; i++) 
    {
        int start, end;
        cin >> start >> end;
        linkedArr[start][end] = 1;
        linkedArr[end][start] = 1;
        //직접 연결된 친구의 거리 1로 초기화.
    }
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++) 
        {
            for (int j = 1; j <= N; j++)
            {
                linkedArr[i][j] = min(linkedArr[i][j], linkedArr[i][k] + linkedArr[k][j]);
            }
        }
    }

    int minSum = 1000000, answer = 0;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++) 
        {
            sum += linkedArr[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
            answer = i;
        }
    }
}