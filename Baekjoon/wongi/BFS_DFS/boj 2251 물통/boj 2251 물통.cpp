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
/*
A B C의 특정 용량 상태를 1개의 노드로 가정한다.
조건에 따라 이 상태에서 변경할 수 있는 이후 용량 상태를 엣지로 이어진 상태로 생각한다.
노드에서 갈 수 있는 6개의 경우 (a->b / a->c / b->a / b->c / c->a / c->b)
*/
using namespace std;
int A, B, C;
vector<int> answer;
queue<tuple<int, int, int>> q;
bool isVisited[201][201][201];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B >> C;
    isVisited[0][0][C];
    q.push({ 0,0,C });
    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front(); q.pop();
        int curA = get<0>(cur);
        int curB = get<1>(cur);
        int curC = get<2>(cur);
        if (isVisited[curA][curB][curC]) continue;
        isVisited[curA][curB][curC] = true;

        if (curA == 0)
        {
            answer.push_back(curC);
        }
        //A->B 줄때
        if (curA + curB > B)//넘칠때
        {
            q.push({ curA + curB - B,B,curC });//(넘친 만큼 다시 A에 넣기, B다채우기)
        }
        else// 안넘칠때 
        {
            q.push({ 0,curB + curA,curC });//A는 그냥 0으로 B는 A+B
        }
        //이하동일
        //A->C
        if (curA + curC > C)
        {
            q.push({ curA + curC - C, curB, C });
        }
        else 
        {
            q.push({ 0, curB, curA + curC });
        }
        //B->A
        if (curB + curA > A)
        {
            q.push({ A, curB + curA - A, curC });
        }
        else 
        {
            q.push({ curA + curB, 0, curC });
        }
        //B->C
        if (curB + curC > C) 
        {
            q.push({ curA, curB + curC - C, C });
        }
        else
        {
            q.push({ curA, 0, curB + curC });
        }
        // C->A
        if (curC + curA > A) 
        {
            q.push({ A, curB, curC + curA - A });
        }
        else 
        {
            q.push({ curA + curC, curB, 0 });
        }
        //C->B
        if (curC + curB > B)
        {
            q.push({ curA, B, curC + curB - B });
        }
        else 
        {
            q.push({ curA, curB + curC, 0 });
        }
    }
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
}