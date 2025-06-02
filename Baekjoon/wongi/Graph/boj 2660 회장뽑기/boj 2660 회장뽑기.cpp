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
vector<vector<int>>linkedArr;
vector<bool> visited;
vector<int> dist;
vector<int> answerArr;
void bfs(int start)// 각 노드에서 부터 거리를 구함. 거기서 제일 큰 값이 회장 후보의 점수
{
	queue<int> q;
	q.push(start);
	visited[start] = true;
	dist[start] = 0;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int i = 0; i < linkedArr[cur].size(); i++)
		{
			int next = linkedArr[cur][i];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = true;
				dist[next]=dist[cur]+1;//각 도착지점노드의 거리를 갱신
			}
		}
	}
	int count = *max_element(dist.begin(), dist.end());
	answerArr[start] = count;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node;
	cin >> node;
	linkedArr.resize(node + 1);
	visited.resize(node + 1);
	dist.resize(node + 1);
	answerArr.resize(node + 1);
	while (true)
	{
		int start, end;
		cin >> start >> end;
		if (start == -1 && end == -1)
		{
			break;
		}
		linkedArr[start].push_back(end);
		linkedArr[end].push_back(start);
	}
	
	for (int i = 1; i <= node; i++)
	{
		bfs(i);
		fill(visited.begin(), visited.end(), false);
		fill(dist.begin(), dist.end(), 0);
	}

	int minScore = *min_element(answerArr.begin()+1, answerArr.end());//이제 가장 작은 값이 회장 후보이므로 가장 작은 값을 구해주고

	vector<int> hubo;
	for (int i = 1; i <= node; i++)//가장 작은 값들을 가진 회장 후보들을 선택및 출력
	{
		if (answerArr[i] == minScore)
			hubo.push_back(i);
	}

	cout << minScore << " " << hubo.size() << '\n';
	for (int i = 0; i < hubo.size(); i++)
	{
		cout << hubo[i] << ' ';
	}
}