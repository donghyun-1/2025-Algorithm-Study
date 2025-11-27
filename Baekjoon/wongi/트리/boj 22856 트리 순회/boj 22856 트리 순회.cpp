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
* 이진 트리.
현재 위치한 노드의 왼쪽 자식 노드가 존재하고 아직 방문하지 않았다면, 왼쪽 자식 노드로 이동한다.
그렇지 않고 현재 위치한 노드의 오른쪽 자식 노드가 존재하고 아직 방문하지 않았다면, 오른쪽 자식 노드로 이동한다.
그렇지 않고 현재 노드가 유사 중위 순회의 끝이라면, 유사 중위 순회를 종료한다.
그렇지 않고 부모 노드가 존재한다면, 부모 노드로 이동한다.
유사 중위 순회를 종료할 때까지 1 ~ 4를 반복한다.

1부터 시작

트리 노드 개수 n
현재 노드 a
왼쪽 자식 노드 b
오른쪽 자식 노드 c
-1 이면 자식 x

중위 순회의 끝점은 가장 오른쪽에 있는 노드.
*/

int lc[100001];
int rc[100001];
int n;
int answer = 0;
int rightNode = 0;
int endNode;
bool isEnd;
void dfs(int node)
{
    
    if (lc[node] != -1)
    {
        answer++;
        dfs(lc[node]);     
        if (!isEnd) 
        {
            answer++;
        }
    }
    if (rc[node] != -1)
    {
        answer++;
        dfs(rc[node]);
        if (!isEnd) 
        {
            answer++;//다시 되돌아갈때 이동 걸음 ++
            //근데 이제 마지막까지 endnode까지 다 돌면 탐색끝나고 되돌아가는 걸음 ++ 안해줘야함
        }
    }
  
    if (node == endNode)
    {
        isEnd = true;

        return;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b;
        rc[a] = c;
    }
    int currentNode = 1;
    while (rc[currentNode] != -1)
    { 
        // 오른쪽 자식이 있다면
        currentNode = rc[currentNode]; // 오른쪽으로 이동
    }
    endNode = currentNode; // 더 이상 갈 곳이 없으면 그곳이 끝점
    //중위 순회에서 제일 마지막 방문노드는 리프 노드 중에서 가장 오른쪽에 있는 노드.
    //--> 오른쪽 자식이 없는 노드중 번호가 가장 큰 노드
    dfs(1);
    cout << answer;

}