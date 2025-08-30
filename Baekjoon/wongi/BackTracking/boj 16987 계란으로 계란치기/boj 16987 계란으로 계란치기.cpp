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
vector<pair<int, int>> egg;
vector<bool> visited;
int maxCnt=0;
int curBroken = 0;
void dfs(int cur)
{
    if (cur == N) 
    {
        maxCnt = max(maxCnt, curBroken);
        return;
    }
    if (egg[cur].first <= 0 || curBroken == N - 1) 
        //현재 계란이 깨졌거나 or 남은 계란이 1개뿐이면 return 가지치기
    {
        dfs(cur + 1);
        return;
    }
    for (int t = 0; t < N; t++) 
    {
        if (t == cur) continue;//자기 자신은 못 침
        if (egg[t].first <= 0) continue;// 이미 깨진 계란은 못 침

        // 때릴 때는 "둘 다 동시에" 내구도가 상대의 무게만큼 깎임
        egg[cur].first -= egg[t].second;
        egg[t].first -= egg[cur].second;

        // 이번 타격으로 새로 깨졌다면 카운트 증가
        if (egg[cur].first <= 0) 
            curBroken++;
        if (egg[t].first <= 0) 
            curBroken++;

        dfs(cur + 1); // 다음 계란 차례로 진행

        // 깨진 개수 복원
        if (egg[cur].first <= 0)
            curBroken--;
        if (egg[t].first <= 0) 
            curBroken--;
        egg[t].first += egg[cur].second;
        egg[cur].first += egg[t].second;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N);
    for (int i = 0; i < N; i++)
    {
        int S, W;
        cin >> S >> W;
        egg.push_back({S,W});
    }
    dfs(0);
    cout << maxCnt;
}