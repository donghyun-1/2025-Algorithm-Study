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
/*
가장 처음에 양분은 모든 칸에 5만큼 들어있다.

m개의 나무 심음.

- 봄 
나이만큼 양분먹을 수 있다면
    한칸에 여러개의 나무가 있으면 나이가 어린 나무부터
    양분 먹고 나이 1 증가
    땅에 있던 양분은 나이만큼 줄어듬
양분 못먹는 나무는 사망
- 여름
죽은나무 나이를 2로 나눈값이 그 칸에 양분으로 환산
- 가을
나이가 5배수인 나무들은 주변 8칸에 나이가 1인 나무를 생성
땅범위 벗어나면 x
- 겨울
매 칸마다 입력으로 주어진 양분 A[r][c] 만큼 양분이 추가된다.
---------------
input
n m k
n개의 a배열 값 주어짐
r번째줄의 c번째 값 -> A[R][C]
M개의 줄에는 나무 정보 담은 X Y 그리고 Z는 나무의 나이.
----------------
output
k년 후 살아남은 나무의 수 출력
*/
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int n,m, k;
int yArr[11][11];
int addY[15][15];
vector<int>tree[15][15];
int answer = 0;
void spring()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(tree[i][j].size()==0) continue;//나무 없으면 동작 x

            vector<int> curTreeArr;//계산하면서 나이 먹은거 배열에 적용하기 위한 temp 배열
            int curTreeDieAge = 0;
            sort(tree[i][j].begin(), tree[i][j].end());
            for (int k = 0; k < tree[i][j].size(); k++)
            {
                int curAge = tree[i][j][k];
                if (yArr[i][j] >= curAge)//양분 먹을 수 있으면.
                {
                    yArr[i][j] = yArr[i][j] - curAge;
                    curTreeArr.push_back(curAge + 1);//나이먹기

                }
                else//없으면 
                {
                    int die=curAge/2;//죽은 나무 나이
                    
                    curTreeDieAge =curTreeDieAge+ die;
                }
            }
            tree[i][j].clear();//현재칸 트리 정보 초기화
            for (int s = 0; s < curTreeArr.size(); s++)
            {
                tree[i][j].push_back(curTreeArr[s]);//새로 트리 정보를 추가 
            }
            yArr[i][j] = yArr[i][j] + curTreeDieAge;//그 나이로 양분으로 ㄱㄱ
        }
    }
}
void summer()
{

}
void fall()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (tree[i][j].size() == 0) continue;
            for (int k = 0; k < tree[i][j].size(); k++)
            {
                if (tree[i][j][k] % 5==0)
                {
                    for (int dir = 0; dir < 8; dir++)
                    {
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];
                        if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
                        tree[ny][nx].push_back(1);
                    }
                }
            }

        }
    }
}
void winter()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            yArr[i][j] = yArr[i][j] + addY[i][j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> addY[i][j];
            yArr[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x][y].push_back(age);
    }
    for (int i = 0; i < k; i++)
    {
        spring();
        fall();
        winter();
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            answer += tree[i][j].size();
        }
    }
    cout << answer;
}