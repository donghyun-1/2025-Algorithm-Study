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
#include<math.h>
/*
첫번째 줄 -> 악마
두번째 줄 -> 천사

input
방문 순서 문자
악마
천사
*/
using namespace std;
string match;
string arr1;
string arr2;
int dp[21][2][101];
/*
두루마리 i번째 까지 왔고
j : 돌다리 종류
k :다리의 몇번째 칸을 밟고 있는지

0 악마
1 천사
==> 다리 k번째 밟아서 두루마리의 i번째 문자까지 완성했을때의 총 경우의 수
마지막에 그러면 각
dp[두루마리 끝][0][arr1 문자 끝] -> 악마
dp[두루마리 끝][1][arr2 문자 끝] -> 천사
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> match;
    cin >> arr1;
    cin >> arr2;
    int matchSize = match.size();
    int arr1S = arr1.size();
    int arr2S = arr2.size();
    for (int a = 0; a < arr1S; a++)
    {
        if (arr1[a] == match[0])
        {
            dp[0][0][a] = 1;
        }
        if (arr2[a] == match[0])
        {
            dp[0][1][a] = 1;
        }
    }
    //일단 첫 번째 매치하는 곳을 찾아서 1로 초기화

    for (int i = 1; i < matchSize; i++)//두번째 매치글자부터 시작
    {
        for (int j = 0; j < 2; j++)
        {
            for (int a = 0; a < arr1.size(); a++)
            {
                if (j == 0 && match[i] == arr1[a])//만약 악마이고 글자 매치되면
                {
                    for (int b = 0; b < a; b++)
                    {
                        dp[i][j][a] += dp[i - 1][1 - j][b]; 
                        /*
                        * //1-j로 반대 돌다리에 있는 수를 더함.
                        악마에서 매칭외 되면 이제 반드시 천사쪽에서의 값을 가져와야함.
                        추가로 번갈아가면서 서로 같은 인덱스로 더하는것이 아니라 교차로 왔다갔다 해야함.
                        */
                    }
                }

                else if (j == 1 && match[i] == arr2[a])
                {
                    for (int b = 0; b < a; b++)
                    {
                        dp[i][j][a] += dp[i - 1][1 - j][b];
                    }
                }
            }
        }
    }

    int answer = 0;
    // 악마 다리
    for (int i = 0; i < arr1S; i++)
    {
        answer += dp[matchSize - 1][0][i];
    }
    // 천사 다리
    for (int i = 0; i < arr2S; i++)
    {
        answer += dp[matchSize - 1][1][i];
    }

    cout << answer << '\n';
}