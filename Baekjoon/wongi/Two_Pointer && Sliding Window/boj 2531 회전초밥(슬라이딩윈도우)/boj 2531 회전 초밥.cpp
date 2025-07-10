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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, d, k, c;
    cin >> N>> d>> k>> c;
 
    vector<int> arr;
    vector<int> typeCnt(d+1);
    // 초밥 타입에 따라서 지금 슬라이딩윈도우 비교할때 이 종류의 초밥이 있는지 없는지 체크하는 배열
    //int형으로 해놓는 이유는 똑같은 종류의 초밥이 있을때 카운트 할지 말지 정하기 위해서
   
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    
    int answer=0;
    int kindCnt=0;
    
    for (int i = 0; i < k; i++)//맨처음 시작하는것 부터 일단 초기화
    {
        if (typeCnt[arr[i]] == 0)
        {
            kindCnt++;//0에서 tpyecnt가++된다면 처음으로 이 종류가 들어왔다는 뜻임.
        }
        typeCnt[arr[i]]++;
    }
    answer += kindCnt;
    if (typeCnt[c] == 0)
    {
        answer++;
    }//쿠폰 유무에 따라서 ++
    for (int i = 1; i < N; i++)
    {
        int left = arr[i - 1];
        int right = arr[(i + k - 1) % N];//나머지 연산을 사용하여 원형 배열 접근
        
        //왼쪽 초밥 빼기
        typeCnt[left]--;
        if (typeCnt[left] == 0) kindCnt--;
        //뺏는데 만약에 똑같은 종류의 초밥이 남아있을수도 있으니 0일때만 kindCnt 감소
        //

        // 오른쪽 초밥 넣기
        if (typeCnt[right] == 0) kindCnt++;
        typeCnt[right]++;

        int currentCnt = 0;
        currentCnt += kindCnt;
        if (typeCnt[c] == 0) { currentCnt++; }
        answer = max(answer, currentCnt);


    }
    cout << answer;
}