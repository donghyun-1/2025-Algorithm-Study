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
vector<pair<int, int>> meetings;
/*
ex) 만일 시작 시간 기준으로 정렬해 선택한다면?
1~10
1 2
2 3
3 4
...
9 10

이렇게 회의 시간이 정해진다 치면
만약에 시작 시간으로 정렬해서 문제를 푼다면?
1~10에서 그냥끝나버림
따라서 1~ 2 -> 2~ 3 ->  .... ->9~ 10 이러한 회의 순서가 무시되어버림.
 끝나는 시간이 빠른 것을 보면 뒤에 더 많은 회의를 채울 수 있다.

 제일 먼저 시작하는 회의는 끝나는 시간이 최솟값인 회의
 --> 끝나는 시간 순으로 정렬을 했기 때문.

 1) 회의들을 끝나는 시간 기준 오름차 정렬
 2) 직전에 선택한 회의의 시간을 가지고 있으면서 현재 회의 시작시간이 마지막으로 끝난 회의 시간보다 같거나 이상이면 선택


*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        meetings.push_back({ end,start});
    }
    sort(meetings.begin(), meetings.end());

    int answerCount = 0;
    int lastEndTime= 0;
    for (int i = 0; i < N; i++)
    {
        int end = meetings[i].first; //현재회의 끝시간
        int start = meetings[i].second;//현재 회의 시작시간
        if (start >= lastEndTime)//겹치지 않게
        {
            answerCount++;
            lastEndTime = end;
        }
    }
    cout << answerCount << '\n';
}