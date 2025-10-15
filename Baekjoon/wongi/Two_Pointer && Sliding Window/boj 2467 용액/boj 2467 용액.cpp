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
#include <unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    vector<long long >arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long input;
        cin >> input;
        arr.push_back(input);
    }
    int left = 0;
    int right = n-1;
    long long answerLeft = arr[left];
    long long answerRight = arr[right];
    long long sum= 2e9;
    while (left < right)
    {
        long long curSum = arr[left] + arr[right];
        if (abs(curSum) < abs(sum))// 더 작은 절대값을 찾았을때
        {
            sum = curSum;
            answerLeft = arr[left];
            answerRight = arr[right];
        }

        if (curSum==0)
        {
            break;
        }
        else if(curSum <0)
        {
            left++;
        }
        else
        {
            right--;
        }
        
    }
    cout << answerLeft << ' ' << answerRight;
}