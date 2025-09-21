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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long A, B;
    cin >> A >> B;
    queue<pair<long long, int>>q;//현재 값,  연산 횟수
    //bfs를 이용하여 최단거리 갱신.
    q.push({ A,1 });
    while (!q.empty())
    {
        pair<long long, int> cur = q.front();
        q.pop();
        if (cur.first == B)//목표 수에 도달하면 출력
        {
            cout << cur.second;
            return 0;
        }
        if (cur.first*2<= B)
        {
            q.push({ cur.first*2,cur.second + 1 });
        }
        if ((cur.first *10)+1 <= B)
        {
            q.push({ (cur.first * 10) + 1,cur.second + 1 });
        }
    }
    cout << -1;
    return 0;
}