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
    int N;
    long long M;
    vector<long long> tree;
    cin >> N >> M;
    tree.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> tree[i];
    }
    sort(tree.begin(), tree.end());
    long long left = 0;
    long long right = tree[N - 1];
    long long answerSaw = 0;
    while (left <= right)//이분 탐색 사용
    {
        long long mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++)
        {
            if (tree[i] > mid)//현재 비교할 수 (톱 길이) 보다 클때만 나무를 잘라갈 수 있으므로 .
            {
                sum += (tree[i] - mid);
            }
        }
        if (sum >= M)
        {
            answerSaw = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << answerSaw;
}