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
    int city;
    cin >> city;
    vector<int> price;
    
    for (int i = 0; i < city; i++)
    {
        int input;
        cin >> input;
        price.push_back(input);
    }
    int maxSum;
    cin >> maxSum;
    sort(price.begin(), price.end());
    int start = 1;
    int end = price.back();
    int answer = 0;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int sum = 0;
        for (int i = 0; i < city; i++)
        {
            sum += min(price[i], mid);
        }
        if (sum <= maxSum)//현재 더한 값이 예산보다 작으면 상한가를 더 늘려도 된다.
        {
            answer = mid;
            start = mid + 1;// 따라서 이제 시작 상한가를 늘려준다.--> 범위를 늘림
        }
        else//현재 더한 값이 예산보다 크므로
        {
            end = mid - 1;// 범위를 줄여준다.
        }

    }
    cout << answer;
}
/*일단 다 더해서 총액 안넘으면 그냥 제일 큰수 출력
    --> 상한액을 1~ 현재 도시들 중에서 가장 큰 값 까지 비교하면서 조건에 알맞게 비교하면서 계산
    ex)
    120 110 140 150
    총예산 : 485
    상한액 : 127

    이러면 나올 수 있는 상한액 범위는 1~150.
    1부터 150까지 상한액을 올려가면서 예산을 넘는지 안넘는지 비교하면서 상한값 계산
    예를 들어 상한액을 100이라 치면
    모든도시에 100씩줘서 400 이되고 이 값은 485 가 안넘기때문에 가능.근데 예산이 많이 남아서 상한액을 더 올려도 됨
    만일 127 이라 치면
    120 110 127 127 이렇게 주면 484가됨
    또한 128 이라 치면
    120 110 128 128 이렇게 준다면 486이 되므로 불가능함
    따라서 1~ 도시들중 가장 큰값까지 상한액을 늘려가면서 계산
    but 이경우는 시간복잡도가 너무 커진다. o(m*n)
    따라서 이분탐색으로 상한액을 범위를 반씩 줄여가면서 계산

    예시)
    1~150
    150/2 => 75부터 상한액을 잡으면 이 값으로 계산한다면 485보다 작은 값이 나오므로
    가능한 상한액의 범위를 76~150 --> (150+76)/2 --> 113
    이때도 485보다 작은 값이 나오므로
    114~150 --> (150+114)/2 --> 132
    120 + 110+ 132 +132 => 494 따라서 132일때는 예산이 초과 해버리므로
    132~150 은 아예제외를 해버림.
    그다음은 이제 114~132... 이런식으로 계속 계산하여 범위를 줄이고
    시작값이 끝값과 같거나 커지면 중단!
    */
