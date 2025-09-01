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
/*
가능한 모든 숫자 배열을 만들어 놓고
부등호에 조건에 맞는 숫자 배열만 벡터에 push해서 
최대값 최소값  출력
*/
using namespace std;
int k;
vector<string> answerArr;
char signalInput[10];
bool visited[10];
bool check(string checkString)
{
    for (int i = 0; i < k; i++)
    {
        if (signalInput[i] == '<')
        {
            if (checkString[i] > checkString[i + 1])
            {
                return false;
            }
        }
        else if (signalInput[i] == '>')
        {
            if (checkString[i] < checkString[i + 1])
            {
                return false;
            }
        }
    }//각 부등호의 조건에 맞지 않을때 false 리턴
    return true;
}
void dfs(int cur,string num)
{
    if (cur == k +1)
    {
        if (check(num))
        {
            answerArr.push_back(num);
        }
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(cur + 1, num + to_string(i));
            visited[i] = false;
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> signalInput[i];
    }
  
    dfs(0, "");
    sort(answerArr.begin(), answerArr.end());

    cout << answerArr.back() << "\n" << answerArr.front();
}