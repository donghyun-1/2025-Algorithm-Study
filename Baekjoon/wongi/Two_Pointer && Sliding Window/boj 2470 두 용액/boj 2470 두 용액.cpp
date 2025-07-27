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
vector<long long> arr;
/*
abs를 사용해서 가장 0에 가까운 즉 
두 용액의 합을 절대값하여 제일 작은 값을 구해서
두 용액을 출력함
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    arr.resize(count);
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = count - 1;

    long long bestSum = 2e9;
    long long ansLeft = arr[left];
    long long ansRight = arr[right];
    while (left < right)
    {
        long long sum = arr[left] + arr[right];
        if (abs(sum) < abs(bestSum))//절대값이 더 작은 조합이 있으면 정답 갱신해줌
        {
            bestSum = sum;
            ansLeft = arr[left];
            ansRight = arr[right];
        }

        // 포인터 이동
        if (sum < 0)
        {
            left++;
        }
        else
            right--;
    }
    cout << ansLeft << " " << ansRight;

}