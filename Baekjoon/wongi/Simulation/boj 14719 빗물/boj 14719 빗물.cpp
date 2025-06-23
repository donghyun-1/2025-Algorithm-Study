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
각 칸에 물이 고이려면 왼쪽에도 나보다 높은 블록, 오른쪽에도 높은 블록 있어야함
물 고일수 있는 최대 높이는 =(현재 칸 -좌우에서 볼때 가장 높은 값 중에서 낮은값)
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int H, W;
    cin >> H >> W;
    vector<int> water;
    for (int i = 0; i < W; i++)
    {
        int input;
        cin >> input;
        water.push_back(input);
    }
    vector<int> rain(W);
    //각 칸마다 얼마나 빗물이 고이는지에 대한 배열
    rain[0] = 0;
    rain[W-1] = 0;
    //처음과 끝은 물이 고일일이 없으니 0으로 초기화
    vector<int> leftMax(W);
    vector<int> rightMax(W);
    //각 칸에서 왼쪽 오른쪽 가장 큰 칸 배열들
    leftMax[0] = water[0];
    rightMax[W - 1] = water[W - 1];

    for (int i = 1; i < W;i++)
    {
        leftMax[i] = max(leftMax[i - 1], water[i]);
    }
    for (int i = W-2; i >=0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], water[i]);
    }
    //각 칸에대해서 좌우 높은 칸 값 배열 
    for (int i = 1; i < W - 1; i++)
    {
        int curRain=min(leftMax[i], rightMax[i]) - water[i];
        if (curRain >= 0)//뺄때 0보다 작으면 그 칸에는 물이 고일수 없다는 뜻
        {
            rain[i] = curRain;
        }
        else
        {
            rain[i] = 0;
        }
    }
    int answer = 0;
    for (int i = 0; i < rain.size(); i++)
    {
        answer += rain[i];
    }
    cout << answer;
}