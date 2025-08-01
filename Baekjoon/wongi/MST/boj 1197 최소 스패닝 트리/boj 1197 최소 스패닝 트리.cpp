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
int V, E;
vector<int> ufArr;
vector<tuple<int, int, int>> tree;
int find(int a)
{
    if (a == ufArr[a])
    {
        return a;
    }
    else
    {
        return ufArr[a] = find(ufArr[a]);
    }
}
void unions(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        ufArr[b] = a;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    ufArr.resize(V + 1);
    for (int i = 1; i <= V; i++)
    {
        ufArr[i] = i;
    }
    for (int i = 0; i < E; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        tree.push_back({ weight,start,end });//가중치 기준으로 오름차순 정렬해야하기 때문에 가중치를 먼저 맨 앞에다가 넣어준다. 
    }
    sort(tree.begin(), tree.end());//오름차순 정렬
    int answer = 0;
    for (int i = 0; i < tree.size(); i++)
    {
        int weight = get<0>(tree[i]);
        int start = get<1>(tree[i]);
        int end = get<2>(tree[i]);
        if (find(start) != find(end))
        // find연산을 이용했을 때 둘이 다르면 사이클이 만들어 지지 않았다는 의미이므로 이때 유니온 연산과 가중치를 갱신시켜준다.
        {
            unions(start, end);
            answer += weight;
        }
    }
    cout << answer;
}