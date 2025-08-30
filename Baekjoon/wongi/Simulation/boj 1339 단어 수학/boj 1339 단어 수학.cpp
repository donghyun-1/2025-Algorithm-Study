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
/*
각 단어에 가중치(자리수 순으로 가중치 부여)를 줘서 높은 순으로 9~0 까지 배치해준다.
GCF 
G-> 100
C-> 10
F ->1
ACDEB
A->10000
C->1000
D->100
E->10
B->1

A = 10000 (9)
C = 1000 + 10 = 1010 (8)
D = 100 (7)
G = 100 (6)
E = 10 (5)
B = 1  (4)
F = 1  (3)

683+98754= 99437
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    vector<string> words;
    words.resize(count);
    vector<int> alphaCount;
    alphaCount.resize(26);
    for (int i = 0; i < count; i++)
    {
        cin >> words[i];
    }
    for (int i = 0; i < count; i++)
    {
        int digitNum = 1;// 1부터 시작해서 자리수 까지 count
        for (int j = words[i].size() - 1; j >= 0; j--)
        {
            alphaCount[words[i][j] - 'A'] += digitNum;//자리수를 더해준다.(가중치 갱신.)
            digitNum *= 10;
        }
    }
    sort(alphaCount.begin(), alphaCount.end(), greater<int>());

    // 큰 가중치부터 9,8,7,... 배정하여 합 계산
    int digit = 9;
    int ans = 0;
    for (int i = 0; i < 26 && alphaCount[i] > 0 && digit >= 0; i++)
    {
        ans += alphaCount[i] * digit;
        digit--;
    }

    cout << ans << '\n';
    return 0;
}