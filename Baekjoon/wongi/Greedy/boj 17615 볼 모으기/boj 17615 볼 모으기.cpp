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
빨간공을 모두 맨 왼쪽(1)
--> 일단 맨 왼쪽부터 연속된 빨간공 갯수 구하고 
전체 빨간공에서 맨 왼쪽부터 연속된 빨간공 갯수를 빼주면 옮겨야 할 공의 횟수가 나온다. 
빨간공을 모두 맨 오른쪽(2)
-->맨 오른쪽부터 연속된 빨간공 갯수 구하고
전체 빨간공에서 맨 오른쪽 부터 연속된 빨간공의 갯수 빼우면 옮겨야 할 공의 횟수가 나옴
파란공을 모두 맨 왼쪽(3)
파란공을 모두 맨 오른쪽(4)
--> 위 두 경우와 같음
으로 옮겼을때 4가지 경우 중에서 가장 작은 값이 정답.
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    string input;
    cin >> input;
    vector<char> balls;
    balls.resize(count);

    for (int i = 0; i < count; i++)
    {
        balls[i] = input[i];
    }
    int allRCnt = 0;
    int allBCnt = 0;
    int redLeftCnt=0;//(1)
    int redRightCnt=0;//(2)
    int blueLeftCnt=0;//(3)
    int blueRightCnt=0;//(4)
    int answer = 500001;
    for (int i = 0; i < count; i++)
    {
        if (balls[i] == 'R')
        {
            allRCnt++;
        }
        else
        {
            allBCnt++;
        }
    }
    //(1) 번 경우
    for (int i = 0; i < count; i++)
    {
        if (balls[i] == 'R')
        {
            redLeftCnt++;
        }
        else
        {
            break;//연속된 R의 경우의 수만 필요하므로 B나오면 그대로 반복문 끝
        }
    }
    answer = min(answer, allRCnt - redLeftCnt);// 각 경우를 지나면서 최소값을 갱신을 시켜준다.
    //(2) 번 경우
    for (int i = count - 1; i >= 0; i--)
    {
        if (balls[i] == 'R')
        { 
            redRightCnt++;
        }
        else break;
    }
    answer = min(answer, allRCnt - redRightCnt);
    //(3) 번 경우
    for (int i = 0; i < count; i++)
    {
        if (balls[i] == 'B')
        {
            blueLeftCnt++;
        }
        else
        {
            break;
        }
    }
    answer = min(answer, allBCnt - blueLeftCnt);
    //(4) 번 경우
    for (int i = count - 1; i >= 0; i--)
    {
        if (balls[i] == 'B')
        {
            blueRightCnt++;
        }
        else break;
    }
    answer = min(answer, allBCnt - blueRightCnt);
    cout << answer;
}