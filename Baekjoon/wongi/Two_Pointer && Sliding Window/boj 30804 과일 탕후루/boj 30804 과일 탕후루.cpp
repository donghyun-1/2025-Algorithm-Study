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
    int count;
    cin >> count;
    vector<int> arr(count);
    int fruitType[10] = {0};//과일 종류를 세는 배열
    
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    int start = 0;
    int end = 0;
    int typeCnt = 0;
    int answer = 0;
    while (end<count)
    {
        if (fruitType[arr[end]] == 0)
        {
            typeCnt++;
        }//만일 end의 typecnt가 0이면 갱신
        fruitType[arr[end]]++;
        end++;
        //일단 end인덱스를 ++

        while (typeCnt > 2)//과일종류가 2개 이상일 경우
        {
            fruitType[arr[start]]--;//일단 start인덱스 늘릴것이므로 타입 카운트 줄여주고
            if (fruitType[arr[start]] == 0)
                //만일 타입 카운드가 0이면 
                //즉 똑같은 종류의 과일이 더이상 없다면
            {
                typeCnt--;//전체 과일 종류 카운드 줄여주기
            }
            start++;
        }
        answer = max(answer, end - start);
    }
    cout << answer;
}
