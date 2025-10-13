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
#include <math.h>
using namespace std;
int N, r, c;
int answer;
void func(int x, int y, int size)
{
    if (x == c && y == r)
    {
        cout << answer;
        return;
    }
    else if (c < x + size && c >= x && r < y + size && r >= y)
    // 나눈 사각형 안에 찾으려는 좌표가 
    //있으면 사각형을 분할함.
    {
        func(x, y, size / 2);
        func(x + size / 2, y, size / 2);
        func(x, y + size / 2, size / 2);
        func(x + size / 2, y + size / 2, size / 2);
    }
    else//만약에 없으면 그 사각형의 넓이만큼 answer ++ 해주면서 다음 사이즈로 넘어감.
    {
        answer += size * size;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> r >> c;
    int boardSize = pow(2, N);
    func(0, 0, boardSize);
}