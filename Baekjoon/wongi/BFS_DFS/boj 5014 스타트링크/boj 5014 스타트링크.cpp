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
F S G U D
총 F층 으로 이루어져있고,
s층부터 시작
g가 이제 도착점
u버튼은 +층
d는 -층

*/
int F, S, G, U, D;
vector<int> visited;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> F >> S >> G >> U >> D;
    visited.resize(F + 1, -1);
    fill(visited.begin(), visited.end(), -1);//-1로 초기화
    queue<int> Q;
    Q.push(S);
    visited[S] = 0;//방문 처리

    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        int upFloor = cur + U;
        if (U > 0 && upFloor <= F && visited[upFloor] == -1)//범위 안벗어나고 방문하지 않은 층 이라면
        {
            visited[upFloor] = visited[cur] + 1;
            Q.push(upFloor);
        }
        int downFloor = cur - D;
        if (D > 0 && downFloor >= 1 && visited[downFloor] == -1)
        {
            visited[downFloor] = visited[cur] + 1;
            Q.push(downFloor);
        }
    }
    if (visited[G] == -1)
    {
        cout << "use the stairs";
    }
    else
        cout << visited[G];


}