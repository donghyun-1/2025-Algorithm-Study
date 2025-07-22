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
이분 탐색을 사용하여 
이분 탐색 대상 ==>최대 랜선 길이를 구해주자.
left를 1길이 부터 시작
maxnum 을 제일 긴 랜선길이로 설정
가능한 랜선 길이를 갱신하면서 중간 값들을 갱신하도록하자.
만일 Mid길이로 n개 이상 만들면 mid길이를 늘려 보도록하고
만일 n개를 만들지 못하면 길이를 줄여보도록하자.


** 유의 할점 **
--> N은 1이상 1,000,000이하의 정수이다.
그래서 int형으로 선언하면 오버 플로우 떠서 자꾸 틀렸다고 나옴. 따라소 long long으로 선언해야함
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> k >> n;
    vector<long long>arr(k);
    int lanLine = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long left = 1;
    long long maxNum = arr[k-1];
    int answer = 0;
    while (left<=maxNum)
    {
        long long line = 0;
        long long mid = (left + maxNum) / 2;
        for (int i = 0; i < k; i++)
        {
            line += arr[i] / mid;
        }
        if (line < n)//랜선길이를 줄이기
        {
            maxNum = mid - 1;
        }
        else//랜선길이 늘리기
        {
            answer = mid;
            left = mid + 1;
        }

    }
    cout << answer;
}
