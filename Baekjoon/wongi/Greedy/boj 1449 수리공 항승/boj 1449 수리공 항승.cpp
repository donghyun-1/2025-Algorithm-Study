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
#include<math.h>
using namespace std;
int n, l;
/*
필요한 테이프의 개수. 를 출력
물 새는 곳의 위치
4 3
1 2 3 4
라고 입력이 들어오면
1~3을 3짜리 테이프로 커버
4를 커버.
따라서 2개의 테이프 필요.
4 3
1 3 50 55
1~3 커버
50커버
55커버
--> 이때는 테이프 3개
*/
vector<int> water;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        water.push_back(input);
    }
    sort(water.begin(), water.end());
    int tapeCnt = 1;//일단 무조건 하나는 들어감.
    int coverEnd = water[0] + l - 1;//현재 테이프가 덮는 오른쪽 끝의 값.
    //coverend==> 현재 물새는 위치에서 테이프로 커버 할수 있는 값.
    for (int i = 1; i < n; i++)
    {
        if (water[i] > coverEnd)//테이프가 닿지 못하면
            //즉 현재 위치에서 테이프로 커버가 안되면.
        {
            tapeCnt++;//새로운 테이프 쓰고
            coverEnd = water[i] + l - 1;// 새로 현재 물 위치부터 커버 할 수 있는 물 파이프의 범위를 갱신함.
        }
    }
    cout << tapeCnt;
}