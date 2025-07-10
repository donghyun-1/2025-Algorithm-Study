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
슬라이딩 윈도우를 사용해서 문제 풀이
직접 b가 나왔을때 그 b의 위치를 바꾸는 것이 아닌
일단 문제는 최대한 a들이 연속되게 해야하므로 슬라이딩 윈도우의 크기를
a의 개수로 잡고 이동하면서 b의 갯수가 가장 적은 구간이 정답!
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string aList;
    cin >> aList;
    vector<char> input(aList.size());
    int windowSize=0;
    int countB = 0;
    int inputSize = aList.size();
    for (int i = 0; i < inputSize; i++)
    {
        if (aList[i] == 'a')
        {
            windowSize++;
        }
    }
    //첫 구간 b 개수 세기
    for (int i = 0; i < windowSize; i++)
    {
        if (aList[i] == 'b')
        {
            countB++;
        }
    }
    int answer = countB;
    // 슬라이딩 윈도우 (원형)
    for (int i = 1; i < inputSize; i++)
    {
        // i~i+windowSize-1 구간이 윈도우, %inputSize로 원형 처리
        // 왼쪽 문자 빠짐
        if (aList[(i - 1) % inputSize] == 'b')
        {
            countB--;
        }
        // 오른쪽 문자 들어옴
        if (aList[(i + windowSize - 1) % inputSize] == 'b')//원형 배열
        {
            countB++;
        }
        answer = min(answer, countB);
    }
    cout << answer;
}