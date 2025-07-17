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
서류점수나 면접점수 순위중 하나라도 다른 사람보다 높은게 없으면 탈락.
따라서 이제 서류점수 순위를 기준으로 오름차순으로 정렬 이후
면접 점수 순위를 비교해가면서 탈락자를 정함.
3 6
7 3
4 2
1 4
5 7
2 5
6 1
--> 서류 점수를 기준으로 오름차순으로 정렬
1 4
2 5
3 6
4 2
5 7
6 1
7 3
-->일단 서류점수 순위 1등은 무조건 합격자임
+ 만약 면접 점수순위가 비교하면서 낮으면 무조건 그사람은 탈락자 
*/
int func()
{
    int answer=0;
    int count;
    cin >> count;
    vector<vector<int>> arr(count + 1);
    for (int i = 0; i < count; i++)
    {
        int s, m;
        cin >> s >> m;
        arr[s].push_back(m);
    }
    int score = 100001;
    for (int i = 1; i <= count; i++)
    {
        int mRate = arr[i][0];
        if (mRate < score)
        {
            answer++;
            score = mRate;
        }
    }

    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout<<func()<<'\n';
    }
}