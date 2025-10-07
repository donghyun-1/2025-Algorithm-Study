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
int n, w, L;
queue<int> truck;
queue<int> bridge;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        truck.push(input);
    }
    int answerTime = 0;
    int curWeight = 0;//현재 다리 위 올라와있는 트럭 무개
    for (int i = 0; i < w; i++)
    {
        bridge.push(0);//그냥 빈칸으로 초기화(0으로 초기화)
    }
    while (!bridge.empty())
    {
        answerTime++;// 시간 늘리고
        curWeight -= bridge.front();//현재 브릿지에서 빼고(0은 차피 빈칸 나타내는거니까 빼도 상관 x)
        bridge.pop();
        if (!truck.empty())
        {
            int next = truck.front();
            if (curWeight + next <= L)//제한 무개가 될때만
            {
                truck.pop();//트럭 큐에서 빼고
                bridge.push(next);//다리로 놓기
                curWeight += next;
            }
            else
            {
                bridge.push(0);//조건 안되면 그냥 빈칸으로 
            }
        }
    }
    cout << answerTime;
}