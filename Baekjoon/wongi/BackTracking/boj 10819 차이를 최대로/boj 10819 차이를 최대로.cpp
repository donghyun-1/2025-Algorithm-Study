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
int N;
vector<int> arr;
vector<int> arr2;//현재까지 만든 순열을 담을 곳
vector<bool> visited;
int answerSum=-1;
void dfs(int cur)
{
    if (cur == N)
    {
        // 완성된 순열 arr2로 합 계산
        int result = 0;
        for (int i = 0; i < N - 1; i++) 
        {
            result += abs(arr2[i] - arr2[i + 1]);
        }
        answerSum = max(answerSum, result);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        arr2[cur] = arr[i];
        dfs(cur + 1);
        visited[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    arr.resize(N);
    visited.resize(N);
    arr2.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    dfs(0);
    cout << answerSum << '\n';
}