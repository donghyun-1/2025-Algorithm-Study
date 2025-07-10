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
int countArr[100001] = { 0 };//입력한 배열의 값들이 몇번 나왔는지 기록할 배열
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    int left = 0;
    int right = 0;
    int answer = 0;
    vector<int> arr;
    arr.resize(N + 1);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    while (right<N)
    {
        if (countArr[arr[right]] < K)// 연속된 수가 넘지 않으면 right 즉 보고있는 배열의 크기를 늘려줌
        {
            countArr[arr[right]]++;
            answer = max(answer, right - left + 1);
            right++;
        }
        else
        {
            countArr[arr[left]]--;
            left++;
        }
    }
    cout << answer;

}