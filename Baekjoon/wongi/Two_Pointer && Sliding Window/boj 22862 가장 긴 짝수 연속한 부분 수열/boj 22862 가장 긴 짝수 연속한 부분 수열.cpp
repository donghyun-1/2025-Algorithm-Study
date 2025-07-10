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
    vector<int> arrS;
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        arrS.push_back(input);
    }
    int startIdx1 = 0;
    int endIdx1 = 0;
    int kCount = K;
    int maxCount=0;
    while (endIdx1 < arrS.size())
    {
        if (arrS[endIdx1] % 2 == 1&&kCount!=0)
        //홀수고 삭제할 수 있는 횟수가 남아 있으면 
        // 끝 인덱스를 +1 , 횟수 줄이고 
        {
            endIdx1++;
            kCount--;
        }
        else if (arrS[endIdx1] % 2 == 0)
        // 짝수 만나면 그냥 확장
        {
            endIdx1++;
        }
        else if(arrS[endIdx1]%2==1&&kCount==0)//삭제할 수 있는 횟수 없고, 홀수 만나면?
        {
            if (arrS[startIdx1] % 2 == 1)//근데 이제 startIdx 가 홀수라면?
            {
                kCount++;//다음수로넘어갈거니까 삭제할 수 있는 횟수를 늘리고
                startIdx1++;//시작 인덱스를 +1
            }
            else//홀수 아니면 그냥 시작 인덱스만 +1
            {
                startIdx1++;
            }
        }
        maxCount = max(maxCount, endIdx1 - startIdx1 - (K-kCount));
        //max카운트와 endIdx1-startIdx1-(현재까지 뺀 홀수갯수를 뺀거) 비교하여 큰쪽으로 갱신
    }
    cout << maxCount;
}