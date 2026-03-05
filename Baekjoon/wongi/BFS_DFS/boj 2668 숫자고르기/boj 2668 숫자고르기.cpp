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
이 배열들 안에서 모든 사이클의 정점의 개수를 출력
dfs를 돌면서 각 사이클을 확인.
*/
int n;
int node[101];
int visited[101];
bool cycle[101];//현재 이 노드는 사이클상태가 이미 확정이 되어있음
/*
0 방문 한번도 안함
1 사이클 판단중에 있음
2 사이클 판단 완료

*/
int count = 0;
vector<int> answer;
void dfs(int curNode)
{
    visited[curNode] = 1;
    int next = node[curNode];
    if (visited[next] == 0)//현재 노드에 연결되어있는 노드가 방문 한번도 안했으면
    {
        dfs(next);//그 노드 부터 사이클 판단 시작
    }
    else if(visited[next]==1)// 사이클 판단 중에 있다면
    {
        for (int i = next; i != curNode; i = node[i])// 현재 판단하는 노드부터 자기 자신이 나올때 까지 확인하면서 사이클 상태를 변경해줌
        {
            cycle[i] = true;// 사이클 상태로 변경 
            answer.push_back(i);
        }
        cycle[curNode] = true;
        answer.push_back(curNode);
    }
    visited[curNode] = 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (!cycle[i])
        {
            dfs(i);
        }
    }
    cout << answer.size()<<'\n';
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i]<<'\n';

    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 03/05에 다시 품
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
int n;
int arr[101];//현재 i가 가리키는 다음 숫자
int cur[101];//현재 i돌면서 필요한 사이클 확인용 
bool isMatch[101]; // 최종적으로 사이클이 되어 매치가 된 노드
vector<int> answer;//정답 사이클 노드
void dfs(int start, int curNode)
{
	int next = arr[curNode];//현재 노드가 가리키는 노드
	if (next == start)// 사이클 판정 됐을때
	{
		int v = start;
		while (!isMatch[v])
		{
			isMatch[v] = true;//사이클 완료 처리
			answer.push_back(v);//사이클 완료된 노드 넣기
			v = arr[v];//다음 노드로 ㄱㄱ
			if (v == start)break;//처음으로 왔으니 break
		}
		return;
	}
	else//안됐을때
	{
		cur[curNode] = start;//일단 이번 사이클에서 한번 방문했다는 표시
		if (cur[next] == start)
		{
			//원래 맨처음 start로 돌아온게 아니라 중간에서 루프가 발생해서 return
			return;
		}
	}
	dfs(start, next);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (!isMatch[i])
		{
			dfs(i, i);
		}
	}
	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << '\n';
	}
}