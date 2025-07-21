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
유니온 연산과 파인드 연산을 사용하여 푸는 문제.
*/
vector<int> ufArr;
int find(int a)
{
    /*
    1. 대상 노드의 배열에 index와 value값이 동일한지 확인
    만약에 동일하면 그대로 반환
    2. 동일하지 않으면 value값이 가리키는 index로 이동
    3. 이동위치의 index값과 value값이 같을 때까지 재귀
    중요! ==> 재귀를 빠져나올때 마다 거치는 모든 노드 값을 대표 노드 값으로 변경해 줘야함
    --> 이연산으로 인해 경로 압축이 되어 시간 복잡도가 줄어듦
    */
    if (a == ufArr[a])//1.
    {
        return a;
    }
    else
    {
        return ufArr[a] = find(ufArr[a]);// 거치는 모든 노드 값을 대표 노드 값으로 변경
    }
}
void unions(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        ufArr[b] = a;
    }
}
bool same(int a, int b) // 두 원소가 같은지?
{
    a = find(a);
    b = find(b);
    if (a == b)
    {
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    ufArr.resize(n + 1);

    for (int i = 0; i <= n; i++)
    {
        ufArr[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int mode, a, b;
        cin >> mode >> a >> b;
        if (mode == 0)
        {
            unions(a, b);
        }
        else
        {
            if (same(a, b))//같은 집합 원소인지 확인하기
            {
                cout << "YES"<<'\n';
            }
            else
            {
                cout << "NO"<< '\n';
            }
        }
    }
    
}