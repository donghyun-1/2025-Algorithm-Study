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
int n, m;
vector<int> inputArr;
int curArr[10];
void func(int cur)
{
    if (cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << curArr[i]<<" ";
        }
        cout << "\n";
        return;
    }
    int temp = 0;//이번 재귀 단계에서 마지막으로 쓴 숫자를 기억하기 위한 변수
    for (int i = 0; i < n; i++)
    {
        if (temp == inputArr[i]) continue;// 같은 깊이에서 같은수는 skip하기.
        if (cur==0||curArr[cur - 1] <= inputArr[i])//
        {
            temp = inputArr[i];//이번 재귀에서 사용한 숫자 기록
            curArr[cur] = inputArr[i];
            func(cur + 1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        inputArr.push_back(input);
    }
    sort(inputArr.begin(), inputArr.end());
    func(0);
}