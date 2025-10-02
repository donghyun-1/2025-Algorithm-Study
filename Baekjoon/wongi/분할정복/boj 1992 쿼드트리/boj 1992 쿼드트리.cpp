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
char board[65][65];
int N;
/*
문제 풀이 방법
분할 정복 문제
1. 현재 영역이 단색 -> 즉 같은 번호가 아니라면 그대로 출력하고
2. 만약에 같은 색이 아니라면 size/2로 4등분.
3. 마지막에 나온 것을 출력.
*/
void func(int x,int y,int size)
/*
(x,y) 시작지점/ size 사각형의 크기
이 3가지를 이용해서 각각 나눈 
*/
{
    char firstNum = board[x][y];
    //재귀 시작하기 전에 일단 이 영역의 숫자를 구한다. --> 영역 나눴을때 영역안에 수를 비교해야함.

    bool isSame = true;
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (board[i][j] != firstNum)
            {
                isSame = false;
            }
        }
        if (!isSame) break;
    }
    if (isSame)
    {
        cout << firstNum;
        return;
    }
    //--> 현재 비교하고있는 영역이 같은 수이므로 그냥 출력
    // 근데 이제 만약에 영역안에 하나라도 다른게 있으면 4등분을 해서 영역을 확인하고
    //또 분할할지 말지 안에서 재귀로 계속 확인하면서 분할함.
    cout << "(";
    func(x, y, size / 2);//왼쪽위
    func(x, y + size / 2, size / 2);//오른쪽 위
    func(x + size / 2, y, size / 2);//왼쪽 아래
    func(x + size / 2, y + size / 2, size / 2);//오른쪽 아래
    cout << ")";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < N; j++)
        {
            board[i][j] = input[j];
        }
    }
    func(0, 0, N);

}    