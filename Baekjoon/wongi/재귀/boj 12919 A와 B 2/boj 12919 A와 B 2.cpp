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
string s, t;
bool isFound=false;
void func(string inputT)
{
    if (isFound) return;
    if (inputT.size()==s.size())
    {
        if (inputT==s)
        {
            isFound=true;
            return;
        }        
    }
    //첫번째 시도
    /* if (t[0] == 'A')
     {
         t.erase(0, 1);
         func();
     }
     if (t[0] == 'B')
     {
         t.erase(0, 1);
         reverse(t.begin(), t.end());
         func();
     }*/
    //앞에서만 지울때 반례
    //AB
    //BABA
    // 두번째 시도
   /* if (!t.empty() && t.back() == 'A')
    {
        t.pop_back();
        func();
    }
    if (!t.empty() && t.back() == 'B')
    {
        t.pop_back();
        reverse(t.begin(), t.end());
        func();
    }
    --> t를 직접 수정하면 x
    */

    if (!inputT.empty() && inputT.back() == 'A')
    {
        string next = inputT;
        next.pop_back();
        func(next);
    }
    //3번째 시도. 
   /* if (!inputT.empty() && inputT.back() == 'B')
    {
        string next = inputT;
        next.pop_back();
        reverse(next.begin(), next.end());
        func(next);
    }*/
    /*
    B 연산은 “뒤에 B 붙이고 전체 뒤집기”
       T에서S로 가는 과정은 역으로 계산하는거기 때문에
        맨 앞에 B가 있으면
        ==>전체 뒤집기 → 뒤에 붙은 B 떼기
    */
    if (!inputT.empty() && inputT.front() == 'B')
    {
        string next = inputT;
        reverse(next.begin(), next.end());
        next.pop_back();
        func(next);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    cin >> t;
    func(t);
    if (isFound)
    {
        cout << 1;
    }
    else
        cout << 0;

}