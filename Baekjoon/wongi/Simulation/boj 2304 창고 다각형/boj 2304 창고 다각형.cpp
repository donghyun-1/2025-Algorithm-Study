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
가장 큰 높이를 가지고 있는 기둥을 
찾아서 그 인덱스를 기준으로 좌 우 넓이를 구해준다.
좌측 : 0부터 매 인덱스 마다 현재까지 최대 높이 더하기
우측 : size 부터 감소 시키면서 최대 높이 더해주기 좌측과 똑같이 
마지막에 제일 높은 부분 더해주기
*/
int arr[1001] = { 0 };
int maxHeight ,maxIndex,sum,arrSize;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int L, H;
        cin >> L >> H;
        arr[L] = H;
        arrSize = max(arrSize, L);
        if (maxHeight < H)
        {
            maxHeight = H;
            maxIndex = L;
        }
    }
    int leftMax = 0;
    for (int i = 1; i < maxIndex; i++)
    {
        leftMax = max(leftMax, arr[i]);
        sum += leftMax;
    }
    int rightMax = 0;
    for (int i = arrSize; i > maxIndex; i--)
    {
        rightMax = max(rightMax, arr[i]);
        sum += rightMax;
    }
    cout << sum + maxHeight;
}