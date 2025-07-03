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
/*그리디 알고리즘
이 문제를 풀때 dp로 풀면 시간초과가 난다.
이 문제를 그리디로 풀수 있었던 조건중 하나는
동전 A[i]가 A[i-1]의 배수가 된다는 조건이 있기 때문에 가능한것
반례 --> 만약에 1, 9,10 원을 이용해 18원을 만든다 치면
9*2 -> 2개 지만
만약에 이 문제에서 풀듯이 가장 큰 값을 빼고 문제를 푼다면 18-10(10원짜리 하나) = 8(1원짜리 8개) 
 이런식으로 나와 틀린 답이 나옴*/ 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int coin, target;
    cin >> coin >> target;
    vector<int> coinArr;
    coinArr.resize(coin+1);
    for (int i = 0; i < coin; i++)
    {
        cin >> coinArr[i];
    }
    int answer = 0;
    for (int i = coin - 1; i >= 0; i--)
    {
        if (coinArr[i] <= target)//현재 동전이 남은 금액 이하일 때 사용가능
        {
            answer += (target / coinArr[i]);//이제 만약에 사용가능 하다면 몇개를 사용할 수 있는지 계산 하여 동전갯수 ++
            target = target % coinArr[i];//나머지 연산을 이용하여 목표 가치를 사용하고 남은 금액으로 바꿈
        }
    }
    cout << answer;
}