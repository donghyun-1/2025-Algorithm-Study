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
int n;
long long arr[500001];
long long temp[500001];
long long answer = 0;
void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int leftIdx = start;
    int rightIdx = mid;
    for (int i = start; i < end; i++)
    {
        if (leftIdx == mid)
        {
            temp[i] = arr[rightIdx];
            rightIdx++;
        }
        else if (rightIdx == end)
        {
            temp[i] = arr[leftIdx];
            leftIdx++;
        }
        else if (arr[leftIdx] <= arr[rightIdx])
            //합병정렬은 stable sort 
        {
            temp[i] = arr[leftIdx];
            leftIdx++;
        }
        else
            /*우측 덩어리에 있던 값이 왼쪽 덩어리보다 작아서 먼저 temp로 이동함
            swap횟수는 병합 과정에서 우측에 있는 데이터가 왼쪽 덩어리에 있는 곳으로 이동하는 횟수와 같음.
            */
        {
            temp[i] = arr[rightIdx];
            rightIdx++;
            answer = answer + (mid - leftIdx);
        }
    }
    for (int i = start; i < end; i++)
    {
        arr[i] = temp[i];
    }
}
void mergeSort(int start, int end)
{
    if (end == start + 1) return;
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    merge(start, end);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(0, n);

    cout << answer;

}
