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
int answerCnt = 0;
int arrSize;
int targetNum;
int arr[101];
void dfs(int cur, int curSum)
{
    if (cur == arrSize)
    {
        if (curSum == targetNum)
        {
            answerCnt++;
        }
        return;
    }

    dfs(cur + 1, curSum + arr[cur]);
    dfs(cur + 1, curSum - arr[cur]);

}
int solution(vector<int> numbers, int target)
{
    arrSize = numbers.size();
    targetNum = target;
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = numbers[i];
    }
    dfs(0, 0);
    return answerCnt;
}