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
using namespace std;
/*
ex)
 input -> 6
 1. 복사(a)
 2. 붙 a a
 3. 붙 a a a
 4. 복 (a a a)
 5. 붙 a a a a a a
*/
int dp[1001][1001];
//dp [i][j] 
// 현재 화면에 i개의 이모티콘이 있고
// 현재 클립보드에 j개가 있을때 걸린시간.
int s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    /*
     복사 dp[i][i]=min(dp[i][i],dp[i][j]+1);
     붙혀넣기 dp[i+j][j]=min(dp[i+j][j],dp[i][j]+1);
     삭제 dp[i-1][j]=min(dp[i-1][j],dp[i][j]+1);    
    */

    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    dp[1][0] = 0;
    //a 는 현재 시간.
    //0초부터 2000초 까지 (나올수 있는 초를 일단 2000초로 대충 어림잡아 선언해 놓음.)
    //시간 순으로 테이블 채우기.
    for (int a = 0; a <= 2000; a++)
    {
        for (int i = 1; i <= 1000; i++)
        {
            for (int j =0; j <= 1000; j++)
            {
                if (dp[i][j] == a)//현재 화면상태가 a초에 도달 할수 있다면.?
                {
                    dp[i][i] = min(dp[i][i], dp[i][j] + 1);//복사할때. 복사는 항상 가능
                    if (i + j <= 1000)// 붙혀넣기할때 범위 체크
                    {
                        dp[i + j][j] = min(dp[i + j][j], dp[i][j] + 1);
                    }
                    if (i - 1 > 0)//삭제할때 . 범위체크
                    {
                        dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + 1);
                    }
                }
            }
        }
    }
    int answer = 1e9;
    for (int i = 0; i <= 1000; i++)
    {
        answer = min(answer, dp[s][i]);//그래서 s개 있을때 그중 가장 작은 값을 출력함
    }
    cout << answer;
}
