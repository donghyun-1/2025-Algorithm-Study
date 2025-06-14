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
int solution(string myString, string pat) {
    int answer = 0;
    int pos = 0;
    while (true) {
        pos = myString.find(pat, pos);
        if (pos == string::npos) break;
        answer++;
        pos++;
        //찾을 때마다 찾을 index 증가 시켜서 다음 인덱스부터 찾도록
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    cout << solution(a, b);
}