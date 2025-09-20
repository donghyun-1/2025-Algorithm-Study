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
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<long long> arr;
    arr.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int left = 0, right = 0;
    long long answer = 2e18;
    while (left < N && right < N)
    {
        long long cur = arr[right] - arr[left];
        if (cur >= M)
        {
            answer = min(cur, answer);
            left++;
        }
        else
        {
            right++;
        }


    }
    cout << answer;
}