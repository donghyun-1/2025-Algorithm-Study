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
    /*
     a와 b사이에 있는 사람수(걍 b인덱스 에서 a인덱스 빼) * a와 b개발자 능력치 중 작은것

    */
    vector<int>arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    int left = 0;
    int right = n - 1;
    int answer = 0;
    while (left < right)
    {
        int minValue = min(arr[left], arr[right]);
        int btSize = right - left - 1;
        answer = max(answer, minValue * btSize);
        if (arr[left] < arr[right])
        {
            left++;
        }
        else
            right--;
    }
    cout << answer;
}