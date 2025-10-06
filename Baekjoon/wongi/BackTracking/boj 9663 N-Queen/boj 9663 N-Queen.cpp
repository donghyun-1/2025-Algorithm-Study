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
각 행에 퀸을 일단 배치하고 그 다음행을 내려가면서 놓을 수 있는 자리를 체크 하면서 백트래킹
방법 1 : 같은 열에 있는걸 확인 -> y값이 같으면 같은 열
    대각선 위치에 있다? -> 각 x+y OR x-y 같을때 같은 대각선에 있다.
방법 2 : isUsed배열을 따로 두어 각 대각선과 열의 점유 상태를 나타내는 배열사용.
따라서
isUsed배열이 3개가 있을텐데
1 -> y축 : 열에 대한 점유 상태 배열
2 -> x+y축 : 좌측 하단에서 우측 상단으로 가는 대각선 점유 상태 배열
3 -> x-y+n-1축 : 좌측 상단에서 우측 하단으로 가는 대각선 점유 상태 배열
만약 cur ,i 에 퀸을 둘 수 있따면 
isUsed1[i], isUsed2[cur+i] ,isUsed3[cur-i+n-1]의 배열을 true로 변경한 후 cur +1 을 호출하여 다음 단계로 넘어감
*/
int N;
int answerCnt = 0;
int isUsed1[40];
int isUsed2[40];
int isUsed3[40];
void func(int cur)
{
    if (cur == N)// 퀸 n개를 다 놓았다~
    {
        answerCnt++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (isUsed1[i] || isUsed2[cur + i] || isUsed3[cur - i + N - 1]) continue;
        isUsed1[i] = 1;
        isUsed2[cur + i] = 1;
        isUsed3[cur - i + N - 1]=1;
        func(cur + 1);
        isUsed1[i] = 0;
        isUsed2[cur + i] = 0;
        isUsed3[cur - i + N - 1]=0;
    }
    
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> N;
    func(0);
    cout << answerCnt;
}