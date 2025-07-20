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
-가 나오면 그 뒤에 나오는수는 모두 괄호로 묶어서 
다 빼버림.
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;
    cin >> input;
    bool minus = false;// 마이너스 괄호가 한번이라도 나온적 있냐를 판단
    int answer=0;
    string num="";//- 또는 + 를 만날때 까지 나오는 string으로 된 숫자를 저장해 놓기 위해 사용할 변수
    for (int i = 0; i <= input.size(); i++)
    {
        // 숫자 끝 또는 문자열 마지막일 때
        if (i == input.size() || input[i] == '+' || input[i] == '-')
        {
            int n = stoi(num);
            if (minus)
            {
                answer -= n;
            }
            else
            {
                answer += n;
            }
            num = "";
        }
        if (i == input.size()) break;
        if (input[i] == '-') minus = true;
        if (input[i] == '+' || input[i] == '-') continue;
        num += input[i];
    }
    cout << answer << '\n';
    return 0;

}