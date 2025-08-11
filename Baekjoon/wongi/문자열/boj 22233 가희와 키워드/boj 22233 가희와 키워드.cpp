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
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int keyCnt, boardCnt;
    cin >> keyCnt >> boardCnt;

    unordered_set<string> keyWord;
    for (int i = 0; i < keyCnt; i++)
    {
        string input;
        cin >> input;
        keyWord.insert(input);
    }
    cin.ignore();// 이전 입력에서 개행 문자까지 포함시켜서 아래에서 문자들 찾을때 틀려버림
    for (int i = 0; i < boardCnt; i++)
    {
        string input;
        getline(cin, input);

        string token;
        stringstream ss(input);

        while (getline(ss, token, ',' ))//, 기준으로 문자 나눠서 만약에 언오더드 set에 있다면 삭제 후 개수 출력
        {
            if (keyWord.find(token)!=keyWord.end())
            {
                keyWord.erase(token);
            }
        }
        cout << keyWord.size() << "\n"; // 남은 키워드 개수 출력
    }

}