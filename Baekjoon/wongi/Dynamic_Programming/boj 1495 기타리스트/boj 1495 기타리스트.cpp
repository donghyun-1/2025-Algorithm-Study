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
구글링+gpt의 힌트를 참고했습니다.
dp[i][a] i번째 곡까지 고려했을때 볼륨 a가 가능한지 아닌지 판단
즉 뺏을때 0이하가아니거나
더했을때 M을 넘는지 안넘는지 
--> 현재 i곡의 볼륨에서 볼륨 이 가능하다면
i+1 번째 곡에서 더해준것과 빼준것이 범위내면 둘다 true로 만들어낸다.
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, S, M;
    //M => 최대 볼륨
    //S => 시작 볼륨
    cin >> N >> S >> M;
    vector<int>V(N);
    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }
    dp[0][S] = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (!dp[i][j]) continue;
            /*
            false면 그 j에서 더하고 빼는 모든 다음 볼륨도 이 경로를 통해서는 불가능 따라서 더하고 빼주는 행위를 해줄 필요 x
            */
            if (j + V[i] <= M)
                dp[i + 1][j + V[i]] = true;
            if (j - V[i] >= 0)
                dp[i + 1][j - V[i]] = true;
        }
    }
    int answer = -1;
    for (int i = M; i >= 0; i--) //최대 볼륨을 찾아야 하므로 뒤에서 부터 빼가면서 가장 먼저 true나오는게 최대 볼륨ㄴ
    {
        if (dp[N][i])
        {
            answer = i;
            break;
        }
    }
    cout << answer;
}